PREFIX = i686-elf-
AS = $(PREFIX)as
CC = $(PREFIX)cpp
CXX =  $(PREFIX)c++
CXXFLAGS = -nostdlib -std=c++17 -ffreestanding -O3 -Wall -Wextra -fno-exceptions -fno-rtti
INCLUDES = -I include
QEMU = qemu-system-x86_64

TARGET = kernel/kos.bin
ASM_SOURCES = kernel/boot.s
CPP_SOURCES = kernel/kernel.cpp kernel/string.cpp kernel/terminal.cpp kernel/vga.cpp
OBJECTS = $(patsubst %.cpp,%.o,$(CPP_SOURCES)) $(patsubst %.s,%.o,$(ASM_SOURCES))

all: $(TARGET)
	
qemu: $(TARGET)
	$(QEMU) -kernel $<

$(TARGET): kernel/linker.ld $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ -T $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	$(RM) $(TARGET) $(OBJECTS)