IDIR = include
SDIR = src
ODIR = .objects

CFLAGS = -Wall -ggdb

EXEC_FILE = sorting

LIBS = -lrt

CC = gcc


# first line defines the dependencies, the second line adds the include directory
# to the front of the names, e.g. linefinder.hpp -> include/linefinder.hpp
# the two lines that follow perform the same function on the object files.
_DEPS = get_int.h linked_list.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = get_int.o linked_list.o sorting_test.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# the .PHONY target specifies that the dependency targets do not refer to files, this prevents conflicts
# if files with the same names as the dependencies are ever created
.PHONY: all run clean

all: $(EXEC_FILE)

run: $(EXEC_FILE)
	./$(EXEC_FILE)

# sets a general rule for creating object files. $@ and $< are special macros referring to
# the left and right hand sides of the rule definition respectively, e.g. $@ -> $(ODIR)/%.o
# $< -> $(SDIR)/%.cpp
# -c option says not to run the linker, but instead output the .o file
# -o $@ says to put the output into a file named the same as the name of the rule, e.g. listfinder.o
$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# This is basically the same as the rule above, except that it is linking object files instead of 
# compiling them from source. $(LIBS) is a list of all the libraries that need to be linked to.
$(EXEC_FILE): $(OBJ)
	$(CC) -o $@ $^ $(LIBS) $(CFLAGS)


# the dash in front tells make to ignore the return status of the clean target. For example if
# make tries to rm a file that doesn't exist (if it doesn't exist, who cares if it wasn't removed)
clean:
	-$(RM) $(ODIR)/* $(EXEC_FILE) 