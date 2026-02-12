CXX = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = cipher

SRCS = main.cpp block.cpp stream.cpp utility.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAG
	) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@