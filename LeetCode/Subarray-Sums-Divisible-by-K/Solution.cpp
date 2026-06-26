1class Solution {
2public:
3    int subarraysDivByK(vector<int>& nums, int k) {
4        int res=0;
5        unordered_map<int,int>mpp1;
6        mpp1[0]=1;
7        int sum=0;
8        for(int i=0;i<nums.size();i++){
9          sum+=nums[i];
10          int red=sum%k;
11          if(red<0) red=red+k;
12          int idx=mpp1[red];
13          res+=idx;
14          mpp1[red]++;       
15        }   
16        return res;
17    }
18};