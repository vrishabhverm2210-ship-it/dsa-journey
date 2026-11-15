class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        int i=0;
        int count=1;
        for(int j=1;j<n;j++){
               if(nums[i] == nums[j]  && count<2){
                i++;
                nums[i]=nums[j];
                count++;
            }
            else if(nums[i] != nums[j]){
                i++;
                nums[i]=nums[j];
                count=1;
            } 
        }
        return i+1;

    }
};