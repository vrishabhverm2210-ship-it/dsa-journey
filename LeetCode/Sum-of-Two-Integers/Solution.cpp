1class Solution {
2public:
3    int getSum(int a, int b) {
4       while(a!=0){
5        int carry=(a&b)<<1;
6        b=a^b;
7        a=carry;
8       }
9       return b;
10    }
11};