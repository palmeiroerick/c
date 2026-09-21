CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilib
BUILD = build

c00 =	c_putchar alphabet letters numbers is_negative \
		comb comb2 c_putnbr combn combn2

c01 =	ft_ft ultimate_ft swap div_mod ultimate_div_mod \
		c_putstr c_strlen rev_int_array sort_int_array 

c02 =	c_strcpy c_strncpy is_alpha is_numeric is_lower \
		is_upper is_print upper lower capitalize

.PHONY: $(c00) $(c01) $(c02) clean

LIB = build/lib/libc.a

$(LIB):
	$(MAKE) -C lib

$(c00): %: $(BUILD)/c00/%
	./$<

$(BUILD)/c00/%: src/c00/%.c $(LIB)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $< $(LIB) -o $@

$(c01): %: $(BUILD)/c01/%
	./$<

$(BUILD)/c01/%: src/c01/%.c $(LIB)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $^ -o $@

$(c02): %: $(BUILD)/c02/%
	./$<

$(BUILD)/c02/%: src/c02/%.c $(LIB)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(BUILD)
	$(MAKE) -C lib clean
