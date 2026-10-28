class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // two loops + two sum
        int n=nums.size();
        sort(nums.begin(),nums.end());

        vector<vector<int>>res;
        for(int idx=0;idx<n-3;idx++){
           if(idx>0 && nums[idx]==nums[idx-1]){
            continue;
           }
           for(int jdx=idx+1;jdx<n-2;jdx++){
              if(jdx>idx+1 && nums[jdx]==nums[jdx-1]){
            continue;
              }
         int i=jdx+1;
         int j=n-1;

         while(i<j){
           long long sum = (long long)nums[idx]+nums[jdx]+nums[i]+nums[j];

            if(sum==target){
                res.push_back({nums[idx],nums[jdx],nums[i],nums[j]});
                i++;
                j--;

                while(i<j && nums[i]==nums[i-1]){
                    i++;
                }
                while(i<j && nums[j]==nums[j+1]){
                    j--;
                }
            }
            else if(sum>target){
                j--;
            }
            else{
                i++;
            }
         }

           }
        }
       
    
    return res;
    }
};