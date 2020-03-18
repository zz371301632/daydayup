/**
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 输入: "abcabcbb" 输出: 3 输出: 3 
 * 输入: "pwwkew" 输出: 3
 * 输入: "bbbbb" 输出: 1
 **/
#include <stdio.h>
#include <strings.h>

int lengthOfLongestSubstring(char * s){
    int str_length = strlen(s);
    if (str_length == 0)
    {
        return 0;
    }
    int top = 1;
    int bottom = 0;
    int max = 1;

    for (; top < str_length; top++)
    {
        for (int j = bottom; j < top; j++)
        {
            if (s[j] == s[top])
            {
                max =  top - bottom > max ? top - bottom : max;
                bottom = j + 1;
                break;
            }
        }
    }
    return top - bottom > max ? top - bottom : max;
}

int main(){
    char txt[] = "abcabcbb";
    int result = lengthOfLongestSubstring(txt); 
    printf("%d\n",result);
    return 0;
}
