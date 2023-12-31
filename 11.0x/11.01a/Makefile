GPPPARAMS = -m32 -fno-use-cxa-atexit -fleading-underscore -fno-exceptions -fno-builtin -nostdlib -fno-rtti -fno-pie
ASPARAMS = --32
LDPARAMS = -melf_i386 -no-pie

objects = kernel.o loader.o

%.o: %.cpp
	g++ ${GPPPARAMS} -o $@ -c $<

%.o: %.s
	as ${ASPARAMS} -o $@ $<

ZhiiOS.bin: linker.ld ${objects}
	ld ${LDPARAMS} -T $< -o $@ ${objects}

ZhiiOS_11.01a.iso: ZhiiOS.bin
	mkdir iso
	mkdir iso/boot
	mkdir iso/boot/grub
	cp $< iso/boot/
	echo 'set timeout=0' > iso/boot/grub/grub.cfg
	echo 'set default=0' >> iso/boot/grub/grub.cfg
	echo 'menuentry "ZhiiOS 1" {' >> iso/boot/grub/grub.cfg
	echo '    multiboot /boot/ZhiiOS.bin' >> iso/boot/grub/grub.cfg
	echo '    boot' >> iso/boot/grub/grub.cfg
	echo '}' >> iso/boot/grub/grub.cfg
	grub-mkrescue --output=$@ iso
	rm -rf iso

clean:
	rm kernel.o loader.o ZhiiOS.bin ZhiiOS_11.01a.iso

