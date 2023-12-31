#ifndef TYPES_H_
#define TYPES_H_

typedef void* addr;
typedef addr ADDR;

typedef void (*ctor)();
typedef ctor CTOR;

typedef char int8_t;
typedef unsigned char uint8_t;
typedef int8_t INT8_T;
typedef uint8_t UINT8_T;

typedef short int16_t;
typedef unsigned short uint16_t;
typedef int16_t INT16_T;
typedef uint16_t UINT16_T;

typedef int int32_t;
typedef unsigned int uint32_t;
typedef int32_t INT32_T;
typedef uint32_t UINT32_T;

typedef long long int64_t;
typedef unsigned long long uint64_t;
typedef int64_t INT64_T;
typedef uint64_t UINT64_T;

///

void print(const int8_t *str)
{
	uint16_t *display_addr = (uint16_t*)0xb8000;
	for(int i = 0; str[i]; i++)
		display_addr[i] = (display_addr[i] & 0xFF00) | str[i];
}

#endif

