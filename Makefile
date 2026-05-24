# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++17

# Get source file from command line or use default
SRC ?= HosiptalSystem.cpp

# Target executable name (derived from source file without extension)
TARGET = $(basename $(SRC))

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Clean up compiled files
clean:
	rm -f $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Phony targets
.PHONY: all clean run
