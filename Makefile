CC = cc
CFLAGS = -Wall -Wextra -Werror
BUILD = build

TARGETS = c_putchar alphabet letters

.PHONY: $(TARGETS) clean

$(TARGETS): %: $(BUILD)/%
	./$<

$(BUILD)/%: src/%.c
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(BUILD)
