#include <stdio.h>
#include <string.h>

bool detectCapitalUse(char * word){
	int len = 0,i = 0,capital_num = 0,lower_num = 0;

	if (NULL == word)
		return false;

	len = strlen(word);

	if (0x41 <= word[0] && word[0] <= 0x5a)//大写
	{
		if(len < 2)
			return true;

		for(i = 1;i<len;i++)
		{
			if (0x41 <= word[i] && word[i] <= 0x5a)
				capital_num++;
			else  if (0x61 <= word[i] && word[i] <= 0x7a)
				lower_num++;
			else
				return false;
		}
		if (capital_num == len -1 || lower_num == len-1)
			return true;
		else
			return false;

	}
	else if (0x61 <= word[0] && word[0] <= 0x7a)//小写
	{
		if(len < 2)
			return true;

		for(i = 1;i<len;i++)
		{
			if (0x61 <= word[i] && word[i] <= 0x7a)
				continue;
			else
				return false;
		}

		return true;
	}
	else
		return false;

}


int main()
{
	detectCapitalUse("USA");

	strlen("pause");
	return true;
}