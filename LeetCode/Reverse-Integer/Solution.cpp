1class Solution {
2public:
3    int reverse(int x) {
4        int ans=0;
5        while(x!=0){
6            int digit = x%10;
7        if((ans>INT_MAX/10)||(ans<INT_MIN/10)){
8                return 0;
9
10            }
11            ans=(ans*10)+digit;
12            x=x/10;
13        }
14        return ans;
15    }
16};