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
14void fun1(TreeNode* root, int val,TreeNode* & ans){
15    // base case
16    if(root==NULL)return;
17
18    // normal case
19    if(root->val==val && ans==NULL){
20        ans=root;
21        return;
22    }
23    if(root->val>val){
24        fun1(root->left,val,ans);
25    }
26    else{
27        fun1(root->right,val,ans);
28    }
29return ;
30}
31    TreeNode* searchBST(TreeNode* root, int val) {
32        TreeNode* ans=NULL;
33         fun1(root,val,ans);
34         return ans;
35    }
36};