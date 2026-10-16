1class Solution {
2public:
3 void merge(vector<int>& nums, int low, int mid, int high) {
4        vector<int> temp;
5
6        int i = low;
7        int j = mid + 1;
8
9        while (i <= mid && j <= high) {
10            if (nums[i] <= nums[j]) {
11                temp.push_back(nums[i]);
12                i++;
13            } else {
14                temp.push_back(nums[j]);
15                j++;
16            }
17        }
18
19        while (i <= mid) {
20            temp.push_back(nums[i]);
21            i++;
22        }
23
24        while (j <= high) {
25            temp.push_back(nums[j]);
26            j++;
27        }
28        
29        for (int k = low; k <= high; k++) {
30            nums[k] = temp[k - low];
31        }
32 }
33
34void divide(vector<int>& nums,int low,int high){
35    if(low>=high)return ;
36    int mid=low+(high-low)/2;
37  divide(nums,low,mid);
38    divide(nums,mid+1,high);
39
40   
41        merge(nums, low, mid, high);
42
43}
44    vector<int> sortArray(vector<int>& nums) {
45         divide(nums, 0, nums.size() - 1);
46        return nums;
47    }
48};