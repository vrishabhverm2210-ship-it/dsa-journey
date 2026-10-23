class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         vector<vector<int>> res; // for storing end answers
         sort(nums.begin(),nums.end());  // 2 sum logic
         for(int idx=0;idx<nums.size()-2;idx++){
            if(idx>0 && nums[idx]==nums[idx-1]) continue;
            int  i=idx+1;
            int j=nums.size()-1;
            while(i<j){
                if(nums[i]+nums[j] == -1 * nums[idx]){
                   res.push_back({nums[idx],nums[i],nums[j]});
                   i++;
                   j--;
                   //for duplicacy
                   while( i<nums.size() &&nums[i]==nums[i-1]){
                    i++;
                   }
                   while( j>=0 &&nums[j] == nums[j+1]){
                    j--;
                   }
                }
              else if(nums[i]+nums[j] > -1 * nums[idx]){
                    j--;
                }
                else{
                    i++;
                }
            }

         }
          return res;
    }
};