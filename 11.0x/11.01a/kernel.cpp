#include "./types.h"

void kernelMain(ADDR loader_addr, UINT32_T magic_num)
{
	print("Hello ZhiiOS!");
	while(1);
}

CTOR start_ctor;
CTOR end_ctor;

void callCtors()
{
	for(CTOR *i = &start_ctor; i != &end_ctor; i++)
		(*i)();
}

