#include "libc.h"

char is_alpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

char is_alphanum(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

char upper(char c) {
    if (c >= 'a' && c <= 'z')
        return (c - ('a' - 'A'));
    return c;
}

char lower(char c) {
    if (c >= 'A' && c <= 'Z')
        return (c + ('a' - 'A'));
    return c;
}

char *capitalize(char *str) {
    if (!str[0]) {
        return str;
    }
    
    if (is_alpha(str[0])) {
        str[0] = upper(str[0]);
    }

    int i = 1;
    while (str[i]) {
        if (is_alpha(str[i]) && !is_alphanum(str[i - 1]))
            str[i] = upper(str[i]);
        else
            str[i] = lower(str[i]);
        i++;
    }

    return str;
}

int main(void) {
    char str[] = "Hi, how are you? 42Words FORTY-TWO; fifty+one";

    c_putstr(capitalize(str));
    return 0;
}