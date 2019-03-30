PROJECT_DIR = $(CURDIR)
ROOT_DIR = $(PROJECT_DIR)/../..
BUILD_DIR = $(ROOT_DIR)/build/kernel

PREFIX = i686-elf-
AS = $(PREFIX)as
CC = $(PREFIX)gcc
CXX =  $(PREFIX)g++
CXXFLAGS = -nostdlib -std=c++17 -ffreestanding -O3 -Wall -Wextra -fno-exceptions -fno-rtti
INCLUDES = -I $(ROOT_DIR)/include

TARGET = $(BUILD_DIR)/kernel.bin
ASM_SOURCES = \
	boot.S
CPP_SOURCES = \
	main.cpp

OBJECTS = $(ASM_SOURCES:%.S=$(BUILD_DIR)/%.o) $(CPP_SOURCES:%.cpp=$(BUILD_DIR)/%.o)
DEPENDENCIES = $(OBJECTS:%.o=%.d)

all: $(TARGET)

$(TARGET): linker.ld $(OBJECTS)
	mkdir -p $(@D)

	$(CXX) $(CXXFLAGS) -o $@ -T $^

-include $(DEPENDENCIES)

$(BUILD_DIR)/%.o: %.cpp
	mkdir -p $(@D)

	$(CXX) $(CXXFLAGS) $(INCLUDES) -MMD -o $@ -c $<

$(BUILD_DIR)/%.o: %.S
	mkdir -p $(@D)

	$(CXX) $(CXXFLAGS) $(INCLUDES) -MMD -o $@ -c $<

clean:
	$(RM) $(TARGET) $(OBJECTS) $(DEPENDENCIES)

distclean:
	$(RM) -r $(BUILD_DIR)