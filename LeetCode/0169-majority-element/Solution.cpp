class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ans1=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(cnt==0){
                ans1=nums[i];
                cnt++;
                continue;
            }
            if(ans1==nums[i]){
                cnt++;
            }
            else{
            cnt--;
            }
        }
        return ans1;
    }
};