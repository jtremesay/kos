PREFIX = i686-elf-
AS = $(PREFIX)as
CC = $(PREFIX)cpp
CXX =  $(PREFIX)c++
CXXFLAGS = -nostdlib -std=c++17 -ffreestanding -O3 -Wall -Wextra -fno-exceptions -fno-rtti
INCLUDES = -I include
QEMU = qemu-system-x86_64

BUILD_DIR = build
TARGET = kos.bin
ASM_SOURCES = kernel/boot.s
CPP_SOURCES = kernel/main.cpp kernel/string.cpp kernel/terminal.cpp kernel/vga.cpp
OBJECTS = $(ASM_SOURCES:%.s=$(BUILD_DIR)/%.o) $(CPP_SOURCES:%.cpp=$(BUILD_DIR)/%.o)
DEPENDENCIES = $(OBJECTS:%.o=%.d)

all: $(TARGET)
	
qemu: $(BUILD_DIR)/$(TARGET)
	$(QEMU) -kernel $<


$(TARGET): $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): kernel/linker.ld $(OBJECTS)
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