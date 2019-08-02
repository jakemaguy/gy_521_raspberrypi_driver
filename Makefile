src = $(shell find src/ -type f -name '*.cpp')

CXXFLAGS = -Wall

myprog: $(src)
	$(CXX) $(CXXFLAGS) $^ -o $@   

.PHONY: clean
clean:
	rm -f $(obj) myprog
