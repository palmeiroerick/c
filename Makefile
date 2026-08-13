CC = cc
CFLAGS = -Wall -Wextra -Werror
BUILD = build

TARGETS = c_putchar alphabet letters numbers is_negative comb comb2 putnbr

.PHONY: $(TARGETS) clean

$(TARGETS): %: $(BUILD)/%
	./$<

$(BUILD)/%: src/%.c
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(BUILD)
