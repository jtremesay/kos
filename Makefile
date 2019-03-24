QEMU = qemu-system-i386

TARGETS = \
	kernel

all: $(TARGETS)

$(TARGETS):
	$(MAKE) -C src/$@

qemu: kernel
	$(QEMU) -kernel build/$</$<

clean:
	$(MAKE) -C src/kernel $@

distclean:
	$(MAKE) -C src/kernel $@

.PHONY: all clean distclean $(TARGETS) qemu