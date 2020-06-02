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
#define BLOCK 2

#define PT_INIT() \
	static int event = BEGIN;\
	switch (event) \
	{\
	case BEGIN: \
	{

/*notic: use `\` means on the one line*/
#define PT_BLOCK() \
	}\
		event = __LINE__;\
		break; \
	case __LINE__: \
	{\

#define PT_DEINIT() \
	}\
		break; \
	default:\
		print("event: %d\n", event); \
		break;\
	}

#define PT_RESUME(p) \
	p(NULL);

int phread_one(void *arg)
{
	PT_INIT();
	print("block\n")
	PT_BLOCK();
	print("run\n");
	PT_BLOCK();
	print("run\n");
	PT_DEINIT();
	return 0;
}

int phread_two(void *arg)
{
	PT_INIT();
	print("run\n");
	PT_RESUME(phread_one);
	print("resume\n");
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
