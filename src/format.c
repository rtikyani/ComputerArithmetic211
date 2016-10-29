#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

static enum format_type {
    INTEGER, FLOAT, UNKNOWN
};

static enum format_type format_for(char *input) {

    if (strcmp(input, "int")) {
        return INTEGER;
    } else if (strcmp(input, "float")) {
        return FLOAT;
    }

    return UNKNOWN;
}

static int twos_complement_to_decimal(char *binary, int significantBits) {

    int exponent = (int) pow(2, significantBits - 1);
    int result = 0;

    for (int index = 0; index < significantBits; ++index) {

        if (index == 0 && binary[index] != '0') {
            result = -exponent;
        } else {
            result += (binary[index] - '0') * exponent;
        }

        exponent /= 2;
    }

    return -result;
}

int main(int argc, char **argv) {

    if (argc != 3) {
        fprintf(stderr, "ERROR: Wrong number of arguments\n");
        return EXIT_FAILURE;
    }

    enum format_type type = format_for(argv[2]);

    if (type == UNKNOWN) {
        fprintf(stderr, "ERROR: Invalid format\n");
        return EXIT_FAILURE;
    }

    char *bits = argv[1];

    if (strlen(bits) != 32) {
        fprintf(stderr, "ERROR: Wrong number of bits\n");
        return EXIT_FAILURE;
    }

    if (type == FLOAT) {



    } else if (type == INTEGER) {

        int decimal = twos_complement_to_decimal(bits, 32);
        printf("%d\n", decimal);

    }

    return EXIT_SUCCESS;

}