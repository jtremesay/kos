PROJECT_DIR = $(CURDIR)
ROOT_DIR = $(PROJECT_DIR)/../..
BUILD_DIR = $(ROOT_DIR)/build/iso

TARGET = $(BUILD_DIR)/kOS.iso

all: $(TARGET)

$(TARGET):
	mkdir -p $(BUILD_DIR)/files
	cp -a $(PROJECT_DIR)/boot $(BUILD_DIR)/files/
	cp -a  $(BUILD_DIR)/../kernel/kernel.bin $(BUILD_DIR)/files/boot/
	grub-mkrescue -o $@ $(BUILD_DIR)/files

clean:
	$(RM) $(TARGET)

distclean:
	$(RM) -r $(BUILD_DIR)