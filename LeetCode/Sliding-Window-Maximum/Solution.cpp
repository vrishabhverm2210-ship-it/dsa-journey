1   
2
3
4class Solution {
5public:
6    // Function to return the max of each sliding window of size k
7    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
8        // Deque to store indices of useful elements in the current window
9        deque<int> dq;
10
11        // Result vector to store the maximums
12        vector<int> result;
13
14        // Loop through each element in the array
15        for (int i = 0; i < nums.size(); i++) {
16            // Remove elements from the front if they are out of this window's range
17            if (!dq.empty() && dq.front() <= i - k) {
18                dq.pop_front();
19            }
20
21            // Remove all elements from the back that are smaller than current element
22            while (!dq.empty() && nums[dq.back()] < nums[i]) {
23                dq.pop_back();
24            }
25
26            // Add the current index to the deque
27            dq.push_back(i);
28
29            // Once the first window is completed, add front element to result
30            if (i >= k - 1) {
31                result.push_back(nums[dq.front()]);
32            }
33        }
34
35        // Return the final result
36        return result;
37    }
38};
39
40
41
42
43
44
45