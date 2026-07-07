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
14void fun(TreeNode* root,vector<int>&res){
15    if(root==NULL){
16        return;
17    }
18    // three steps we have to follow
19    res.push_back(root->val);
20    fun(root->left,res);
21    fun(root->right,res);
22}
23    vector<int> preorderTraversal(TreeNode* root) {
24         vector<int>res;
25         fun(root,res);
26         return res;
27    }
28};