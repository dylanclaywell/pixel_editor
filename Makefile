TARGET := pixel_editor

CXX := g++
CXXFLAGS := -std=c++11 -g -Wall

LIBS := -lallegro

SRC := $(shell find . -name "*.cpp")
OBJECTS  := $(patsubst %.c, %.o, $(SRC))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LIBS) -o $(TARGET) $(OBJECTS)

clean:
	rm -f $(OBJECTS)
