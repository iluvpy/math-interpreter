#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cstr.h"
#include "console.h"
#include "tokens.h"

// input
// gets input dynamically (breaks for some reason at 4095 bytes)
cstr *dynamic_input() {
	int len = INPUT_LENGTH;
	char *input_ = malloc(len);
	int i = 0;
	char c;
	while ((c = fgetc(stdin)) && c != '\n') {
		input_[i] = c;

		i++;
		if (i >= len) {
			len += INPUT_LENGTH;
			input_ = realloc(input_, len * sizeof(char));
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
void print_color(char *color, char *format, ...) {
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


// prints out the help menu
void print_help_menu() {
    print_color(FgMagenta, "\nmathc debug version \n");
    print_color(FgGreen ,"------- Comannds -------\n");
    print_color(FgBlue, "'%s' or '%s' to show this menu again\n", H_CMD, H2_CMD);
    print_color(FgBlue, "'%s' or '%s' to clear the console\n", CLR_CMD, CLR2_CMD);
    print_color(FgBlue, "'%s' or '%s' to exit\n\n", Q_CMD, Q2_CMD);
	
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

// other

bool valid_math_expression(cstr *input) {
	for (int i = 0; i < cstr_len(input); i++) {
		char char_ = cstr_getc(input, i);
		if ((IS_LOWERCASE_CHAR(char_) || IS_UPPERCASE_CHAR(char_))) {
			return false;
		}
	}
	return true;
}

int handle_input(cstr *input) {
	if (valid_math_expression(input)) { return NO_COMMAND; }
	int res = check_commands(input); 
	return res;
}


// checks for commands
int check_commands(cstr *input) {

    char *str = cstr_str(input);

	if (str_eq_str(str, Q_CMD) || str_eq_str(str, Q2_CMD)) {
		return QUIT_COMMAND;
	}
	else if (str_eq_str(str, H_CMD) || str_eq_str(str, H2_CMD)) {
		print_help_menu();
		return COMMAND_EXECUTED;
	}
	else if (str_eq_str(str, CLR_CMD) || str_eq_str(str, CLR2_CMD)) {
		clear_console();
		return COMMAND_EXECUTED;
	}
    else if (!isdigit(str[0])) { // if the first letter of the input isnt a number 
		print_color(FgRed, "Uknown command '%s', please type '%s' or '%s' for help.\n", str, H_CMD, H2_CMD);
		return COMMAND_EXECUTED;
	}

	return NO_COMMAND;
}
