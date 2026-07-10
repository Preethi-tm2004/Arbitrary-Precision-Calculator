CC = gcc

CFLAGS = -Wall

TARGET = a.out

SRC = main.c \
      addition.c \
      subtraction.c \
      multiplication.c \
      division.c \
      insert_first.c \
      insert_last.c \
      print_list.c \
      delete_list.c \
      compare_list.c \
      create_countlist.c \
      remove_leading_zeroes.c \
      signed_addition.c \
      validate.c \
      create_operand_list.c

OBJ = $(SRC:.c=.o)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c apc.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET) 
