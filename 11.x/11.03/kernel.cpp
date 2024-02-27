#include "types.h"

void printf(const char* str)
{
	static uint16_t* video_memory = (uint16_t*)0xb8000;
	static uint32_t x = 0, y = 0;

	for(uint32_t i = 0; str[i] != '\0'; i++)
	{
		if(x >= 80)
		{
			y++;
			x = 0;
		}
		else if(y >= 25)
		{
			for(y = 0; y < 25; y++)
			{
				for(x = 0; x < 80; y++)
					video_memory[80 * y + x] = (video_memory[80 * y + x] & 0xFF00) | ' ';
			}

			x = 0;
			y = 0;
		}
		else
		{
			switch(str[i])
			{
				case '\n':
					y++;
					x = 0;
					break;
				default:
					video_memory[80 * y + x] = (video_memory[80 * y + x] & 0xFF00) | str[i];
					x++;
					break;
			}
		}
	}
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
	printf("Hello World! --- Hello ZhiiOS!\n");
	printf("ver 11.03");

	while(1);
}

