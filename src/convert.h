#ifndef _CONVERT_H_
#define _CONVERT_H_

#include <limits.h>

#define CONVERSION_BUFFER_SIZE sizeof(int) * CHAR_BIT

/**
 * Converts an octal number into a decimal number.
 */
int octal_to_decimal(int);

/**
 * Converts an decimal number into a octal number.
 */
int decimal_to_octal(int);

/**
 * Converts a decimal number into a hexadecimal string.
 */
char *decimal_to_hexadecimal(int);

/**
 * Converts a hexadecimal string into a decimal number.
 */
int hexadecimal_to_decimal(char *);

/**
 * Converts a decimal number into a binary string.
 */
char *decimal_to_binary(int);

/**
 * Converts a binary string into a decimal number.
 */
int binary_to_decimal(char *);

#endif