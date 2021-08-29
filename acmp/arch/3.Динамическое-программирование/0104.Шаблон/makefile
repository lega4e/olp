ex      := main
cflags  := -std=gnu++17 -c -Wall -Wextra
ldflags :=
libs    :=





# $(ex)
build: $(ex)

run: $(ex)
	$(ex) < input


re: clean build

rerun: clean run


source_dirs     := .
search_wildcard := $(wildcard $(addsuffix /*.cpp,$(source_dirs)))
object_files    := $(patsubst %.cpp,%.o,$(search_wildcard))
object_files    := $(notdir $(object_files))
object_files    := $(addprefix target/,$(object_files))
VPATH           := $(source_dirs)

$(ex): ./target $(object_files)
	g++ $(ldflags) -o $@ $(object_files) $(libs)

./target:
	if ! [ -d ./target ]; then mkdir target; fi

target/%.o: %.cpp
	g++ $(cflags) -o $@ -MD $(addprefix -I,$(source_dirs)) $<

include $(wildcard target/*.d)



# clean
clean:
	rm -rf target

fclean: clean
	rm -rf $(ex)





# end
