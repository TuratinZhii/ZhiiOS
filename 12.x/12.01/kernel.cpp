#include "types.h"

void printf(const char* str)
{
	static uint16_t* VideoMemory = (uint16_t*)0xb8000;

	for(int i = 0; str[i] != '\0'; ++i)
		VideoMemory[i] = (VideoMemory[i] & 0xFF00) | str[i];
}

extern "C" ctor start_ctors;
extern "C" ctor end_ctors;
extern "C" void callConstructors()
{
	for(ctor* i = &start_ctors; i != &end_ctors; i++)
		(*i)();
}

extern "C" void kernelMain(const void* multiboot_structure, uint32_t magicnumber)
{
	printf("Hello World! --- Hello ZhiiOS!");

	while(1);
}

