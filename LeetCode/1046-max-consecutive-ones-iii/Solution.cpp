class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zerocnt=0;
        int n=nums.size();
        int low=0;
        int res=0;
        for(int high=0;high<n;high++){
            // now 1st step increase the zero count
            if(nums[high]==0)zerocnt++;
            // now write the shrinking condition we have to shrink when our zerocount exceeds k
            while(zerocnt>k){
                if(nums[low]==0)zerocnt--;
                low++;        
            }
            // now update the length
            int len=high-low+1;
            res=max(res,len);
        }
        return res;
    }
};