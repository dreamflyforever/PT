#include <stdio.h>

typedef void (*PHREAD_ENTRY) (void *arg);

#define print(format, ...) \
	{printf("[%s : %s : %d] ", \
	__FILE__, __func__, __LINE__); \
	printf(format, ##__VA_ARGS__);}

#define BEGIN 0
#define YIELD 1
#define BLOCK 2

#define PT_INIT(event) \
	switch(event) { \
	case YIELD: \
		goto pos; \
	case BEGIN: \
		break;\
	default: \
		break; \
	} \

#define PT_BLOCK() \
	return 0; \
	pos: \

#define PT_RESUME(p) \
	int event = YIELD; \
	p(&event); \


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
	PT_INIT(event);
	print();
	PT_BLOCK();

	print("running\n");
}

int phread_two(void *arg)
{
	PT_RESUME(phread_one);
	print("running\n");
}

int main()
{
	int event = BEGIN;
	create_phread(phread_one, &event);
	create_phread(phread_two, &event);
	return 0;
}
