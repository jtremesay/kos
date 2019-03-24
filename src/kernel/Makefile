ROOT_DIR = $(CURDIR)/../..

PREFIX = i686-elf-
AS = $(PREFIX)as
CC = $(PREFIX)gcc
CXX =  $(PREFIX)g++
CXXFLAGS = -nostdlib -std=c++17 -ffreestanding -O3 -Wall -Wextra -fno-exceptions -fno-rtti
INCLUDES = -I $(ROOT_DIR)/include

TARGET = kernel
BUILD_DIR = $(ROOT_DIR)/build/$(TARGET)
ASM_SOURCES = \
	boot.s
CPP_SOURCES = \
	main.cpp

OBJECTS = $(ASM_SOURCES:%.s=$(BUILD_DIR)/%.o) $(CPP_SOURCES:%.cpp=$(BUILD_DIR)/%.o)
DEPENDENCIES = $(OBJECTS:%.o=%.d)

all: $(TARGET)

$(TARGET): $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): linker.ld $(OBJECTS)
	mkdir -p $(@D)

	$(CXX) $(CXXFLAGS) -o $@ -T $^

-include $(DEPENDENCIES)

$(BUILD_DIR)/%.o: %.cpp
	mkdir -p $(@D)

	$(CXX) $(CXXFLAGS) $(INCLUDES) -MMD -o $@ -c $<

$(BUILD_DIR)/%.o: %.s
	mkdir -p $(@D)

	$(CXX) -o $@ -c $<

clean:
	$(RM) $(BUILD_DIR)/$(TARGET) $(OBJECTS) $(DEPENDENCIES)

distclean:
	$(RM) -r $(BUILD_DIR)