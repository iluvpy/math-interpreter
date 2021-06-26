#include <stdio.h>

#include "defines.h"
#include "utils.h"
#include "vector.h"
#include "console.h"


void print_res(char *t, bool res) {
    printf("%s", t);
    if (res) {
        printlnGreen("True");
    }
    else {
        printlnRed("False");
    }
}


int main(int argc, char const *argv[])
{
    printf("starting test...\n");
    char d1[] = "123456789"; // digit
    char d2[] = "123.65432"; // digit
    char d3[] = "234d2rfgs"; // not a digit 
    char *result_text = NULL;
    char *red = "red";
    char *rev_test = "hello";
    // testing colors
    printlnGreen("green text");
    printlnRed("red text");

    getColorText(red, KRED);
    printf("testing get color text; %s <- red?\n", red);
    char rev_cpy[strlen(rev_test)];
    strcpy(rev_cpy, rev_test);
    rev_str(rev_test);
    printf("testing rev str; '%s' becomes: %s\n", rev_cpy, rev_test);
    
    printlnGreen("------ Utils ------\n");
    bool res1 = string_digit(d1);
    bool res2 = string_digit(d2);
    bool res3 = string_digit(d3);
    printf("testing string digit\n");
    print_res("string digit d1 T: ", res1);
    print_res("string digit d2 T: ", res2);
    print_res("string digit d3 F: ", res3);

    printlnGreen("------ Vector ------\n");
    Vector v;
    initV(&v);
    printf("initalized vector, length: %d\n", v.length);
    appendV(&v, 100);
    print_res("appended 100 to vector successfully: ", (Vget(&v, 0) == 100));
    deleteVec(&v);
    print_res("deleting vector successfully: ", (v.ptr == NULL));
    free(result_text);
    return 0;
}
