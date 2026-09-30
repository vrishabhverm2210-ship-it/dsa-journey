1class Solution {
2public:
3    int hammingWeight(int n) {
4        int count=0;
5        while(n>0){
6            int bit=n&1;
7            if(bit==1)count++;
8             n=n>>1;
9        }
10        return count;
11    }
12};   