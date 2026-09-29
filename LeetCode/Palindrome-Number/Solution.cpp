1class Solution {
2public:
3    bool isPalindrome(int x) {
4        long long reversed=0;
5        int temp=x;
6        while(temp>0){
7            int digit=temp%10;
8            reversed=reversed*10+digit;
9            temp=temp/10;
10        }
11        if(x==reversed){
12            return true;
13        }
14        return false;
15    }
16};