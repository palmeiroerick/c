#include "libc.h"

// size_t c_strlcat(char *dest, char *src, size_t dsize) {
//     size_t i = 0;
//     while (i < dsize && dest[i]) { i++; }
//     size_t j = 0;
//     while (i < dsize && src[j]) {
//         dest[i] = src[j];
//         i++;
//         j++;
//     }
//     dest[i] = '\0';
//     while (src[i]) { i++; }
//     return i;
// }

size_t c_strlcat(char *dest, char *src, size_t dsize) {
    size_t dlen = 0;
    size_t slen = 0;

    while (dlen < dsize && dest[dlen] != '\0') {
        dlen++;
    }

    while (src[slen] != '\0') {
        slen++;
    }

    if (dlen == dsize) {
        return dsize + slen;
    }
    
    size_t i = dlen;
    size_t j = 0;

    while (src[j] != '\0' && i + 1 < dsize) {
        dest[i] = src[j];
        i++;
        j++;
    }

    dest[i] = '\0';

    return dlen + slen;
}
                    
int main(void) {
    char str[11] = "";
    char *hello = "Hello";
    char *world = ", World!";
    c_strlcat(str, hello, 11);
    c_strlcat(str, world, 11);
    c_putstr(str);
    return 0;
}