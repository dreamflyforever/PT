#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define print(format, ...) \
	{printf("[%s : %s : %d] ", \
	__FILE__, __func__, __LINE__); \
	printf(format, ##__VA_ARGS__);}

#define BEGIN 0
#define YIELD 1
#define BLOCK 2

#define POS(token) pos_##token

#define PT_INIT(event) \
	static int token;\
	switch(event) { \
	case YIELD: \
		goto POS(token); \
	case BEGIN: \
		break;\
	default: \
		break; \
	}

#define PT_DEINIT()\
	POS(token):

#define PT_BLOCK() \
	srand(time(NULL)); \
	token = rand();\
	return 0; \
	POS(token):

#define PT_RESUME(p) \
	int e = YIELD; \
	p(&e);

#define PT_CREATE(p, arg) \
	if (p == NULL) { \
		return 0; \
	} \
	p(arg);
