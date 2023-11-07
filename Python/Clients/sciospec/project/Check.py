from Constants import AssertionErrorString, AssertionErrorTypesDoNotMatchString, \
    AssertionErrorDifferenceDoesNotMatchString, AssertionErrorTypeIsNotSubclassString, \
    AssertionErrorListLengthsDoNotMatchString, AssertionErrorStringsDoNotMatchString, \
    AssertionErrorNumbersDoNotMatchString, AssertionErrorElementIsNotInString, AssertionErrorIsNotNoneString, \
    AssertionErrorElementIsInString


def assertion_types_match(check_variable, reference_variable):
    if not type(check_variable) == type(reference_variable):
        if check_variable is not None:
            print(AssertionErrorString, str(type(check_variable)), AssertionErrorTypesDoNotMatchString,
                  str(type(reference_variable)))
        return False
    return True


def assertion_difference_matches(index_start, index_end, difference):
    if not index_end - index_start == difference:
        print(AssertionErrorString, AssertionErrorDifferenceDoesNotMatchString, str(difference))
        return False
    return True


def assertion_type_is_subclass(check_variable, super_class):
    if not issubclass(type(check_variable), super_class):
        if check_variable is not None:
            print(AssertionErrorString, str(type(check_variable)), AssertionErrorTypeIsNotSubclassString,
                  str(super_class))
        return False
    return True


def assertion_list_same_length(check_list, reference_list):
    if not len(check_list) == len(reference_list):
        print(AssertionErrorString, str(check_list), AssertionErrorListLengthsDoNotMatchString, str(reference_list))
        return False
    return True


def assertion_strings_match(check_string, reference_string):
    if not check_string == reference_string:
        print(AssertionErrorString, check_string, AssertionErrorStringsDoNotMatchString, reference_string)
        return False
    return True


def assertion_numbers_match(check_number, reference_number):
    if not check_number == reference_number:
        print(AssertionErrorString, check_number, AssertionErrorNumbersDoNotMatchString, reference_number)
        return False
    return True


def assertion_element_in_list(check_element, reference_list):
    if check_element not in reference_list:
        print(AssertionErrorString, check_element, AssertionErrorElementIsNotInString, reference_list)
        return False
    return True


def assertion_element_not_in_list(check_element, reference_list):
    if check_element in reference_list:
        print(AssertionErrorString, check_element, AssertionErrorElementIsInString, reference_list)
        return False
    return True


def assertion_is_not_none(check_variable):
    if check_variable is None:
        print(AssertionErrorString, check_variable, AssertionErrorIsNotNoneString)
        return False
    return True


def assertion_is_primary_key_valid(primary_key_list, *args):
    for primary_key in primary_key_list:
        if primary_key not in args:
            return False
    return True
