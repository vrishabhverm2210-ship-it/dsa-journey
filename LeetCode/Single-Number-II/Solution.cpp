1class Solution {
2public:
3    int singleNumber(vector<int>& nums) {
4        int ans=0;
5        // run a loop for all the bits
6        for(int i=0;i<32;i++){
7            int count=0;
8            for(auto x:nums){
9                 // Does x have this bit set?
10
11                if(x&(1<<i)){
12                    count++;
13                }
14            }
15            if(count%3!=0){
16                ans|=(1<<i);
17            }
18        }
19        return ans;
20    }
21};