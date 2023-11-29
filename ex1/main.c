// 211908256 Noy Dvori
#include <stdio.h>
#include <stdbool.h>

const int SIZE = 8;

// This function returns 1 if it was compiled and run on a big endian machine and returns 0 if it was compiled
// and run on a little endian machine.
// char represent in 1 byte and int represent in 4 bytes, when we cast int to char it takes only the first byte in the
// representation of int.
int is_big_endian() {
    int n = 1;
    return !(*(char *) &n);
}

// This function gets bits array, and converts it to its decimal number.
// (multiplies the leftmost element in the array by 2^0, the element after it in the array by 2^1 and so on,
// and returns the sum of all values)
int binary_to_decimal_little_endian(bool bitArray[8]) {
    int sum = 0, j = 1, i;
    for (i = 0; i < SIZE - 1; i++) {
        if (bitArray[i] == true) {
            sum += j;
        }
        j *= 2;
    }
    return sum;
}


// This function gets bits array (binary number by sign magnitude representation), and returns its decimal value.
// (checks the sign- MSB value (=s), and return s*(decimal value))
int get_sign_magnitude(bool bitArray[8]) {
    int s = 1;
    if (bitArray[SIZE - 1] == true) {
        s = -1;
    }
    return binary_to_decimal_little_endian(bitArray) * s;
}

// This function gets bits array (binary number by twos complement representation), and returns its decimal value.
// (negative number -> reverses all the bits in the array, then adds 1 to the LSB and returns the decimal value of this
// binary number)
// (positive number -> returns the decimal value of this binary number)
int get_two_comp(bool bitArray[8]) {
    int i;
    // if positive:
    // returns the decimal value of this binary number
    if (bitArray[SIZE - 1] == false) {
        return get_sign_magnitude(bitArray);
    }
    // if negative:
    // reverses all the bits in the array.
    for (i = 0; i < 7; i++) {
        bitArray[i] = !bitArray[i];
    }
    // adds 1 to the LSB and returns the decimal value of this binary number.
    return get_sign_magnitude(bitArray) -1;
}
