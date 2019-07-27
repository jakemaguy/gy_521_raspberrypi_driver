src = $(wilcard src/*.cpp) \
      $(wilcard src/i2c/*.cpp)
obj = $(src:.cpp=.o)

CXXFLAGS = -Wall

myprog: $(obj)
	$(CXX) $(CXXFLAGS) $^ -o $^  
.PHONY: clean
clean:
	rm -f $(obj) myprog
