class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int closest=INT_MAX;   // for differnce 
        int res_sum=0;
        
        
          for(int idx=0;idx<nums.size()-2;idx++){
            int i=idx+1;
            int j=nums.size()-1;
            while(i<j){
            int sum=nums[i]+nums[j]+nums[idx];
             if( abs(sum-target)<closest){
                closest=abs(sum-target);     
                res_sum=sum;
            }
            // if(sum==target){
            //     res_sum=target;
            //     return target;
            // }
            else if(sum>target){
                j--;
            }
            else{
                i++;
            }
           
    }

        }
return res_sum;
    }
};