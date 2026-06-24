1class Solution {
2public:
3    int maxProduct(vector<int>& nums) {
4        
5        int maxi = nums[0];
6        int mini = nums[0];
7        int ans  = nums[0];
8
9        for(int i = 1; i < nums.size(); i++) {
10
11            // If negative number → swap
12            if(nums[i] < 0)
13                swap(maxi, mini);
14
15            maxi = max(nums[i], maxi * nums[i]);
16            mini = min(nums[i], mini * nums[i]);
17
18            ans = max(ans, maxi);
19        }
20
21        return ans;
22    }
23};
24