CXX = g++
CXXFLAGS = -pedantic-errors -std=c++11

EXEC = game
SRCS = main.cpp character.cpp room.cpp maze.cpp battle.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = main.h character.h room.h maze.h battle.h

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

.PHONY: all clean
