#include <stdio.h>

#define print(format, ...) \
	{printf("[%s : %s : %d] ", \
	__FILE__, __func__, __LINE__); \
	printf(format, ##__VA_ARGS__);}

#define BEGIN 0
#define YIELD 1
#define BLOCK 2

typedef void (*PHREAD_ENTRY) (void *arg);

int resume_phread(PHREAD_ENTRY p)
{
	int event = YIELD;
	p(&event);
}

int block_phread(void *p)
{
}

int create_phread(PHREAD_ENTRY p, void *arg)
{
	if (p == NULL) {
		print("pthread null\n");
	}
	p(arg);
}

int phread_one(void *arg)
{
	int event = *((int*)arg);
	switch(event) {
	case YIELD:
		goto pos;
	case BEGIN:
		break;
	default:
		break;
	}
	int pos = 0;
	//block_phread(phread_one);
	event = BLOCK;
	if (event == BLOCK) {
		print("block\n");
		return 0;
	}
pos:
	print("running\n");
}

int phread_two(void *arg)
{
	resume_phread(phread_one);
	print("running\n");
}

int main()
{
	int event = BEGIN;
	create_phread(phread_one, &event);
	create_phread(phread_two, &event);
	return 0;
}
