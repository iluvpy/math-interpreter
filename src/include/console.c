#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cstr.h"
#include "console.h"


// input 

// max input
// set max bytes
cstr *minput(size_t max) {
    char *str = malloc(max);
    str = fgets(str, max, stdin);
	size_t size = strlen(str)+1;
	str = realloc(str, size);
	str[size-2] = '\0'; // overwrite endline char (last char)
    return cstr_from_allocstr(str);
}

// gets input dynamically
cstr *dynamic_input() {
	size_t len = INPUT_LENGTH;
	char *input_ = malloc(len);
	int i = 0;
	char c;
	while ((c = fgetc(stdin)) && c != '\n' && c != EOF) {
		input_[i] = c;

		i++;
		if (i > len) {
			len += INPUT_LENGTH;
			input_ = realloc(input_, len);
		}	
	}

	// no input was given
	if (i == 0) return NULL;
	// resize to correct size and set null char
	input_ = realloc(input_, i);
	input_[i] = '\0';

	return cstr_from_allocstr(input_); // create cstr from allocated char*
}


// output 

void printcolor(char *text, char *color) {
    printf("%s%s%s", color, text, Reset);
}

void printlncolor(char *text, char *color) {
    printcolor(text, color);
    putc(10, stdin);
}


// other

void clear_console() {
#ifdef WIN32_
    system("cls");
#else
    system("clear");
#endif
}

