#include "libc.h"
#include "stdint.h"

// Maybe I should maintaing this code as it is right now.
// Even with the `column < size` bug. This can be a good
// Material for future revision and reference.

// This function uses that logic of being based on side effects. It
// calculates the character to print and prints it to stdout. This is
// becoming a recuring pattern in these c exercises. Coming back later
// to this, and the other exercises, and tring to store and return the
// output data would be interesting. The function merely operates on
// data, and the caller decides what to do with it.

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

    // Is it possible to generate the output string in the
    // proper order without needing to reverse it?
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

// I ended up adding two functions that perform basically the same
// operation. One byte can be representated by exactly two hexadecimal
// digits. So we don't need to loop or to reverse it.
// This is a good function? As far as I understand—and assuming c_putchar
// works—it will always produce the correct output. But again, This is a
// good function. Having an `itoa()` that supports other numerical bases
// and casting the byte to a int would be better? Because, this would
// remove the duplicated hexadecimal convertion logic.
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

    // I am representing a one dimentional byte array as a two
    // dimentional lines-columns abstraction. Thinking in terms of lines
    // is probably the correct approach, but maybe representing lines
    // as byte slices is a better representation of what should be printed.
    // I wonder what is the difference in the assembly of both approachs.
    // But it's probably less interesting I would guess. The former will
    // probably simply have instructions translating between the two
    // dimentional representation and the real index.
    const size_t columns = 16;
    const size_t lines = size % columns == 0 ? size / columns : size / columns + 1;
    size_t line = 0;
    size_t column = 0;

    while (line < lines) {
        print_address(data + line * columns);
        c_putstr(": ");

        // That's a interesting bug `column < size`
        // Because the variable are mesuring distinct things.
        // Column is the current position within a line [0 .. 15 when
        // columns are 16], while size is the data boudiary.
        // if lines == 1, size is less than 16, so the valid indexes 
        // are, indeed, 0 .. 15, columns and size will match.
        // But for every data with more that 1 line, this size will
        // always be more or equal 16. Therefore `column < size` will
        // always be true, never preventing iteration on invalid indexes.
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
    // I should stop being lazy and develop a small script to generate
    // this data automatically from a input string. Maybe randomizing
    // non-pritable character. It will be handy to create test cases.
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