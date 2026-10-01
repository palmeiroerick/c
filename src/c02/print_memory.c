#include "libc.h"
#include "stdint.h"

int is_print(unsigned char c) {
    return c >= ' ' && c <= '~';
}

const char g_hex_digits[16] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
};

// I couldn't make this auxiliary function works here.
// This have something to do with size being the half I assume?
// char *reverse(char *str);

// using size_t for size and i creates a bug.
// Probably UB indexing (this actually makes little sense)
// Is it possible to store the char backward?
// So I don't need to reverse them.
// I still don't understand c indexing boundiaries.
void print_address(unsigned char *byte) {
    int size = sizeof(byte);
    char output[size];

    const uintptr_t address = (uintptr_t)byte;
    uintptr_t high_nibble = address / 16;
    uintptr_t low_nibble = address % 16;
    output[0] = g_hex_digits[low_nibble];

    int i = 1;
    while (i < size * 2) {
        low_nibble = high_nibble % 16;
        high_nibble = high_nibble / 16;
        output[i] = g_hex_digits[low_nibble];
        i++;
    }

    // c_putstr(output);

    // i = size - 1 did not work but size * 2 -1 did.
    // what is happening? Is size 8 not 16?
    i = size * 2 - 1;
    while (i >= 0) {
        c_putchar(output[i]);
        i--;
    }
}

void print_byte_hex(unsigned char byte) {
    c_putchar(g_hex_digits[byte / 16]);
    c_putchar(g_hex_digits[byte % 16]);
}

// I don't like this lines initialization.
// Probably the variable columns isn't good practice.
// And the function is too big anyway.
// The lazy approach is to abstract printing byte_hex
// and print_char_non_printable [bad name]. Maybe this is
// indeed the solution but there is other way of structuring this?
// Or it simply manages the concept of lines and then outsource
// for other functions to print the required stuff?
// I also don't like the column re-assignments.
void *print_memory(void *address, size_t size) {
    unsigned char *data = (unsigned char *)address;

    const size_t columns = 16;
    const size_t lines = size % columns == 0 ? size / columns : size / columns + 1;
    size_t line = 0;
    size_t column = 0;

    while (line < lines) {
        print_address(data + line * columns);
        c_putstr(": ");

        while (column < columns && column < size) {
            size_t index = line * columns + column;
            print_byte_hex(data[index]);
            if (column % 2 == 1) c_putchar(' ');
            column++;
        }

        column = 0;

        while (column < columns && column < size) {
            size_t index = line * columns + column;
            if (is_print(data[index])) {
                c_putchar((char)data[index]);
            }
            else {
                c_putchar('.');
            }
            column++;
        }
        c_putchar('\n');
        column = 0;
        line++;
    }


    return address;
}

int main(void) {
    unsigned char data[] = {
        0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x2c, 0x20, 0x66,
        0x72, 0x69, 0x65, 0x6e, 0x64, 0x73, 0x2e, 0x09,
        0x00, 0x00, 0x69, 0x74, 0x27, 0x73, 0x00, 0x00,
        0x00, 0x63, 0x72, 0x61, 0x7a, 0x79, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x77, 0x68, 0x61, 0x74, 0x20,
        0x79, 0x6f, 0x75, 0x00, 0x63, 0x61, 0x6e, 0x0a, 
        0x00, 0x00, 0x00, 0x00, 0x64, 0x6f, 0x00, 0x77,
        0x69, 0x74, 0x68, 0x20, 0x69, 0x74, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x70, 0x72, 0x69, 0x6e, 0x74,
        0x5f, 0x6d, 0x65, 0x6d, 0x6f, 0x72, 0x79, 0x00,
    };

    print_memory(data, 80);

    return 0;
}