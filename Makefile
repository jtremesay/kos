ROOT_DIR = $(CURDIR)
BUILD_DIR = $(ROOT_DIR)/build


QEMU = qemu-system-i386

TARGETS = \
	kernel \
	iso

all: $(TARGETS)

$(TARGETS):
	$(MAKE) -C src/$@

qemu: iso
	$(QEMU) -cdrom build/iso/kOS.iso

iso: kernel

clean:
	$(MAKE) -C src/kernel $@
	$(MAKE) -C src/iso $@

distclean:
	$(MAKE) -C src/kernel $@
	$(MAKE) -C src/iso $@

.PHONY: all clean distclean $(TARGETS) qemu