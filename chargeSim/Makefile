# Compile for both windows and linux
CC = g++

# compiler flags
# -g                 adds debugging information to excecutable file
# -Wall              turns on most, but not all, compiler warnings
CFLAGS = -Wall -g

# LINKER_FLAGS specifies libraries we're linking against
LINKER_FLAGS = -lSDL2

# build target executable:
TARGET = chargeSim
INCLUDE = -I /usr/include/SDL2

all: $(TARGET)

chargeSim: chargeSim.cpp gameScreen.o

gameScreen.o: gameScreen.cpp gameScreen.hpp
	$(CC) $(CFLAGS) $(LINKER_FLAGS) $(INCLUDE) -c -o $@ $<
	cp $^ win/

$(TARGET): $(TARGET).cpp gameScreen.o
	$(CC) $(CFLAGS) $(LINKER_FLAGS) $(INCLUDE) -o $@ $^
	cp $< win/
	cp Winmake win/Makefile

clean:
	# executable files
	$(RM) $(TARGET)
	$(RM) win/$(TARGET).exe
	# object files
	$(RM) *.o
	$(RM) win/*.o
