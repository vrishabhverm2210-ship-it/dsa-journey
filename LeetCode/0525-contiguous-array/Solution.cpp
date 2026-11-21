class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mpp1;
        int n=nums.size();
        int diff;
        int onecount=0;
        int zerocount=0;
        int res=INT_MIN;
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1)onecount++;
            else zerocount++;
            diff=onecount-zerocount;
            if(diff==0)res=max(res,i+1);  // if 0 and 1 are of equal proportion
            if(mpp1.find(diff) == mpp1.end()){
               mpp1[diff]=i;
            }
            else{ // means if diff mil gya
            int indx=mpp1[diff];
            count=i-indx;
            res=max(res,count);
            // mpp1[diff]=i;  
            }

        }
        if(res==INT_MIN)return 0;
        return res;
    }
};
