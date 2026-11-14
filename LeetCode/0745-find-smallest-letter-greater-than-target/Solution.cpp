class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0;
        // kashvi 2420915

        int high = letters.size() - 1;
        // kashvi 2420915

        int ans = 0;
        // kashvi 2420915

        while (low <= high) {
            int mid = low + (high - low) / 2;
            // kashvi 2420915

            if (letters[mid] > target) {
                ans = mid;
                // kashvi 2420915
                high = mid - 1;
            }
            else {
                low = mid + 1;
                // kashvi 2420915
            }
        }

        return letters[ans];
    }
};