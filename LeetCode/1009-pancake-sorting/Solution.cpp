
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> res;

        for (int size = n; size > 1; size--) {

            // 1. Find maximum in the unsorted prefix
            int maxi = 0;

            for (int i = 1; i < size; i++) {
                if (arr[i] > arr[maxi]) {
                    maxi = i;
                }
            }

            // 2. Already in the correct position
            if (maxi == size - 1)
                continue;

            // 3. Bring maximum to the front
            if (maxi != 0) {
                reverse(arr.begin(), arr.begin() + maxi + 1);
                res.push_back(maxi + 1);
            }

            // 4. Move maximum to its final position
            reverse(arr.begin(), arr.begin() + size);
            res.push_back(size);
        }

        return res;
    }
};
