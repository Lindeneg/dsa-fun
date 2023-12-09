dev:
	clang++ main.cpp List/*.cpp \
		-std=c++17 \
		-ggdb \
		-pedantic-errors \
		-Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion

run:
	./a.exe

clean:
	rm a.exe a.ilk a.pdb
