#ifndef _BASE_H_
#define _BASE_H_

enum base_type {
    DECIMAL, HEXADECIMAL, OCTAL, BINARY, UNKNOWN
};

enum base_type parse_base(char *);

char letter_for_base(enum base_type type);

char* convert_from_decimal(int, enum base_type);

int convert_to_decimal(enum base_type, char *);

#endif