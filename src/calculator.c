#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "base.h"

int main(int argc, char **argv) {

    /* Check that the number of arguments is correct */
    if (argc != 5) {
        fprintf(stderr, "ERROR: Wrong number of arguments\n");
        return EXIT_FAILURE;
    }

    char operator = *argv[1];

    /* Check that the operator being used is valid */
    if (operator != '+' && operator != '-' && operator != '*') {
        fprintf(stderr, "ERROR: Invalid operator specified\n");
        return EXIT_FAILURE;
    }

    char *first_input = argv[2];

    /* Check for a minus symbol in the beginning of the first input */
    bool negative = false;
    if (*first_input == '-') {
        negative = true;
        first_input += sizeof(char);
    }

    /* Get the base type for the first input */
    enum base_type first_base = parse_base(first_input);
    first_input += sizeof(char);

    if (first_base == UNKNOWN) {
        fprintf(stderr, "ERROR: Invalid base for first number\n");
        return EXIT_FAILURE;
    }

    /* Convert the first input to decimal */
    int first_value = convert_to_decimal(first_base, first_input);
    if (negative) first_value = -first_value;

    char *second_input = argv[3];

    /* Check for a minus symbol in the beginning of the second input */
    negative = false;
    if (*second_input == '-') {
        negative = true;
        second_input += sizeof(char);
    }

    /* Get the base type for the second input */
    enum base_type second_base = parse_base(second_input);
    second_input += sizeof(char);

    if (second_base == UNKNOWN) {
        fprintf(stderr, "ERROR: Invalid base for second number\n");
        return EXIT_FAILURE;
    }

    /* Convert the second input to decimal */
    int second_value = convert_to_decimal(second_base, second_input);
    if (negative) second_value = -second_value;

    char *third_input = argv[4];
    enum base_type result_base = parse_base(third_input);

    if (result_base == UNKNOWN) {
        fprintf(stderr, "ERROR: Invalid result base\n");
        return EXIT_FAILURE;
    }

    int result_value;

    /* Compute the result value, based upon the operator given */
    if (operator == '+') {
        result_value = first_value + second_value;
    } else if (operator == '-') {
        result_value = first_value - second_value;
    } else { // multiplication
        result_value = first_value * second_value;
    }

    negative = result_value < 0;

    /* Print a negative symbol if the result is negative */
    if (negative) printf("-");

    /* Print the result base and the result itself */
    char *result_string = convert_from_decimal(result_value, result_base);
    printf("%c%s\n", letter_for_base(result_base), result_string);
    free(result_string);

    return EXIT_SUCCESS;
}