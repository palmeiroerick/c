CC = cc
CFLAGS = -Wall -Wextra -Werror
BUILD = build

c00 =	c_putchar alphabet letters numbers is_negative \
		comb comb2 c_putnbr combn combn2

c01 =	ft_ft ultimate_ft swap div_mod ultimate_div_mod \
		c_putstr c_strlen rev_int_array sort_int_array 

c02 =	c_strcpy c_strncpy is_alpha is_numeric is_lower \
		is_upper is_print upper lower capitalize \
		c_strlcpy putstrnp print_memory

c03 =	c_strcmp c_strncmp c_strcat c_strncat c_strstr c_strlcat

c04 =	r_strlen r_putstr r_putnbr

r04 =	r_putnbr-rs 

c_itoa = itoa itoa2 itoa3 

.PHONY: $(c00) $(c01) $(c02) $(c03) $(c04) $(r04) $(c_itoa) clean

LIB = build/lib/libc.a

$(LIB):
	$(MAKE) -C lib

$(c00): %: $(BUILD)/src/c00/%
	./$<

$(BUILD)/src/c00/%: src/c00/%.c $(LIB)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -Ilib $< $(LIB) -o $@

$(c01): %: $(BUILD)/src/c01/%
	./$<

$(BUILD)/src/c01/%: src/c01/%.c $(LIB)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -Ilib $^ -o $@

$(c02): %: $(BUILD)/src/c02/%
	./$<

$(BUILD)/src/c02/%: src/c02/%.c $(LIB)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -Ilib $^ -o $@

$(c03): %: $(BUILD)/src/c03/%
	./$<

$(BUILD)/src/c03/%: src/c03/%.c $(LIB)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -Ilib $^ -o $@

$(c04): %: $(BUILD)/src/c04/%
	./$<

$(BUILD)/src/c04/%: src/c04/%.c $(LIB)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -Ilib $< $(LIB) -o $@

$(r04): %: $(BUILD)/src/c04/%
	./$<

RUST_SOURCES = $(patsubst %-rs,%,$(r04))

$(addprefix $(BUILD)/src/c04/,$(r04)): $(BUILD)/src/c04/%-rs: src/c04/%.rs
	mkdir -p $(@D)
	rustc $< -o $@

$(c_itoa): %: $(BUILD)/extra/itoa/%
	./$<

$(BUILD)/extra/itoa/%: extra/itoa/%.c $(LIB)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $< $(LIB) -o $@

os00 =	hello_process

.PHONY: $(os00)

$(os00): %: $(BUILD)/ostep/os00/%
	./$<

$(BUILD)/ostep/os00/%: ostep/os00/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(BUILD)
	$(MAKE) -C lib clean
