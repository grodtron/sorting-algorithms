IDIR = include
SDIR = src
ODIR = .objects

CFLAGS = -Wall -std=gnu99 -ggdb

EXEC_FILES = insertion_sort_array insertion_sort_linkedlist quicksort_array

LIBS = -lrt

CC = gcc

RMDIR = rm -rf


# first line defines the dependencies, the second line adds the include directory
# to the front of the names, e.g. linefinder.hpp -> include/linefinder.hpp
# the two lines that follow perform the same function on the object files.
_DEPS = get_int.h linked_list.h insertion_sort.h bool.h parse_args.h quicksort.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# the .PHONY target specifies that the dependency targets do not refer to files, this prevents conflicts
# if files with the same names as the dependencies are ever created
.PHONY: all run clean

all: $(EXEC_FILES)

# sets a general rule for creating object files. $@ and $< are special macros referring to
# the left and right hand sides of the rule definition respectively, e.g. $@ -> $(ODIR)/%.o
# $< -> $(SDIR)/%.cpp
# -c option says not to run the linker, but instead output the .o file
# -o $@ says to put the output into a file named the same as the name of the rule, e.g. listfinder.o

# make sure that the objects directory exists!
$(ODIR):
	mkdir $(ODIR)

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS) $(ODIR)
	$(CC) -c -o $@ $< $(CFLAGS)

# This is basically the same as the rule above, except that it is linking object files instead of 
# compiling them from source. $(LIBS) is a list of all the libraries that need to be linked to.

insertion_sort_linkedlist: $(patsubst %, $(ODIR)/%, insertion_sort_linkedlist.o linked_list.o get_int.o parse_args.o  )
	$(CC) -o $@ $^ $(LIBS) $(CFLAGS) && cp $@ test/

insertion_sort_array: $(patsubst %, $(ODIR)/%, insertion_sort_array.o insertion_sort.o get_int.o parse_args.o  )
	$(CC) -o $@ $^ $(LIBS) $(CFLAGS) && cp $@ test/

quicksort_array: $(patsubst %, $(ODIR)/%, quicksort_array.o quicksort.o insertion_sort.o get_int.o parse_args.o  )
	$(CC) -o $@ $^ $(LIBS) $(CFLAGS) && cp $@ test/

# the dash in front tells make to ignore the return status of the clean target. For example if
# make tries to rm a file that doesn't exist (if it doesn't exist, who cares if it wasn't removed)
clean:
	$(RM) $(ODIR)/*;
	$(RM) $(EXEC_FILES);
	$(RM) $(patsubst %, test/%,  $(EXEC_FILES) );
