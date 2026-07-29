CC = cc
CFLAGS = -Wall -Wextra -Werror
BUILD = build

.PHONY: c_putchar

c_putchar: $(BUILD)/c_putchar
	./$<

build/c_putchar: src/c_putchar.c
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $^ -o $@

alphabet: $(BUILD)/alphabet
	./$<

build/alphabet: src/alphabet.c
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $^ -o $@
