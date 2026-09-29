1class Solution {
2public:
3    bool isPalindrome(int x) {
4        // if(x<0)return false;
5        int temp=x;
6        long long rev=0;
7        while(temp>0){
8            int digit=temp%10;
9
10            rev=rev*10+digit;
11            temp/=10;
12        }
13        if(rev==x)return true;
14        return false;
15    }
16};