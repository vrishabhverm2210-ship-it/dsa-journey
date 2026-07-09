1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14int solve(TreeNode* root, int k ,int& i){
15    if(root==NULL){return -1;}
16    // left 
17    int left=solve(root->left,k,i);
18    if(left!=-1){
19        return left;
20    }
21    i++;
22    if(i==k){return root->val;}
23     // right
24     return solve(root->right,k,i);
25}
26    int kthSmallest(TreeNode* root, int k) {
27        int i=0;
28        int ans=solve(root,k,i);
29     return ans;}
30};