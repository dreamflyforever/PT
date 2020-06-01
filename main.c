#include "pt.h"

int phread_one(void *arg)
{
	int event = *((int*)arg);
	PT_INIT(event);
	print("blocking\n");
	PT_BLOCK();
	print("running\n");
	return 0;
}

int phread_two(void *arg)
{
	int event = *((int*)arg);
	PT_INIT(event);
	print("running\n");
	PT_RESUME(phread_one);
	print("resume\n");
	PT_DEINIT();
	return 0;
}

int main()
{
	int event = BEGIN;
	PT_CREATE(phread_one, &event);
	PT_CREATE(phread_two, &event);
	return 0;
}
