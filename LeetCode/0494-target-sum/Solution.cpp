class Solution {
public:
    int fun1(vector<int>& nums, int target, int idx, vector<vector<int>>& dp) {
        if (idx == 0) {
          
            return target==0;
        }
        if (dp[idx][target] != -1)
            return dp[idx][target];
        if (nums[idx - 1] > target)
            return fun1(nums, target, idx - 1, dp);
        int c1 = fun1(nums, target - nums[idx - 1], idx - 1, dp);
        int c2 = fun1(nums, target, idx - 1, dp);
        return dp[idx][target] = c1 + c2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int range = 0;
        for (int i = 0; i < n; i++) {
            range += nums[i];
        }
        if (abs(target) > range)
            return 0;
        if ((range + target) % 2 != 0)
            return 0;
        int sum = (range + target) / 2;
        vector<vector<int>> dp(n + 1);
        for (int i = 0; i <= n; i++) {
            vector<int> t(sum + 1, -1);
            dp[i] = t;
        }
        return fun1(nums, sum, n, dp);
    }
};