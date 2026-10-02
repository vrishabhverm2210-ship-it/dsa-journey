1class Solution {
2public:
3    int singleNumber(vector<int>& nums) {
4      int ans=0;
5      int n=nums.size();
6      for(int i=0;i<32;i++){
7        int count=0;
8        for(int j=0;j<nums.size();j++){
9            if(nums[j] &(1<<i)){
10                count++;
11            }
12        }
13        if(count%3!=0){
14            ans|=(1<<i);
15        }
16      }  
17      return ans;
18    }
19};