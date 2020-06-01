#include <stdio.h>

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
