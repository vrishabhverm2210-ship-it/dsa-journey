class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);

        // Mark indices that must be unlocked
        for (int i = 0; i < n; i++) {
            int target = nums[i] - 1;
            int left = min(i, target);
            int right = max(i, target);

            if (left != right) {
                diff[left]++;
                diff[right + 1]--;
            }
        }

        int unlocks = 0;
        int active = 0;

        for (int i = 0; i < n; i++) {
            active += diff[i];

            if (active > 0 && locked[i] == 1) {
                unlocks++;
            }
        }

        if (unlocks > k) return -1;

        // Count inversions to find the minimum adjacent swaps
        vector<int> bit(n + 1, 0);
        long long swaps = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = nums[i] - 1; j > 0; j -= j & -j) {
                swaps += bit[j];
            }

            for (int j = nums[i]; j <= n; j += j & -j) {
                bit[j]++;
            }
        }

        return unlocks + swaps;
    }
};