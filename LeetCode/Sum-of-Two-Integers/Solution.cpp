1class Solution {
2public:
3    int getSum(int a, int b) {
4        // rule of thumb XOR FOR SUM WITHOUT CARRY
5        // (A&B)<<1 FOR THE CARRY BIT
6
7            while(a!=0){
8           unsigned int carry=(unsigned int)(a&b)<<1;
9            b=a^b;
10            a=carry;
11            }
12            return b;
13    }
14};