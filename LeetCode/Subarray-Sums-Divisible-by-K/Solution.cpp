1class Solution {
2public:
3    int subarraysDivByK(vector<int>& nums, int k) {
4        // in this case we need remainder instead of the sum only
5        unordered_map<int,int>mpp1;
6        int sum=0;
7    int count=0;
8    mpp1[0]=1;
9    for(int i=0;i<nums.size();i++){
10        sum+=nums[i];
11        // find in map
12        int rem=sum%k;
13        if(rem<0){
14            rem=rem+k;
15        }
16        // now find out the remainder in map
17        if(mpp1.find(rem)!=mpp1.end()){
18            count+=mpp1[rem];
19        }
20        // add this entry in the map for future use also
21        mpp1[rem]++;
22    }
23    return count;
24    }
25};