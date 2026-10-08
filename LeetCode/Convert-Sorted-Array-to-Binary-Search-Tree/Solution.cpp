1class Solution {
2public:
3    TreeNode* solve(vector<int>& nums, int left, int right) {
4
5        if(left > right)
6            return NULL;
7
8        int mid = left + (right - left) / 2;
9
10        TreeNode* root = new TreeNode(nums[mid]);
11
12        root->left = solve(nums, left, mid - 1);
13        root->right = solve(nums, mid + 1, right);
14
15        return root;
16    }
17
18    TreeNode* sortedArrayToBST(vector<int>& nums) {
19        return solve(nums, 0, nums.size() - 1);
20    }
21};