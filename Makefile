all: main

CXX = clang++
GXX = g++
override CXXFLAGS += -g -Wno-everything

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.cpp' -print | sed -e 's/ /\\ /g')
HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

main: $(SRCS) $(HEADERS)
	cd demo_app; ${GXX} *.cpp libgtest.a -lpthread -std=c++14 -I ${PWD}/demo_app/include -o main_gtest;

main-debug: $(SRCS) $(HEADERS)
	make main-debug -C demo_app 

clean:
	rm -f main main-debug