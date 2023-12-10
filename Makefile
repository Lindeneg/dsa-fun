MAIN_FILE = main.cpp
SOURCE_FILES = $(wildcard **/*.cpp)

dev:
	clang++ \
		${MAIN_FILE} \
		$(SOURCE_FILES) \
		-std=c++17 \
		-ggdb \
		-pedantic-errors \
		-Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion

run:
	./a.exe

clean:
	rm a.exe a.ilk a.pdb
