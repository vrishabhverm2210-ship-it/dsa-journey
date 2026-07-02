1class Solution {
2public:
3    int subarraysDivByK(vector<int>& nums, int k) {
4        int sum=0;
5        int count=0;
6        int n=nums.size();
7        unordered_map<int,int>mpp1;
8        mpp1[0]=1;
9        for(int i=0;i<n;i++){
10            sum+=nums[i];
11            int rem=sum%k;
12            if(rem<0){
13               rem= rem+k;
14            }
15            int freq=mpp1[rem];
16            count+=freq;
17            mpp1[rem]++;
18        }
19        return count;
20    }
21};