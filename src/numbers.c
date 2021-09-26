#include "numbers.h"

/**
 * @brief returns the number of digits in a number
 */
size_t geti_digits(long n) { // TODO: ADD A WAY TO CALCULATE THE NUMBER OF DIGITS OF A NEGATIVE NUMBER
    long n2 = 10;
    if (n >= 0) {
		size_t length = 1;
		for (;;) {
			if (n2 > n) return length;
			n2 *= 10;
			length++;
		}
		return length;
	}

	return 0;
}
/**
 * @brief returns the number of digits in a number
 */
size_t getf_digits(double f, int decimals) {
    return geti_digits((int)(f)) + decimals;
}