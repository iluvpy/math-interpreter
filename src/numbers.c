#include "numbers.h"

/**
 * @brief returns the number of digits in a number
 */
size_t geti_digits(long n) {
    long n2 = 10;
    size_t length = 1;
    for (;;) {
        if (n2 > n) return length;
        n2 *= 10;
    }
    
}
/**
 * @brief returns the number of digits in a number
 */
size_t getf_digits(float f, int decimals) {
    return geti_digits((int)(f)) + decimals;
}