CC = cc
CFLAGS = -Wall -Wextra -Werror
BUILD = build

TARGETS = c_putchar alphabet letters numbers is_negative comb comb2 putnbr combn combn2 \
		ft_ft ultimate_ft swap div_mod ultimate_div_mod

.PHONY: $(TARGETS) clean

$(TARGETS): %: $(BUILD)/%
	./$<

$(BUILD)/%: src/%.c
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(BUILD)
