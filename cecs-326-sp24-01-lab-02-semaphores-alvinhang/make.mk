# This defines what compiler it is for
CC = gcc

# This is a flag for the compiler to show all warnings and treat warnings as errors
CFLAGS = -Wall -Werror

# This holds the libraries that are needed to compile the program
LIBS = -lrt -pthread

# These are the source files
SOURCES = barbarian.c wizard.c rogue.c game.c dungeon.c

#These are the object files that are created from the source files
OBJECTS = $(SOURCES:.c=.o)

# These are the executables that are created from the object files
EXECUTABLES = barbarian wizard rogue game

# This is the default target that is run when you type make
all: $(EXECUTABLES)

# These are the rules to create the executables
wizard: wizard.o dungeon.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

barbarian: barbarian.o dungeon.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

rogue: rogue.o dungeon.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# This is used to create the game executable and give it execute permissions
game: game.o dungeon.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
	chmod +x $@

# This compiles the source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# This is used to clean up the object files and executables and filteres out the dungeon.o file from being removed
clean:
	rm -f $(filter-out dungeon.o,$(OBJECTS)) $(EXECUTABLES)

# This is the command used to run the game
run: game
	./game

# This is used to tell make that the following targets are not files
.PHONY: all clean run
