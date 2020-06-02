#include <stdio.h>

#define print(format, ...) \
	{printf("[%s : %s : %d] ", \
	__FILE__, __func__, __LINE__); \
	printf(format, ##__VA_ARGS__);}

#define PT_CREATE(p, arg) \
	if (p == NULL) { \
		return 0; \
	} \
	p(arg);

#define BEGIN 0
#define YIELD 1
#define BLOCK 2

#define PT_INIT(event) \
	switch (event) \
	{\
	case BEGIN: \
	{

#define PT_BLOCK() \
	}\
	case BLOCK: \
		return 0; \
	case YIELD: \
	{\

#define PT_DEINIT() \
	}\
		break; \
	}

#define PT_RESUME(p) \
	int _e = YIELD;\
	p(&_e);

int phread_one(void *arg)
{
	int e = *((int *)arg);
	PT_INIT(e);
	print("block\n")
	PT_BLOCK();
	print("run\n");
	PT_DEINIT();
	return 0;
}

int phread_two(void *arg)
{
	int e = *((int *)arg);
	PT_INIT(e);
	print("run\n");
	PT_RESUME(phread_one);
	print("resume\n");
	PT_DEINIT();
}

int main()
{
	int event = BEGIN;
	PT_CREATE(phread_one, &event);
	PT_CREATE(phread_two, &event);
	return 0;
}
