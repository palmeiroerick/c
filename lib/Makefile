CC = cc
CFLAGS = -Wall -Wextra -Werror
BUILD = ../build/lib

NAME = $(BUILD)/libc.a

SRC = c_putchar c_putnbr c_putstr

OBJ = $(SRC:%=$(BUILD)/%.o)

$(NAME): $(OBJ)
	mkdir -p $(@D)
	ar rcs $@ $^

$(BUILD)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(NAME)