class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int res=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                 res=mid;
                 high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        if(res==-1)return n;
        return res;
    }
};