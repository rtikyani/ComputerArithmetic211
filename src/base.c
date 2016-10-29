#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "base.h"
#include "convert.h"

char letter_for_base(enum base_type type) {

    if (type == DECIMAL) {
        return 'd';
    } else if (type == HEXADECIMAL) {
        return 'x';
    } else if (type == OCTAL) {
        return 'o';
    } else if (type == BINARY) {
        return 'b';
    }

    return NULL;
}

char *convert_from_decimal(int number, enum base_type type) {

    if (type == DECIMAL) {
        char tmp[CONVERSION_BUFFER_SIZE];
        snprintf(tmp, CONVERSION_BUFFER_SIZE, "%d", number);
        return strdup(tmp);

    } else if (type == HEXADECIMAL) {
        return decimal_to_hexadecimal(number);

    } else if (type == OCTAL) {
        int octal = decimal_to_octal(number);
        char tmp[CONVERSION_BUFFER_SIZE];
        snprintf(tmp, CONVERSION_BUFFER_SIZE, "%o", octal);
        return strdup(tmp);

    } else if (type == BINARY) {
        return decimal_to_binary(number);

    }

    return NULL;
}

int convert_to_decimal(enum base_type type, char *input) {

    switch (type) {
        case DECIMAL:
            return atoi(input);

        case HEXADECIMAL:
            return hexadecimal_to_decimal(input);

        case OCTAL:
            return octal_to_decimal(atoi(input));

        case BINARY:
            return binary_to_decimal(input);

        default:
            return NULL;
    }

}

enum base_type parse_base(char *input) {
    char first = *input;

    switch (first) {
        case 'd':
            return DECIMAL;

        case 'o':
            return OCTAL;

        case 'x':
            return HEXADECIMAL;

        case 'b':
            return BINARY;

        default:
            return UNKNOWN;
    }
}