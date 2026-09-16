CC = cc
CFLAGS = -Wall -Wextra -Werror
BUILD = build

c00 =	putchar alphabet letters numbers is_negative \
		comb comb2 putnbr combn combn2

c01 =	ft_ft ultimate_ft swap div_mod ultimate_div_mod \
		putstr strlen rev_int_array sort_int_array 

c02 =	strcpy

.PHONY: $(c00) $(c01) clean

$(c00): %: $(BUILD)/c00/%
	./$<

$(BUILD)/c00/%: src/c00/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $^ -o $@

$(c01): %: $(BUILD)/c01/%
	./$<

$(BUILD)/c01/%: src/c01/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $^ -o $@

$(c02): %: $(BUILD)/c02/%
	./$<

$(BUILD)/c02/%: src/c02/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(BUILD)
