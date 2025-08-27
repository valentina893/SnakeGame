CC = gcc
CFLAGS = -Wall -Wextra -g

# Object files for the main game build (no tests)
OBJS = src/position/position.o \
       src/snake/snake.o \
       src/board/board.o \
       src/apple/apple.o \
       src/game/game.o \
       lib/matrix/matrix.o \
       lib/random/random.o

# Final executable
TARGET = builds/snake

# Default rule (compile everything and link into the game)
all: $(TARGET)

# Rule to link the final executable
$(TARGET): src/snake_main.c $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Generic rule to compile any .c into .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run:
	./builds/snake