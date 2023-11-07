import copy
import os
import time

import pandas as pd

from Check import assertion_type_is_subclass, assertion_strings_match, \
    assertion_element_in_list
from Constants import DataTypeSeparatorString, GenericDataTypeNameString, EmptyNameString
from Sequence import Sequence
from Util import get_dict_keys_from_values, get_sub_dict, get_unique_elements


class SequenceFrame:

    def __init__(self, name=EmptyNameString, abscissa_type=GenericDataTypeNameString):
        self.name = name
        self.abscissa_type = abscissa_type
        self.sequence_index = 1
        self.data_frame = pd.DataFrame()
        self.sequence_index_name_dict = {}
        self.sequence_index_group_dict = {}
        self.sequence_index_timestamp_dict = {}
        self.sequence_index_ordinate_type_dict = {}
        self.sequence_index_meta_data_dict = {}

    def __repr__(self):
        return self.data_frame.__repr__()

    def __str__(self):
        return self.data_frame.__str__()

    # Setter and Getter
    def add_sequences(self, sequence_list):
        for sequence in sequence_list:
            if assertion_type_is_subclass(sequence, Sequence):
                if assertion_strings_match(sequence.get_abscissa_type(), self.abscissa_type):
                    sequence_series = sequence.get_series()
                    new_data_frame = sequence_series.to_frame(name=self.sequence_index)
                    self.data_frame = pd.concat([self.data_frame, new_data_frame], axis=1)
                    self.sequence_index_name_dict[self.sequence_index] = sequence.get_name()
                    self.sequence_index_group_dict[self.sequence_index] = sequence.get_group()
                    self.sequence_index_timestamp_dict[self.sequence_index] = sequence.get_timestamp()
                    self.sequence_index_ordinate_type_dict[self.sequence_index] = sequence.get_ordinate_type()
                    self.sequence_index_meta_data_dict[self.sequence_index] = sequence.get_metadata_dict()
                    self.sequence_index += 1
        self.data_frame.index.name = self.abscissa_type

    def set_name(self, name):
        self.name = name

    def get_name(self):
        return self.name

    def set_value(self, value, row, names=None, groups=None, timestamps=None, ordinate_types=None):
        key_list = self._filter(names, groups, timestamps, ordinate_types)
        for key in key_list:
            self.data_frame.at[row, key] = value

    def get_value(self, row, names=None, groups=None, timestamps=None, ordinate_types=None):
        key_list = self._filter(names, groups, timestamps, ordinate_types)
        data_frame = self.data_frame[key_list]
        value = data_frame.loc[row][key_list].values
        return value

    def get_data_frame(self, column_names="names"):
        assertion_element_in_list(column_names, ["names", "timestamps", "group", "ordinate_type", "indices"])
        new_data_frame = copy.deepcopy(self.data_frame)
        if column_names == "names":
            new_data_frame.columns = self.get_column_names()
        elif column_names == "timestamps":
            new_data_frame.columns = self.get_column_timestamps()
        elif column_names == "group":
            new_data_frame.columns = self.get_column_groups()
        elif column_names == "ordinate_type":
            new_data_frame.columns = self.get_column_ordinate_types()
        return new_data_frame

    def get_column_names(self):
        return [self.sequence_index_name_dict[sequence_index] for sequence_index in self.data_frame.columns]

    def get_unique_column_names(self):
        unique_list_values = get_unique_elements(self.sequence_index_name_dict.values())
        unique_list_values.sort()
        return unique_list_values

    def get_column_groups(self):
        return [self.sequence_index_group_dict[sequence_index] for sequence_index in self.data_frame.columns]

    def get_unique_column_groups(self):
        unique_list_values = get_unique_elements(self.sequence_index_group_dict.values())
        unique_list_values.sort()
        return unique_list_values

    def get_column_timestamps(self):
        return [self.sequence_index_timestamp_dict[sequence_index] for sequence_index in self.data_frame.columns]

    def get_column_ordinate_types(self):
        return [self.sequence_index_ordinate_type_dict[sequence_index] for sequence_index in self.data_frame.columns]

    def get_metadata(self, key):
        metadata_list = []
        for metadata_dict in self.sequence_index_meta_data_dict.values():
            metadata = metadata_dict.get(key)
            metadata_list.append(metadata)
        return metadata_list

    def get_rows(self, names=None, groups=None, timestamps=None, ordinate_types=None, index=False):
        key_list = self._filter(names, groups, timestamps, ordinate_types)
        new_data_frame = self.data_frame[key_list]
        new_data_frame_row_iterator = new_data_frame.itertuples(index=index)
        row_list = [list(row) for row in new_data_frame_row_iterator]
        return row_list

    def filter(self, names=None, groups=None, timestamps=None, ordinate_types=None, row_indices=None):
        key_list = self._filter(names, groups, timestamps, ordinate_types)
        new_data_frame = self.data_frame[key_list]
        if row_indices is not None:
            new_data_frame = new_data_frame.iloc[row_indices]
        new_sequence_index_name_dict = get_sub_dict(self.sequence_index_name_dict, key_list)
        new_sequence_index_group_dict = get_sub_dict(self.sequence_index_group_dict, key_list)
        new_sequence_index_timestamp_dict = get_sub_dict(self.sequence_index_timestamp_dict, key_list)
        new_sequence_index_ordinate_type_dict = get_sub_dict(self.sequence_index_ordinate_type_dict, key_list)
        new_sequence_index_meta_data_dict = get_sub_dict(self.sequence_index_meta_data_dict, key_list)
        new_sequence_frame = copy.deepcopy(self)
        new_sequence_frame.data_frame = new_data_frame
        new_sequence_frame.sequence_index_name_dict = new_sequence_index_name_dict
        new_sequence_frame.sequence_index_group_dict = new_sequence_index_group_dict
        new_sequence_frame.sequence_index_timestamp_dict = new_sequence_index_timestamp_dict
        new_sequence_frame.sequence_index_ordinate_type_dict = new_sequence_index_ordinate_type_dict
        new_sequence_frame.sequence_index_meta_data_dict = new_sequence_index_meta_data_dict
        return new_sequence_frame

    def apply(self, function, names=None, groups=None, timestamps=None, ordinate_types=None):
        new_sequence_frame = self.filter(names=names, groups=groups, timestamps=timestamps,
                                         ordinate_types=ordinate_types)
        processed_data = function(new_sequence_frame)
        return processed_data

    def to_csv(self, path):
        save_data_frame = self.get_data_frame(column_names="names")
        timestamp = time.time()
        timestamp_string = str(timestamp)
        filename = self.name + DataTypeSeparatorString + timestamp_string + ".csv"
        save_path = os.path.join(path, filename)
        save_data_frame.to_csv(path_or_buf=save_path, sep=";", na_rep='NaN', compression=None)

    # Helper
    def _filter(self, names=None, groups=None, timestamps=None, ordinate_types=None):
        key_set = set(self.sequence_index_name_dict.keys())
        if names is not None:
            names_sequence_index_list = get_dict_keys_from_values(self.sequence_index_name_dict, names)
            names_sequence_index_set = set(names_sequence_index_list)
            key_set = key_set.intersection(names_sequence_index_set)
        if groups is not None:
            groups_sequence_index_list = get_dict_keys_from_values(self.sequence_index_group_dict, groups)
            groups_sequence_index_set = set(groups_sequence_index_list)
            key_set = key_set.intersection(groups_sequence_index_set)
        if timestamps is not None:
            timestamps_sequence_index_list = get_dict_keys_from_values(self.sequence_index_timestamp_dict,
                                                                       timestamps)
            timestamps_sequence_index_set = set(timestamps_sequence_index_list)
            key_set = key_set.intersection(timestamps_sequence_index_set)
        if ordinate_types is not None:
            ordinate_types_sequence_index_list = get_dict_keys_from_values(self.sequence_index_ordinate_type_dict,
                                                                           ordinate_types)
            ordinate_types_sequence_index_set = set(ordinate_types_sequence_index_list)
            key_set = key_set.intersection(ordinate_types_sequence_index_set)
        key_list = list(key_set)
        key_list.sort()
        return key_list
