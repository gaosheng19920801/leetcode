class Solution {
public:
    //使用滑动窗口，每次检测l到r字符串
    string minWindow(string s, string t) {
        int sLen = s.size(), tLen = t.size();

        //初始化map，存下t中各个字符的个数
        map<char,int> need;
        for(int i =0;i<tLen;i++ )
        {
            need[t[i]]++;
        }
        /*
          l代表左边的下标；
          r代表右边的下标
          start代表第一个t中字符串出现的位置
          count记录当前字符串中还需要的字符个数
        */
        int l = 0, r = 0,start = 0,count = tLen,size = INT_MAX;
        
        while(r<sLen)
        {
            //先移动r，直到包含了t中所有的字符
            if(need[s[r]]>0)//当前字符需要
            {
                count--;
            }

            need[s[r]] --;//将右侧字符放进去，方便后面l移动

            if(count == 0)//当l到r已经包含t
            {
                while(l<r && need[s[l]] < 0)
                {
                    need[s[l]] ++;
                    l++;//l向右移动
                }

                //l到达最左侧包含t的字符位置
                if(r-l+1 < size)
                {
                    size = r-l+1;
                    start = l;
                }

                need[s[l]] ++;
                l++;
                count++;
            }

            r++;
        }

      // printf("%d %d",start,size);

        return size == INT_MAX ? "":s.substr(start,size);
    }
};