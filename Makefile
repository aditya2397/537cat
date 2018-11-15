CC=gcc
WARNING_FLAGS=-Wall -Wextra -g
EXE=537cat

# the -g flag at all gcc compilation stages ensures that you can use gdb to debug your code
$(EXE): main.o cat.o
	$(CC) -g $(WARNING_FLAGS) -o $(EXE) main.o cat.o

main.o: main.c cat.h
	$(CC) -g $(WARNING_FLAGS) -c main.c

cat.o: cat.c cat.h
	$(CC) -g $(WARNING_FLAGS) -c cat.c

# the -f flag for rm ensures that clean doesn't fail if file to be deleted doesn't exist
clean:
	rm -f $(EXE) *.o

# recompile runs clean and then makes everything again to generate executable
# this is equivalent to running "make clean" followed by "make"
recompile: clean $(EXE)
