class Solution {
public:
bool isPossible(vector<int>& nums, int k, int mid){
    int count=1;
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(sum>mid){
            count++;
            sum=nums[i];
            if(count>k)return false;
        }
    }
return true;
}
    int splitArray(vector<int>& nums, int k) {
        //  determine the search space
        int low=INT_MIN;
        int high=0;
        for(int i=0;i<nums.size();i++){
            high+=nums[i];
            low=max(low,nums[i]);
        }
     int res=-1;
     while(low<=high){
        int mid=low+(high-low)/2;
        if(isPossible(nums,k,mid)){
            res=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
     }
return res;
    }
};