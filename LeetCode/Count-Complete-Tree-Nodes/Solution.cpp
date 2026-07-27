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
14void fun1(TreeNode* root,vector<int>&res){
15    if(root==NULL)return ;
16    fun1(root->left,res);
17     fun1(root->right,res);
18     res.push_back(root->val);
19}
20    int countNodes(TreeNode* root) {
21        vector<int>res;
22        fun1(root,res);
23        return res.size();
24    }
25};