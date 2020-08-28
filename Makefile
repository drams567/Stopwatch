CC = g++
CCFLAGS = -Wall -Wextra
EFLAGS = -I ~/Documents/Libraries/
LDFLAGS = -lncurses
OBJ = main.cpp Stopwatch.h

driver.out: $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) $(LDFLAGS) -o driver.out


.PHONY:
run:
	./driver.out

.PHONY:
valrun:
	valgrind ./driver.out

.PHONY:
clean:

	rm *.o*
	rm *~*
