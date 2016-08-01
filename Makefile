CXX=clang++
CXXFLAGS=-std=c++11 -stdlib=libc++ -Weverything -Wno-padded -g

TARGET_NAME=c-int

SOURCE_FILES=\
	src/main.cpp \
	src/util.cpp

all: clean default

default: $(TARGET_NAME)

$(TARGET_NAME):
	mkdir -p build
	$(CXX) $(CXXFLAGS) $(SOURCE_FILES) -o build/$(TARGET_NAME)

clean:
	rm -f build/$(TARGET_NAME)
	rm -rf build/$(TARGET_NAME).dSYM
