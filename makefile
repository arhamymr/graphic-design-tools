# Application name
APP_NAME=app

# Source files
SOURCES=main.cpp

# Object files
OBJECTS=$(SOURCES:.cpp=.o)

# Use `wx-config` to get the compilation and linking flags.
# Replace `wx-config` with `$(shell pkg-config --cflags --libs wxWidgets)` if using pkg-config
WX_CXXFLAGS=$(shell wx-config --cxxflags)
WX_LIBS=$(shell wx-config --libs)

# Compilation flags
CXXFLAGS+=-Wall $(WX_CXXFLAGS)

# Linking flags
LDFLAGS=$(WX_LIBS)

# Default target
all: $(APP_NAME)

# Link the application
$(APP_NAME): $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Compile the source files into object files
%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

# Clean target
clean:
	rm -f $(OBJECTS) $(APP_NAME)

# Run target
run: $(APP_NAME)
	./$(APP_NAME)

# Phony targets
.PHONY: all clean run