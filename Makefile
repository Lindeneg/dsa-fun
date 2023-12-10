MAIN_FILE = main.cpp
SOURCE_FILES = $(wildcard **/*.cpp)

dev:
	g++ \
		${MAIN_FILE} \
		$(SOURCE_FILES) \
		-static-libstdc++ \
		-std=c++17 \
		-ggdb \
		-pedantic-errors \
		-Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion

run:
	./a.exe

clean:
	rm a.exe
