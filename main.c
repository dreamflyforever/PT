#include <stdio.h>

#define print(format, ...) \
	{printf("[%s : %s : %d] ", \
	__FILE__, __func__, __LINE__); \
	printf(format, ##__VA_ARGS__);}

typedef void (*PHREAD_ENTRY) (void *arg);

int resume_phread(void *p)
{

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
	//while (1) {
		//if (condition == 1) {
			print("running\n");
		//}
	//}
}

int phread_two(void *arg)
{
	//while (1) {
		print("running\n");
	//}
}

int main()
{
	int line = __LINE__;
	int condition  = line;
	switch (condition)
	{
	case 5:
		printf("hello world\n");
		break;
	default:
		printf("line: %d\n", line);
		break;
	}
	create_phread(phread_one, NULL);
	create_phread(phread_two, NULL);
	return 0;
}
