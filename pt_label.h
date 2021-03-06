#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*protothread status*/
#define BEGIN 0
#define YIELD 1
#define BLOCK 2

/*the position of label*/
#define POS(token) pos_##token

/*for debug info*/
/*#pragma message(POS(token))*/

/*protothread start*/
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

/*prothread end*/
#define PT_DEINIT()\
	POS(token):

/*protothread wait*/
#define PT_BLOCK() \
	srand(time(NULL)); \
	token = rand();\
	return BLOCK; \
	POS(token):

/*protothread resume*/
#define PT_RESUME(p) \
	int e = YIELD; \
	p(&e);

/*prothread create*/
#define PT_CREATE(p, arg) \
	if (p == NULL) { \
		return 0; \
	} \
	p(arg);
