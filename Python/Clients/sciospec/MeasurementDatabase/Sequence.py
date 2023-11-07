import copy
import time

import numpy as np
import pandas as pd

from Constants import GenericDataTypeNameString, EmptyNameString


class Sequence:

    def __init__(self, name=EmptyNameString, group=EmptyNameString, abscissa_type=GenericDataTypeNameString,
                 ordinate_type=GenericDataTypeNameString):
        self.name = name
        self.group = group
        self.abscissa_type = abscissa_type
        self.ordinate_type = ordinate_type
        self.timestamp = time.time()
        self.metadata = {}
        self.series = pd.Series()

    def __repr__(self):
        return self.series.__repr__()

    def __str__(self):
        return self.series.__str__()

    # Setter and Getter
    def add_value_pair(self, abscissa_value, ordinate_value):
        self.series = self.series.append(pd.Series(data=[ordinate_value], index=[abscissa_value]))

    def add_ordinate_value(self, ordinate_value, index_zero=None):
        abscissa_value = self.series.size
        if index_zero is not None:
            abscissa_value += 1
        self.series = self.series.append(pd.Series(data=[ordinate_value], index=[abscissa_value]))

    def fill_ordinate_value(self, value, size, index_zero=None):
        for index in range(size):
            self.add_ordinate_value(value, index_zero=index_zero)

    def set_series(self, series):
        self.series = series

    def get_series(self):
        return self.series

    def get_data_frame(self):
        data_frame = pd.DataFrame(self.series)
        return data_frame

    def get_row_list(self):
        return [list(x) for x in self.get_data_frame().to_records()]

    def get_mean(self):
        new_sequence = copy.deepcopy(self)
        new_series = self.series.groupby(self.series.index).apply(np.mean)
        new_sequence.set_series(new_series)
        return new_sequence

    def set_name(self, name):
        self.name = name

    def get_name(self):
        return self.name

    def set_group(self, group):
        self.group = group

    def get_group(self):
        return self.group

    def get_timestamp(self):
        return self.timestamp

    def get_abscissa_type(self):
        return self.abscissa_type

    def get_ordinate_type(self):
        return self.ordinate_type

    def add_metadata(self, key, metadata):
        self.metadata[key] = metadata

    def get_metadata(self, key):
        metadata = self.metadata.get(key)
        return metadata

    def get_metadata_dict(self):
        return self.metadata

    def get_size(self):
        size = self.series.size
        return size
