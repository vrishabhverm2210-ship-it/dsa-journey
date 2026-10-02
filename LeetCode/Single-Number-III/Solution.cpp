1class Solution {
2public:
3    vector<int> singleNumber(vector<int>& nums) {
4        int x=0;
5        for(int num:nums){
6            x^=num;
7        }
8      long long diff=(long long)x & -(long long)x;
9
10      int ans1=0;
11      int ans2=0;
12
13      for(int num:nums){
14        if(diff&num){
15            ans1^=num;
16        }
17        else{
18            ans2^=num;
19        }
20      }
21      return {ans1,ans2};
22    }
23};