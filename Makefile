src = $(shell find src/ -type f -name '*.cpp')

CXXFLAGS = -Wall -lmenu -lncurses

myprog: $(src)
	$(CXX) $(CXXFLAGS) $^ -o $@   

.PHONY: clean
clean:
	rm -f $(obj) myprog
