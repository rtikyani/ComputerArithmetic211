#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "convert.h"

int octal_to_decimal(int octal) {
    char octal_string[CONVERSION_BUFFER_SIZE];
    snprintf(octal_string, CONVERSION_BUFFER_SIZE, "%d", octal);

    int result = 0;
    for (int i = 0; i < strlen(octal_string); i++) {
        int index = (int) (strlen(octal_string) - (i + 1));

        int value = octal_string[index] - '0';
        result += value * pow(8, i);
    }

    return result;
}

int decimal_to_octal(int decimal) {
    int remainder, index = 1, octal = 0;

    while (decimal != 0) {
        remainder = decimal % 8;
        decimal /= 8;
        octal += remainder * index;
        index *= 10;
    }

    return octal;
}

int hexadecimal_to_decimal(char *hex) {
    unsigned int result = 0;

    while (*hex != '\0') {
        result *= 16;

        char current = *hex;

        if (current >= 'A' && current <= 'F') {
            result += current - 'A' + (10 * sizeof(char));
        } else if (current >= 'a' && current <= 'f') {
            result += current - 'a' + (10 * sizeof(char));
        } else if (current >= '0' && current <= '9') {
            result += current - '0';
        }

        hex += sizeof(char);
    }

    return result;
}

static void reverse(char string[]) {

    size_t length = strlen(string);

    for (size_t start_index = 0, end_index = length - 1; start_index < end_index; start_index++, end_index--) {
        char current = string[start_index];
        string[start_index] = string[end_index];
        string[end_index] = current;
    }
}

char *decimal_to_hexadecimal(int decimal) {

    char hexadecimal_string[CONVERSION_BUFFER_SIZE];
    int hex_character = 0, index = 0, quotient = decimal;

    while (quotient != 0) {
        hex_character = quotient % 16;

        if (hex_character < 10) {
            hex_character += 48;
        } else {
            hex_character += 55;
        }

        hexadecimal_string[index++] = (char) hex_character;
        quotient = quotient / 16;
    }

    hexadecimal_string[index] = '\0';

    reverse(hexadecimal_string);

    return strdup(hexadecimal_string);
}

char *decimal_to_binary(int decimal) {

    char binary_string[CONVERSION_BUFFER_SIZE];

    int index = 0;

    while(decimal != 0) {
        binary_string[index++] = (char) ((decimal % 2 == 0) ? '0' : '1');
        decimal = decimal / 2;
    }

    binary_string[index] = '\0';

    reverse(binary_string);

    return strdup(binary_string);
}

int binary_to_decimal(char *binary) {

    int result = 0;

    for (int pow_index = 0, string_index = (int) (strlen(binary) - 1); string_index >= 0; string_index--, ++pow_index) {
        if (binary[string_index] == '1') {
            result = (int) (result + pow(2, pow_index));
        }
    }

    return result;
}