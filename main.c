#include <stdio.h>

#define print(format, ...) \
	{printf("[%s : %s : %d] ", \
	__FILE__, __func__, __LINE__); \
	printf(format, ##__VA_ARGS__);}

int phread_one()
{
	print("running\n");
}

int phread_two()
{
	print("running\n");
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
	return 0;
}
