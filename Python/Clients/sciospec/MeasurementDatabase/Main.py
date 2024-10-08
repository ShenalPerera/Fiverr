import uuid
import sys

import numpy as np

from Sequence import Sequence
from SequenceFrame import SequenceFrame

# Raw Sequence Frame
uuid_list = [str(uuid.uuid4()) for index in range(5)]
attribute_key_list = [["2022-03-04 12:22:58", "Method 1"], ["2022-03-03 21:16:37", "Method 2"],
                      ["2022-03-04 12:30:58", "Method 1"], ["2022-03-04 09:51:45", "Method 2"],
                      ["2022-03-03 23:01:33", "Method 2"]]
sample_id_list = ["0000-0000-0000-0000", "0000-0000-0000-0001", "0000-0000-0000-0002", "0000-0000-0000-0003",
                  "0000-0000-0000-0004"]
batch_list = ["0000-0000-0000-0000", "0000-0000-0000-0001", "0000-0000-0000-0002", "0000-0000-0000-0003",
              "0000-0000-0000-0004"]
sample_count = 10
delta_t = 0.1

raw_sequence_list = []
for measurement_index in range(5):
    attribute_key = attribute_key_list[measurement_index]
    sample_id = sample_id_list[measurement_index]
    batch = batch_list[measurement_index]
    uuid = uuid_list[measurement_index]

    raw_sequence_voltage = Sequence(name="Voltage", group=attribute_key, abscissa_type="Seconds",
                                    ordinate_type="Voltage")
    raw_sequence_voltage.add_metadata("sample_id", sample_id)
    raw_sequence_voltage.add_metadata("sample_count", sample_count)
    raw_sequence_voltage.add_metadata("batch", batch)
    raw_sequence_voltage.add_metadata("UUID", uuid)

    raw_sequence_current = Sequence(name="Current", group=attribute_key, abscissa_type="Seconds",
                                    ordinate_type="Current")
    raw_sequence_current.add_metadata("sample_id", sample_id)
    raw_sequence_current.add_metadata("sample_count", sample_count)
    raw_sequence_current.add_metadata("batch", batch)
    raw_sequence_current.add_metadata("UUID", uuid)

    for data_index in range(0, 1000):
        raw_sequence_voltage.add_value_pair(data_index * delta_t, np.abs(np.random.randn()))
        raw_sequence_current.add_value_pair(data_index * delta_t, np.abs(np.random.randn()))

    raw_sequence_list.append(raw_sequence_voltage)
    raw_sequence_list.append(raw_sequence_current)

raw_sequence_frame = SequenceFrame(name="SequenceFrame", abscissa_type="Seconds")
raw_sequence_frame.add_sequences(raw_sequence_list)

print("Raw Sequence Frame:", raw_sequence_frame)

# Processed Sequence Frame
comment = "This is a comment"

processed_sequence_list = []
for measurement_index in range(5):
    attribute_key = attribute_key_list[measurement_index]
    sample_id = sample_id_list[measurement_index]
    batch = batch_list[measurement_index]
    uuid = uuid_list[measurement_index]

    processed_sequence_water_content = Sequence(name="Water Content", group=attribute_key, abscissa_type="Number")
    processed_sequence_water_content.add_metadata("sample_id", sample_id)
    processed_sequence_water_content.add_metadata("sample_count", sample_count)
    processed_sequence_water_content.add_metadata("batch", batch)
    processed_sequence_water_content.add_metadata("comment", comment)
    processed_sequence_water_content.add_metadata("UUID", uuid)
    processed_sequence_water_content.add_metadata("version", 1)

    processed_sequence_uncertainty = Sequence(name="Uncertainty", group=attribute_key, abscissa_type="Number")
    processed_sequence_uncertainty.add_metadata("sample_id", sample_id)
    processed_sequence_uncertainty.add_metadata("sample_count", sample_count)
    processed_sequence_uncertainty.add_metadata("batch", batch)
    processed_sequence_uncertainty.add_metadata("comment", comment)
    processed_sequence_uncertainty.add_metadata("UUID", uuid)
    processed_sequence_uncertainty.add_metadata("version", 1)

    processed_sequence_use_average_content = Sequence(name="Use Average", group=attribute_key, abscissa_type="Number")
    processed_sequence_use_average_content.add_metadata("sample_id", sample_id)
    processed_sequence_use_average_content.add_metadata("sample_count", sample_count)
    processed_sequence_use_average_content.add_metadata("batch", batch)
    processed_sequence_use_average_content.add_metadata("comment", comment)
    processed_sequence_use_average_content.add_metadata("UUID", uuid)
    processed_sequence_use_average_content.add_metadata("version", 1)

    for data_index in range(1, 11):
        processed_sequence_water_content.add_value_pair(data_index, np.abs(np.random.randn()))
        processed_sequence_uncertainty.add_value_pair(data_index, np.abs(np.random.randn()))
        processed_sequence_use_average_content.add_value_pair(data_index, False)

    processed_sequence_list.append(processed_sequence_water_content)
    processed_sequence_list.append(processed_sequence_uncertainty)
    processed_sequence_list.append(processed_sequence_use_average_content)

processed_sequence_frame = SequenceFrame(name="SequenceFrame", abscissa_type="Number")
processed_sequence_frame.add_sequences(processed_sequence_list)

print("Processed Sequence Frame:", processed_sequence_frame)
