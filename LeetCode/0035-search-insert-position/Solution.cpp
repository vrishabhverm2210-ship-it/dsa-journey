class Solution {
public:
    int searchInsert(vector<int>& arr, int tar) {
         int n = arr.size();
        int start = 0;
        int end = n - 1;
        int ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == tar) {
                return mid;
            } else if (arr[mid] > tar) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }

        }
        if (ans == -1)
            return n;
        return ans;
    }
};