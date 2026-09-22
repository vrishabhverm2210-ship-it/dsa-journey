1class Solution {
2public:
3int fun1(int n){
4    int temp=n;
5    int res=0;
6    while(temp>0){
7        int digit=temp%10;
8        res+=digit*digit;
9        temp/=10;
10    }
11    return res;
12}
13    bool isHappy(int n) {
14        int slow=n;
15        int fast=n;
16        while(fast!=1){
17          slow=fun1(slow);
18          fast=fun1(fun1(fast));
19          if ( slow!=1 && slow == fast){
20            return false;
21          }
22        }
23        return true;
24    }
25};