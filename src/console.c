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
	str = realloc(str, size+1);

    return cstr_from_allocstr(str);
}

// gets input dynamically
cstr *dynamic_input() {
	size_t len = INPUT_LENGTH;
	char *input_ = malloc(len);
	int i = 0;
	char c;
	while ((c = fgetc(stdin)) && c != '\n') {
		input_[i] = c;

		i++;
		if (i > len) {
			len += INPUT_LENGTH;
			input_ = realloc(input_, len);
		}	
	}

	// no input was given
	if (i == 0) {
		free(input_);
		return NULL;
	}
	// resize to correct size and set null char
	input_ = realloc(input_, i+1);
	input_[i] = '\0'; // fixes memory error
	return cstr_from_allocstr(input_); // create cstr from allocated char*
}


// output 

void printcolor(char *color, char *format, ...) {
	va_list argp;
  	va_start(argp, format);
	fputs(color, stdout);
  	while (*format != '\0') {
    	if (*format == '%') {
			format++;
			if (*format == 'c') {
				char char_to_print = va_arg(argp, int);
				putchar(char_to_print);
			} 
			else if (*format == 's') {
				char *string = va_arg(argp, char*);
				fputs(string, stdout);
			}
    	} 
		else {
     	 	putchar(*format);
    	}
    	format++;
  	}
	fputs(Reset, stdout);
  	va_end(argp);
}



// other

void clear_console() {
#ifdef WIN32_
    system("cls");
#else
    system("clear");
#endif
}

