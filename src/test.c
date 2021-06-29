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

void printTest(char *name) {
    printGreen("------ ");
    printGreen(name);
    printlnGreen(" ------");
}
int main(int argc, char const *argv[])
{
    printf("starting test...\n");
    char d1[] = "123456789"; // digit
    char d2[] = "123.65432"; // digit
    char d3[] = "234d2rfgs"; // not a digit 
    char *hello_world = "hello world";
    char *color_text;
    char *rev_test = "hello";

    printTest(" text test ");
    // testing colors
    printlnGreen("green text");
    printlnRed("red text");

    printTest("text functions");
    // get color text
    getColorText(&color_text, "Red", KRED);
    printf("testing get color text; %s <- red?\n", color_text);

    // reverse string
    printf("testing rev_str: '%s' becomes -> ", rev_test);
    rev_str(&rev_test, rev_test);
    printf("%s\n", rev_test);

    
    printTest("Util test");
    bool res1 = string_digit(d1);
    bool res2 = string_digit(d2);
    bool res3 = string_digit(d3);
    printf("testing string digit\n");
    print_res("string digit d1 T: ", res1);
    print_res("string digit d2 T: ", res2);
    print_res("string digit d3 F: ", res3);

    printTest("Vector test");
    Vector v;
    initV(&v);
    printf("initalized vector, length: %ld\n", v.length);
    appendV(&v, 100);
    print_res("appended 100 to vector successfully: ", (Vget(&v, 0) == 100));
    deleteVec(&v);
    print_res("deleted vector successfully: ", (v.ptr == NULL));

    printTest("String Vector test");
    sVector sv;
    initsV(&sv);
    printf("initialized svector, length: %ld\n", sv.length);
    appendsV(&sv, hello_world);
    printf("appended %s to svector, result: %s\n", hello_world, sVget(&sv, 0));
    
    deletesVec(&sv);
    print_res("deleted svector successfully: ", (sv.ptr == NULL));


    free(color_text);
    free(rev_test);
    return 0;
}
