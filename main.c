#include <stdio.h>
#include "pt_label.h"
#include "pt_switch.h"

#define print(format, ...) \
	{printf("[%s : %s : %d] ", \
	__FILE__, __func__, __LINE__); \
	printf(format, ##__VA_ARGS__);}

int phread_one(void *arg)
{
	PT_INIT();
	print("block\n")
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
	PT_DEINIT();
}

int main()
{
	int event = BEGIN;
	PT_CREATE(phread_one, &event);
	PT_CREATE(phread_two, &event);
	return 0;
}
