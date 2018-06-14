CXX = g++
CXXFLAGS = --std=c++17

TARGET = cppabusesort
SRCS = cppabusesort.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean

clean:
	-rm *o $(TARGET)
