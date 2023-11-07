def get_dict_keys_from_values(dictionary, reference_values):
    key_list = []
    for key, value in dictionary.items():
        if value in reference_values:
            key_list.append(key)
    return key_list


def get_sub_dict(dictionary, key_list):
    try:
        new_dictionary = {key: dictionary[key] for key in key_list if key in dictionary}
    except TypeError:
        return {}
    return new_dictionary


def get_unique_elements(element_list):
    def list_to_tuple(element):
        if type(element) == list:
            return tuple(element)
        return element

    def tuple_to_list(element):
        if type(element) == tuple:
            return list(element)
        return element

    hashable_element_list = [list_to_tuple(element) for element in element_list]
    unique_element_list = list(set(hashable_element_list))
    unique_list_values = [tuple_to_list(element) for element in unique_element_list]
    return unique_list_values
