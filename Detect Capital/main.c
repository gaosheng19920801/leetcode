#include <stdio.h>
#include <string.h>
/*
给定一个单词，你需要判断单词的大写使用是否正确。

我们定义，在以下情况时，单词的大写用法是正确的：

全部字母都是大写，比如"USA"。
单词中所有字母都不是大写，比如"leetcode"。
如果单词不只含有一个字母，只有首字母大写， 比如 "Google"。
否则，我们定义这个单词没有正确使用大写字母

*/

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