1class Solution {
2public:
3    int subarraysDivByK(vector<int>& nums, int k) {
4        int sum=0;
5        unordered_map<int,int>mpp1;
6        mpp1[0]=1;
7        int count=0;
8        for(int i=0;i<nums.size();i++){
9            sum+=nums[i];
10            int red=sum%k;
11            if(red<0)red=red+k;   // for handling negative no modulus
12            // int freq=mpp1[red];
13            count+=mpp1[red];  // jitni bhi hogi freq vo total answer hoga
14
15            mpp1[red]++;  // because hum remainder store kr re hain
16        }
17        return count;
18    }
19};