1class Solution {
2public:
3    int singleNumber(vector<int>& nums) {
4        int n=nums.size();
5        int res=0;
6       for(int i=0;i<32;i++){
7        int count=0;
8        for(auto n:nums){
9            if((n)&1<<i){
10                count++;
11            }
12        }
13        if(count%3!=0){
14           res|=(1<<i);
15        }
16       }
17       return res;
18    }
19};