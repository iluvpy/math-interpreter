#include <stdio.h>

#include "cstr.h"

int main(int argc, char **argv) {

    cstr *str = get_cstr("hello ");
    append_cstr(str, "world");
    printf("%s\n", getcstr(str));

    del_cstr(str);
    printf("exiting\n");
    return 0;
}