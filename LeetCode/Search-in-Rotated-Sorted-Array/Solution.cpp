1class Solution {
2public:
3    int findpivot(const vector<int>& nums, int n) {
4        int s = 0;
5        int e = n - 1;
6        // If array is already sorted (no rotation)
7        if (nums[s] <= nums[e]) {
8            return 0;
9        }
10        while (s < e) {
11            int mid = s + (e - s) / 2;
12            if (nums[mid] > nums[e]) {
13                // pivot is to right of mid
14                s = mid + 1;
15            } else {
16                // pivot is at mid or to left of mid
17                e = mid;
18            }
19        }
20        return s;
21    }
22
23    int binarySearch(const vector<int>& nums, int start, int end, int target) {
24        int s = start;
25        int e = end;
26        while (s <= e) {
27            int mid = s + (e - s) / 2;
28            if (nums[mid] == target) {
29                return mid;
30            } else if (nums[mid] > target) {
31                e = mid - 1;
32            } else {
33                s = mid + 1;
34            }
35        }
36        return -1;
37    }
38
39    int search(vector<int>& nums, int target) {
40        int n = nums.size();
41        if (n == 0) return -1;
42
43        int pivot = findpivot(nums, n);
44
45        // if pivot element is the target
46        if (nums[pivot] == target) {
47            return pivot;
48        }
49
50       if (pivot == 0) {
51    return binarySearch(nums, 0, n - 1, target);
52}
53
54if (target >= nums[0]) {
55    // target in left sorted part
56    return binarySearch(nums, 0, pivot - 1, target);
57} else {
58    // target in right sorted part
59    return binarySearch(nums, pivot, n - 1, target);
60}
61
62}
63    
64};
65
66