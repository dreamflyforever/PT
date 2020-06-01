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
	}

#define PT_BLOCK() \
	return 0; \
	pos:

#define PT_RESUME(p) \
	int event = YIELD; \
	p(&event);

#define PT_CREATE(p, arg) \
	if (p == NULL) { \
		return 0; \
	} \
	p(arg);
