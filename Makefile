TARGET := pixel_editor

CXX := g++
CXXFLAGS := -std=c++11 -g -Wall

LIBS := -lallegro -lallegro_primitives

SRC := $(shell find ./src -name "*.cpp")
OBJECTS  := $(patsubst %.c, %.o, $(SRC))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o ./build/$(TARGET) $(OBJECTS) $(LIBS)

clean:
	rm -f $(OBJECTS)
