#include<stdio.h>
#include<string.h>
#define MAX_STRINGS 30


struct  color
{
	char name_color[20];
	int count;
};

int add_element(struct color *clm,const char *buf,int *ptr_num_colors);
int main()
{
	struct color Color[MAX_STRINGS];
	char buf[20];
	int num_colors = 0;

	while(scanf("%19s", buf) != EOF)// buf = "GREEN"
					// num_colors = 2
	{
		int exist = 0;
		for( int i = 0; i < num_colors; i++)// i = 0
			if (strcmp(Color[i].name_color, buf) == 0)
			{
				Color[i].count++;// Color[0].count++
				exist = 1;
			}
		if (!exist)
		{
			if ( add_element(&Color[num_colors], buf, &num_colors))
				break;
			/*if (num_colors >= MAX_STRINGS)
				break;
			strcpy(Color[num_colors].name_color, buf);
			Color[num_colors].count = 1;
			num_colors++;*/
		}
	}
	for(int i = 0; i < num_colors; i++)
		printf("%s %d\n",Color[i].name_color, Color[i].count);
	return 0;
}

int add_element(struct color *clm,const char *buf,int *ptr_num_colors)
{
	if(*ptr_num_colors >= MAX_STRINGS)
		return 1;
	strcpy(clm->name_color,buf);
	clm->count = 1;
	(*ptr_num_colors)++;
	return 0;
}