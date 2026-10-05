1class Solution {
2public:
3    int reverseBits(int n) {
4        int ans=0;
5        for(int i=0;i<32;i++){
6            int bit=n&1;
7
8            ans=(ans<<1)|bit;
9            n=n>>1;
10        }
11        return ans;
12     
13    }
14};