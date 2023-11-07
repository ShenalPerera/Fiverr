from SQLiteDatabase import SQLiteDatabase
from Constants import GenericDataTypeNameString
from Check import assertion_type_is_subclass
from SequenceFrame import SequenceFrame
from Sequence import Sequence


class MeasurementDatabase:

    def __init__(self, db_path):
        self.dbInstance = SQLiteDatabase(db_path)
        self.dbInstance.set_foreign_key_pragma(True)
        # create the relevant tables if not exits

        # Create the table that contains a sequence
        self.dbInstance.create_table("SEQUENCE_FRAME",
                                     "frame_id INTEGER PRIMARY KEY AUTOINCREMENT ",
                                     "name VARCHAR(20) NOT NULL",
                                     f"abscissa_type VARCHAR(20) DEFAULT {GenericDataTypeNameString}",
                                     )

        # create the table sequence that contains a sequence
        self.dbInstance.create_table("SEQUENCE",
                                     "seq_id CHAR(36) PRIMARY KEY NOT NULL",
                                     "name VARCHAR(20) NOT NULL",
                                     "group_ VARCHAR(40) NOT NULL",
                                     f"abscissa_type VARCHAR(20) DEFAULT {GenericDataTypeNameString}",
                                     f"ordinate_type VARCHAR(20) DEFAULT {GenericDataTypeNameString}",
                                     "sample_id CHAR(19) NOT NULL",
                                     "sample_count INTEGER NOT NULL",
                                     "batch CHAR(19) NOT NULL",
                                     "comment TEXT",
                                     "frame_id INT NOT NULL",
                                     "FOREIGN KEY (frame_id) REFERENCES SEQUENCE_FRAME(frame_id) ON UPDATE "
                                     "CASCADE ON DELETE CASCADE"
                                     )

        # create the table for metadata of each sequence
        self.dbInstance.create_table("PROCESSED_SEQUENCE",
                                     "data_id INTEGER PRIMARY KEY AUTOINCREMENT",
                                     "seq_id CHAR(36) NOT NULL",
                                     "name VARCHAR(20) NOT NULL",
                                     "group_ VARCHAR(40) NOT NULL",
                                     f"abscissa_type VARCHAR(20) DEFAULT {GenericDataTypeNameString}",
                                     f"ordinate_type VARCHAR(20) DEFAULT {GenericDataTypeNameString}",
                                     "sample_id CHAR(19) NOT NULL",
                                     "sample_count INTEGER NOT NULL",
                                     "batch CHAR(19) NOT NULL",
                                     "comment TEXT",
                                     "frame_id INT NOT NULL",
                                     "version INT NOT NULL",
                                     "FOREIGN KEY (seq_id) REFERENCES SEQUENCE(seq_id) ON UPDATE "
                                     "CASCADE ON DELETE CASCADE",
                                     "FOREIGN KEY (frame_id) REFERENCES SEQUENCE_FRAME(frame_id) ON UPDATE "
                                     "CASCADE ON DELETE CASCADE",

                                     )

        self.dbInstance.create_table("RAW_DATA",
                                     "seq_id CHAR(36) NOT NULL",
                                     "abscissa_value DOUBLE PRECISION",
                                     "ordinate_value DOUBLE PRECISION",
                                     "FOREIGN KEY (seq_id) REFERENCES SEQUENCE(seq_id) ON UPDATE "
                                     "CASCADE ON DELETE CASCADE"
                                     )

        self.dbInstance.create_table("PROCESSED_DATA",
                                     "abscissa_value DOUBLE PRECISION",
                                     "ordinate_value DOUBLE PRECISION",
                                     "data_id INTEGER NOT NULL",
                                     "FOREIGN KEY (data_id) REFERENCES PROCESSED_SEQUENCE(data_id) ON UPDATE "
                                     "CASCADE ON DELETE CASCADE"
                                     )

    def insert_raw_sequence_frame(self, frame=SequenceFrame()):
        if assertion_type_is_subclass(frame, SequenceFrame):
            name = frame.name
            abscissa = frame.abscissa_type
            frame_id = self.dbInstance.insert_in_columns("SEQUENCE_FRAME", [name, abscissa], "name", "abscissa_type")

            sample_id = frame.get_metadata('sample_id')
            sample_count = frame.get_metadata('sample_count')
            batch = frame.get_metadata('batch')
            comment = frame.get_metadata('comment')
            seq_id = frame.get_metadata('UUID')

            for sequence_index in range(1, frame.sequence_index):
                seq_name = frame.sequence_index_name_dict[sequence_index]
                seq_group_ = ",".join(frame.sequence_index_group_dict[sequence_index])

                ordinate_type = frame.sequence_index_ordinate_type_dict[sequence_index]
                abscissa_type = frame.abscissa_type

                self.dbInstance.insert("SEQUENCE", [seq_id[sequence_index - 1],
                                                    seq_name,
                                                    seq_group_,
                                                    abscissa_type,
                                                    ordinate_type,
                                                    sample_id[sequence_index - 1],
                                                    sample_count[sequence_index - 1],
                                                    batch[sequence_index - 1],
                                                    comment[sequence_index - 1],
                                                    frame_id
                                                    ])

                sequence_abscissa = list(frame.data_frame.index)
                sequence_ordinate = list(frame.data_frame.iloc[:, sequence_index - 1])

                for index in range(len(sequence_abscissa)):
                    self.dbInstance.insert("RAW_DATA",
                                           [
                                               seq_id[sequence_index - 1],
                                               sequence_abscissa[index],
                                               sequence_ordinate[index]

                                           ]
                                           )

    def insert_processed_sequence_frame(self, frame=SequenceFrame()):
        if assertion_type_is_subclass(frame, SequenceFrame):
            name = frame.name
            abscissa = frame.abscissa_type
            frame_id = self.dbInstance.insert_in_columns("SEQUENCE_FRAME", [name, abscissa], "name", "abscissa_type")

            sample_id = frame.get_metadata('sample_id')
            sample_count = frame.get_metadata('sample_count')
            batch = frame.get_metadata('batch')
            comment = frame.get_metadata('comment')
            seq_id = frame.get_metadata('UUID')
            version = frame.get_metadata('version')

            for sequence_index in range(1, frame.sequence_index):
                seq_name = frame.sequence_index_name_dict[sequence_index]
                seq_group_ = ",".join(frame.sequence_index_group_dict[sequence_index])

                ordinate_type = frame.sequence_index_ordinate_type_dict[sequence_index]
                abscissa_type = frame.abscissa_type

                last_key = self.dbInstance.insert_in_columns("PROCESSED_SEQUENCE", [
                    seq_id[sequence_index - 1],
                    seq_name,
                    seq_group_,
                    abscissa_type,
                    ordinate_type,
                    sample_id[sequence_index - 1],
                    sample_count[sequence_index - 1],
                    batch[sequence_index - 1],
                    comment[sequence_index - 1],
                    frame_id,
                    version[sequence_index - 1]
                ],
                                                             "seq_id",
                                                             "name",
                                                             "group_",
                                                             "abscissa_type",
                                                             "ordinate_type",
                                                             "sample_id",
                                                             "sample_count",
                                                             "batch",
                                                             "comment",
                                                             "frame_id",
                                                             "version"
                                                             )

                sequence_abscissa = list(frame.data_frame.index)
                sequence_ordinate = list(frame.data_frame.iloc[:, sequence_index - 1])

                for index in range(len(sequence_abscissa)):
                    self.dbInstance.insert("PROCESSED_DATA",
                                           [
                                               sequence_abscissa[index],
                                               sequence_ordinate[index],
                                               last_key

                                           ]
                                           )

    def fetch_frames_by_name(self, name):

        result = self.dbInstance.get_rows_referential_integrity(["SEQUENCE_FRAME", "SEQUENCE", "RAW_DATA"], None
                                                                ,
                                                                [
                                                                    ["SEQUENCE_FRAME.frame_id", "=",
                                                                     "SEQUENCE.frame_id"],
                                                                    ["SEQUENCE.seq_id", "=", "RAW_DATA.seq_id"],

                                                                    ["SEQUENCE_FRAME.name", "=", "\"" + name + "\""]
                                                                ])

        frames = {}
        sequences = {}

        for row in result:
            frames[row[0]] = {"frame": SequenceFrame(row[1], row[2]), "id": row[0]}
            sequences[row[3]] = {"seq": Sequence(row[4], row[5], row[6], row[7]), "id": row[0]}
            sequences[row[3]]["seq"].add_metadata("sample_id", row[8])
            sequences[row[3]]["seq"].add_metadata("sample_count", row[9])
            sequences[row[3]]["seq"].add_metadata("batch", row[10])
            sequences[row[3]]["seq"].add_metadata("UUID", row[3])

        for row in result:
            sequences[row[3]]["seq"].add_value_pair(row[14], row[15])

        for key1 in frames.keys():
            seq_list = []
            for key2 in sequences.keys():
                if frames[key1]["id"] == sequences[key2]["id"]:
                    seq_list.append(sequences[key2]["seq"])
            frames[key1]["frame"].add_sequences(seq_list)

        return frames

    def fetch_raw_data_frames(self):
        result = self.dbInstance.get_rows_referential_integrity(["SEQUENCE_FRAME", "SEQUENCE", "RAW_DATA"], None
                                                                ,
                                                                [
                                                                    ["SEQUENCE_FRAME.frame_id", "=",
                                                                     "SEQUENCE.frame_id"],
                                                                    ["SEQUENCE.seq_id", "=", "RAW_DATA.seq_id"],

                                                                ])

        frames = {}
        sequences = {}

        for row in result:
            frames[row[0]] = {"frame": SequenceFrame(row[1], row[2]), "id": row[0]}
            sequences[row[3]] = {"seq": Sequence(row[4], row[5], row[6], row[7]), "id": row[0]}
            sequences[row[3]]["seq"].add_metadata("sample_id", row[8])
            sequences[row[3]]["seq"].add_metadata("sample_count", row[9])
            sequences[row[3]]["seq"].add_metadata("batch", row[10])
            sequences[row[3]]["seq"].add_metadata("UUID", row[3])

        for row in result:
            sequences[row[3]]["seq"].add_value_pair(row[14], row[15])

        for key1 in frames.keys():
            seq_list = []
            for key2 in sequences.keys():
                if frames[key1]["id"] == sequences[key2]["id"]:
                    seq_list.append(sequences[key2]["seq"])
            frames[key1]["frame"].add_sequences(seq_list)
        return frames

    def fetch_processed_data(self, _uuid):
        result = self.dbInstance.get_rows_referential_integrity(["SEQUENCE", "PROCESSED_SEQUENCE", "SEQUENCE_FRAME"],
                                                                [
                                                                    "PROCESSED_SEQUENCE.name",
                                                                    "PROCESSED_SEQUENCE.group_",
                                                                    "PROCESSED_SEQUENCE.abscissa_type",
                                                                    "PROCESSED_SEQUENCE.ordinate_type",
                                                                    "PROCESSED_SEQUENCE.sample_id",
                                                                    "PROCESSED_SEQUENCE.sample_count",
                                                                    "PROCESSED_SEQUENCE.batch",
                                                                    "PROCESSED_SEQUENCE.comment",
                                                                    "PROCESSED_SEQUENCE.frame_id",
                                                                    "PROCESSED_SEQUENCE.seq_id",
                                                                    "PROCESSED_SEQUENCE.data_id",
                                                                    "PROCESSED_SEQUENCE.version",
                                                                    "SEQUENCE_FRAME.name",
                                                                    "SEQUENCE_FRAME.abscissa_type",
                                                                    "SEQUENCE_FRAME.frame_id"

                                                                ]
                                                                ,
                                                                [

                                                                    ["SEQUENCE.seq_id", "=",
                                                                     "PROCESSED_SEQUENCE.seq_id"],
                                                                    ["PROCESSED_SEQUENCE.frame_id", "=",
                                                                     "SEQUENCE_FRAME.frame_id"],

                                                                    ["SEQUENCE.seq_id", "=", "\"" + _uuid + "\""]
                                                                ])


        frames = {}
        sequences = {}

        for row in result:
            frames[row[14]] = {"frame": SequenceFrame(row[12], row[13]), "id": row[14]}
            sequences[row[10]] = {"seq": Sequence(row[0], row[1], row[2], row[3]), "id": row[14]}
            sequences[row[10]]["seq"].add_metadata("sample_id", row[4])
            sequences[row[10]]["seq"].add_metadata("sample_count", row[5])
            sequences[row[10]]["seq"].add_metadata("batch", row[6])
            sequences[row[10]]["seq"].add_metadata("comment", row[7])
            sequences[row[10]]["seq"].add_metadata("UUID", row[9])
            sequences[row[10]]["seq"].add_metadata("version", row[11])

        for key in sequences.keys():
            result2 = self.dbInstance.get_rows_referential_integrity(["PROCESSED_DATA", "PROCESSED_SEQUENCE"],
                                                                     [
                                                                         "abscissa_value",
                                                                         "ordinate_value"
                                                                     ],
                                                                     [
                                                                         ["PROCESSED_DATA.data_id", "=",
                                                                          "PROCESSED_SEQUENCE.data_id"],
                                                                         ["PROCESSED_DATA.data_id", "=", str(key)]
                                                                     ]
                                                                     )


            for row in result2:
                sequences[key]["seq"].add_value_pair(row[0], row[1])


        for key1 in frames.keys():
            seq_list = []
            for key2 in sequences.keys():
                if frames[key1]["id"] == sequences[key2]["id"]:
                    seq_list.append(sequences[key2]["seq"])
            frames[key1]["frame"].add_sequences(seq_list)

        return frames


