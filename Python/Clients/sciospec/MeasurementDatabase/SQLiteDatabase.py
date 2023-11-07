import sqlite3


class SQLiteDatabase:

    def __init__(self, database_path):
        self.connection = sqlite3.connect("file:{}?mode=rwc".format(database_path),
                                          detect_types=sqlite3.PARSE_DECLTYPES,
                                          uri=True)
        self.cursor = self.connection.cursor()

    def create_table(self, table_name, *args):
        # *args are the columns of the table.
        arguments = ", ".join(args)
        query = "CREATE TABLE IF NOT EXISTS {} ({});".format(table_name, arguments)
        self.cursor.execute(query)

    def close(self):
        self.connection.close()

    # Setter and Getter
    def insert(self, table_name, value_list, *args):
        # value_list is the list of values to be inserted into the table.
        # The values should match the columns of the table.
        # *args are the columns of the table, which is created if it does not exist.
        if not self.table_exists(table_name):
            self.create_table(table_name, *args)
        placeholders = ""
        for index in range(len(value_list)):
            placeholders += "?"
            if index < len(value_list) - 1:
                placeholders += ", "
        query = "INSERT INTO {} VALUES ({});".format(table_name, placeholders)
        self.cursor.execute(query, value_list)
        self.connection.commit()

    def insert_in_columns(self, table_name, value_list, *args):
        if not self.table_exists(table_name):
            self.create_table(table_name, *args)

        columns = "("
        for item in list(args):
            item = item.split()[0]
            columns += item + ', '
        columns = columns[:-2]
        columns += ')'
        placeholders = ""
        for index in range(len(value_list)):
            placeholders += "?"
            if index < len(value_list) - 1:
                placeholders += ", "
        query = "INSERT INTO {}{} VALUES ({});".format(table_name, columns, placeholders)
        self.cursor.execute(query, value_list)
        self.connection.commit()

    def update(self, table_name, new_value_dict, where=None, where_and=None, where_or=None):
        # The parameters where, where_and and where_or are mutually exclusive.
        # Each of those parameters is a list of lists in the following format: [["parameter", "operand", "value"]]
        # Parameters given as where_and are joined with AND.
        # Parameters given as where_or are joined with OR.
        where_clause = ""
        value_list = []
        argument_list = []
        for key, value in new_value_dict.items():
            argument_list.append("{}=?".format(key))
            value_list.append(value)
        if where is not None:
            where_clause += " WHERE {}{}?".format(where[0][0], where[0][1])
            value_list.append(where[0][2])
        elif where_and is not None:
            and_list = []
            for condition in where_and:
                if condition[2] is not None:
                    and_list.append("{}{}?".format(condition[0], condition[1]))
                    value_list.append(condition[2])
            where_clause += " WHERE "
            where_clause += " AND ".join(and_list)
        elif where_or is not None:
            or_list = []
            for condition in where_or:
                if condition[2] is not None:
                    or_list.append("{}{}?".format(condition[0], condition[1]))
                    value_list.append(condition[2])
            where_clause += " WHERE "
            where_clause += " OR ".join(or_list)
        query = "UPDATE {} SET {} {};".format(table_name, ", ".join(argument_list), where_clause)
        self.cursor.execute(query, value_list)
        self.connection.commit()

    def remove(self, table_name, where=None, where_and=None, where_or=None):
        # The parameters where, where_and and where_or are mutually exclusive. The 2 parameters not used should be None.
        # There are no defaults for the parameters in order to reduce the risk of handing over no parameters and
        # deleting all entries.
        # Each of those parameters is a list of lists in the following format: [["parameter", "operand", "value"]]
        # Parameters given as where_and are joined with AND.
        # Parameters given as where_or are joined with OR.
        where_clause = ""
        value_list = []
        if where is not None:
            where_clause += " WHERE {}{}?".format(where[0][0], where[0][1])
            value_list.append(where[0][2])
        elif where_and is not None:
            and_list = []
            for condition in where_and:
                if condition[2] is not None:
                    and_list.append("{}{}?".format(condition[0], condition[1]))
                    value_list.append(condition[2])
            where_clause += " WHERE "
            where_clause += " AND ".join(and_list)
        elif where_or is not None:
            or_list = []
            for condition in where_or:
                if condition[2] is not None:
                    or_list.append("{}{}?".format(condition[0], condition[1]))
                    value_list.append(condition[2])
            where_clause += " WHERE "
            where_clause += " OR ".join(or_list)
        query = "DELETE FROM {} {};".format(table_name, where_clause)
        self.cursor.execute(query, value_list)
        self.connection.commit()

    def remove_table(self, table_name):
        query = "DROP TABLE IF EXISTS {};".format(table_name)
        self.cursor.execute(query)
        self.connection.commit()

    def get_all_columns(self, table_name):
        if not self.table_exists(table_name):
            return None
        query = "SELECT * FROM {};".format(table_name)
        self.cursor.execute(query)
        column_list = self.cursor.fetchall()
        if len(column_list) == 0:
            return None
        return column_list

    # Get all rows of certain columns from a table.
    def get_columns(self, table_name, *args):
        if not self.table_exists(table_name):
            return None
        arguments = ", ".join(args)
        query = "SELECT {} FROM {};".format(arguments, table_name)
        self.cursor.execute(query)
        column_list = self.cursor.fetchall()
        if len(column_list) == 0:
            return None
        return column_list

    def get_rows_by_where(self, table_name, where=None, where_or=None, where_and=None):
        # The parameters where and (where_and and where_or) are mutually exclusive.
        # It is possible to have parameters joined by AND as well as OR.
        # Each of those parameters is a list of lists in the following format: [["parameter", "operand", "value"]]
        # Parameters given as where_and are joined with AND.
        # Parameters given as where_or are joined with OR.
        if not self.table_exists(table_name):
            return None
        arguments = ""
        value_list = []
        if where is not None:
            if where[0][2] is not None:
                arguments += " WHERE {}{}?".format(where[0][0], where[0][1])
                value_list.append(where[0][2])
        else:
            if where_and is not None:
                arguments += " WHERE "
                and_list = []
                for condition in where_and:
                    if condition[2] is not None:
                        and_list.append("{}{}?".format(condition[0], condition[1]))
                        value_list.append(condition[2])
                arguments += " AND ".join(and_list)
            if where_or is not None:
                if where_and is None:
                    arguments += " WHERE ("
                else:
                    arguments += " AND ("
                for condition_set in where_or:
                    or_list = []
                    for condition in condition_set:
                        if condition[2] is not None:
                            or_list.append("{}{}?".format(condition[0], condition[1]))
                            value_list.append(condition[2])
                    arguments += " OR ".join(or_list)
                    if condition_set != where_or[-1]:
                        arguments += ") AND ("
                arguments += ")"
        query = "SELECT * FROM {}{};".format(table_name, arguments)
        self.cursor.execute(query, value_list)
        row_list = self.cursor.fetchall()
        if len(row_list) == 0:
            return None
        return row_list

    def get_certain_rows_by_where(self, table_name, row_list=None, where=None, where_or=None, where_and=None):
        # The parameters where and (where_and and where_or) are mutually exclusive.
        # where_and is a list of lists in the following format: [["parameter", "operand", "value"]]
        # where_or is a list of lists of lists in the following format:
        # [[["parameter", "operand", "value"], ["parameter", "operand", "value"]], ["parameter", "operand", "value"]]
        # The reason for this is that certain OR-clauses are joined by AND
        # For example in the audit trail a search might be for a certain user and a category. In this case it would
        # make no sense to join them by OR; rather they should be joined by AND.
        if not self.table_exists(table_name):
            return None
        if row_list is None:
            rows = "*"
        else:
            rows = ", ".join(row_list)
        arguments = ""
        value_list = []
        if where is not None:
            if where[0][2] is not None:
                arguments += " WHERE {}{}?".format(where[0][0], where[0][1])
                value_list.append(where[0][2])
        else:
            if where_and is not None:
                arguments += " WHERE "
                and_list = []
                for condition in where_and:
                    if condition[2] is not None:
                        and_list.append("{}{}?".format(condition[0], condition[1]))
                        value_list.append(condition[2])
                arguments += " AND ".join(and_list)
            if where_or is not None:
                if where_and is None:
                    arguments += " WHERE ("
                else:
                    arguments += " AND ("
                for condition_set in where_or:
                    or_list = []
                    for condition in condition_set:
                        if condition[2] is not None:
                            or_list.append("{}{}?".format(condition[0], condition[1]))
                            value_list.append(condition[2])
                    arguments += " OR ".join(or_list)
                    if condition_set != where_or[-1]:
                        arguments += ") AND ("
                arguments += ")"
        query = "SELECT {} FROM {}{};".format(rows, table_name, arguments)
        self.cursor.execute(query, value_list)
        row_list = self.cursor.fetchall()
        if len(row_list) == 0:
            return None
        return row_list

    def get_rows_by_columns(self, table_name, column_list, row_index_list, separator_list):
        # This method takes 3 lists that should be of equal length.
        # column_list is the list of colums.
        # row_index_list is the list of corresponding values.
        # seperator_list is the list of corresponding operands.
        # Elements of the 3 lists are joined by index and added to a list, which is joined by OR.
        if not self.table_exists(table_name):
            return None
        arguments = ""
        value_list = []
        for index in range(len(row_index_list)):
            arguments += "{}{}?".format(column_list[index], separator_list[index])
            value_list.append(row_index_list[index])
            if index < len(row_index_list) - 1:
                arguments += " OR "
        query = "SELECT * FROM {} WHERE {};".format(table_name, arguments)
        self.cursor.execute(query, value_list)
        row_list = self.cursor.fetchall()
        if len(row_list) == 0:
            return None
        return row_list

    def get_distinct_rows(self, table_name, column):
        if not self.table_exists(table_name):
            return None
        query = "SELECT DISTINCT t.{} FROM {} AS t;".format(column, table_name)
        self.cursor.execute(query)
        row_list = self.cursor.fetchall()
        if len(row_list) == 0:
            return None
        return row_list

    def get_column_names(self, table_name):
        if not self.table_exists(table_name):
            return None
        query = "PRAGMA table_info({});".format(table_name)
        self.cursor.execute(query)
        raw_column_list = self.cursor.fetchall()
        column_list = []
        for column in raw_column_list:
            column_list.append(column[1])
        if len(column_list) == 0:
            return None
        return column_list

    # Packs the key into a format that fits into a where-clause
    def get_values_from_json(self, table_name, column_name, key):
        return "json_extract({}.{}, '$.{}')".format(table_name, column_name, key)

    # gets the corresponding value of the key from the column in the table
    # Example: to get all comments from a json string in the parameters column in the audit_trail table,
    #          pass "audit_trail", "parameters" and "Comment" to this function
    def get_rows_from_json(self, table_name, column_name, key):
        return "json_extract({}.{}, '$.{}')".format(table_name, column_name, key)

    #
    # Example: get all batch nos
    def get_all_values_from_json_entry(self, table_name, id_column_name, column_name, value_name):
        self.cursor.execute("SELECT {} FROM {} ORDER BY {};".format(id_column_name, table_name, id_column_name))
        ids = self.cursor.fetchall()
        result_list = []
        for row_id in ids:
            keys = self.get_json_dict_keys_by_column_value(table_name, column_name, id_column_name, row_id[0])
            for key in keys:
                query = "SELECT json_extract(json_extract({}.{}, '$.{}'), '$.{}') " \
                        "FROM {} WHERE {} = {};".format(table_name, column_name, key, value_name, table_name,
                                                        id_column_name, row_id[0])
                self.cursor.execute(query)
                result = self.cursor.fetchall()
                result_list.append(result[0][0])
        return result_list

    def get_all_json_dict_keys(self, table_name, column_name):
        query = "SELECT j.key FROM {}, json_each({}.{}) AS j;".format(table_name, table_name, column_name)
        self.cursor.execute(query)
        row_list = self.cursor.fetchall()
        if len(row_list) == 0:
            return None
        result_list = []
        for item in row_list:
            result_list.append(item[0])
        return result_list

    # Gets the keys from column_one where column_two is equal to value
    # Example: get the keys from sequence_index_name_dict where sequence_frame_ID is 1
    def get_json_dict_keys_by_column_value(self, table_name, column_one, column_two, value):
        query = "SELECT j.key FROM {}, json_each({}.{}) AS j WHERE {}={};".format(
            table_name, table_name, column_one, column_two, value)
        self.cursor.execute(query)
        row_list = self.cursor.fetchall()
        if len(row_list) == 0:
            return None
        result_list = []
        for item in row_list:
            result_list.append(item[0])
        return result_list

    # iterates over the keys and gets the required entries by searching for value
    # Example: search for value sample_id in column meta_data_dict of table sequence_frame
    def get_entries_from_json(self, table_name, column_name, key_list, value):
        result_list = []
        for key in key_list:
            query = "SELECT json_extract(json_extract({}.{}, '$.{}'), '$.{}') " \
                    "FROM {};".format(table_name, column_name, key, value, table_name)
            self.cursor.execute(query)
            row_list = self.cursor.fetchall()
            if len(row_list) != 0:
                result_list.append(row_list[0][0])
        print(result_list)

    def table_exists(self, table_name):
        query = "SELECT COUNT(*) FROM sqlite_master WHERE type='table' AND name=?;"
        self.cursor.execute(query, [table_name])
        table_exists = self.cursor.fetchall()
        return table_exists[0][0]
