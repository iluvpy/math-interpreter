#include <stdio.h>

#include "cstr.h"
#include "console.h"

int main(int argc, char **argv) {
    size_t max_chars = 100;
    printf("text 1 (max characters %ld): ", max_chars);
    cstr *text1 = minput(100);
    printf("text 2 (max characters %ld): ", max_chars);
    cstr *text2 = minput(100);


    cstr *result = add_cstr(text1, text2);

    printf("result: \n%s", getcstr(result));

    del_cstr(text1);
    del_cstr(text2);
    del_cstr(result);
    printf("exiting\n");
    return 0;
}