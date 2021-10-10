#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cstr.h"
#include "console.h"


// input 


// gets input dynamically
cstr *dynamic_input() {
	int len = INPUT_LENGTH;
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
	//fixes memory error ( Conditional jump or move depends on uninitialised value )
	input_[i] = '\0'; 
	return cstr_from_allocstr(input_); // create cstr from allocated char*
}


// output 

// acts like printf but you can specify a color 
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

// clears the console
void clear_console() {
#ifdef WIN32_
    system("cls");
#else
    system("clear");
#endif
}

