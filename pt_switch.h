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

