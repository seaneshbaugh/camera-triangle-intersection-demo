CXX=clang++
CXXFLAGS=-std=c++11 -stdlib=libc++ -Weverything -Wno-padded -Wno-c++98-compat -g

TARGET_NAME=c-int

SOURCE_FILES=\
	src/camera.cpp \
	src/intersection.cpp \
	src/line_segment.cpp \
	src/main.cpp \
	src/triangle.cpp \
	src/util.cpp

all: clean default

default: $(TARGET_NAME)

$(TARGET_NAME):
	mkdir -p build
	$(CXX) $(CXXFLAGS) $(SOURCE_FILES) -o build/$(TARGET_NAME)

clean:
	rm -f build/$(TARGET_NAME)
	rm -rf build/$(TARGET_NAME).dSYM
