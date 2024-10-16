#include<stdio.h>
#include<string.h>
#include<math.h>

int main(int argc, char **argv)
{
	char *str[4] = {"sin", "cos", "sqrt", "exp"};
	
	double x;
	int i;
	double (*m[4])(double) = {sin, cos, sqrt, exp};

	if (argc < 3)
	{
		printf("Use; %s func arg_func", argv[0]);
		return 1;
	}
	for(i = 0; i< 4; i++)
	{
		if (!strcmp(argv[1], str[i]))
			break;
	}
	if (i == 4)
	{
		printf("Don't know this fumction\n");
		return 2;
	}
	if (sscanf(argv[2], "%lf", &x)!=1)
		return 3;
	printf("%s(%.2lf) = %.2lf \n", str[i] , x, m[i](x));
	return 0;
}