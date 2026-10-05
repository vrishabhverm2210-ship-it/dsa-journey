1class Solution {
2public:
3    int reverseBits(int n) {
4        int ans=0;
5        for(int i=0;i<32;i++){
6            int bit=(n&1);
7            ans=(ans<<1)|bit;
8            n=n>>1;
9        }
10        return ans;
11    }
12};