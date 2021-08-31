ex      := main
srcdirs := .
hdrdirs := 
cflags  := -c -Wall -Wextra
targdir := target

srcs := $(wildcard $(addsuffix /*.cpp,$(srcdirs))) 
objs := $(patsubst %.cpp,%.o,$(srcs))
objs := $(patsubst src/%,$(targdir)/%,$(objs))
dirs := $(dir $(objs))
incl := $(addprefix -I,$(hdrdirs))




# common
all: build

build: $(ex)

run: build
	./$(ex) < input

re: fclean build

rerun: fclean run



# compilation and linking
$(ex): $(dirs) $(objs)
	g++ -o $@ $(objs)

$(targdir)/%.o: src/%.cpp
	g++ -o $@ $(cflags) $(incl) -MD $<

%/: # don't works on mac, remove '/'
	mkdir -p $@

include $(shell if [ -d $(targdir) ]; then find $(targdir) -name "*.d"; fi)



# accesory
clean:
	rm -rf $(targdir)

fclean: clean
	rm -f $(ex)

.PHONY: all build run re rerun test clean fclean



# END
