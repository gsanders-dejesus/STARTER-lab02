CXX = g++
CXXFLAGS = -std=c++11 -Wall -g
OBJS = intbst.o testbst.o

testbst: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp intbst.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o testbst

.PHONY: clean
