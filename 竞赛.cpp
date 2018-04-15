#include"stdio.h"
#include"string.h"
int main()
{
	char str[255];
	gets(str);
	int length = strlen(str);//length为字符串总长度
	int max = 0;             //max为最大不重复子串的长度
	int i, j, k, l;
	for (i = 0; i < length; i++)
	{
		for (j = i + 1; j < length; j++)
			for (k = i; k < j; k++)
			{
				if (str[k] == str[j])
				{
					l = j;
					j = length;
					k = j;
				}
			}
		if (l - i > max)
			max = l - i;
		if (max == 0)
			max = length;
	}
	printf("%d\n", max);
}

