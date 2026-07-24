1class Solution {
2public:
3    bool checkSubarraySum(vector<int>& nums, int k) {
4        // in this we will store the remainder in the hashmap but with it's index
5   unordered_map<int,int>mpp1;
6        int sum=0;
7        mpp1[0]=-1;
8    for(int i=0;i<nums.size();i++){
9        sum+=nums[i];
10        // find in map
11        int rem=sum%k;
12        if(rem<0){
13            rem=rem+k;
14        }
15        // now find out the remainder in map
16        if(mpp1.find(rem)!=mpp1.end()){
17          // means we found the remainder
18          if(i-mpp1[rem] >=2)return true;
19        }
20        // add this entry in the map for future use also
21       
22       else {
23        mpp1[rem]=i;
24        }
25    }
26    return false;
27    }
28};