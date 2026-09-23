1class Solution {
2public:
3    bool containsDuplicate(vector<int>& nums) {
4        unordered_map<int,int>mpp1;
5        for(int i=0;i<nums.size();i++){
6            mpp1[nums[i]]++;
7        }
8        // now check for the frequency in the map
9        for(auto i:mpp1){
10            int freq=i.second;
11            if(freq>=2){
12                return true;
13            }
14        }
15        return false;
16    }
17};