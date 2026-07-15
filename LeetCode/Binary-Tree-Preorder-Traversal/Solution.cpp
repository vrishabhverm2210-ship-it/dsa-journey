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
14 void preorder(TreeNode* root,  vector<int> &res){
15    if(root==NULL){
16        return;
17    }
18    res.push_back(root->val);
19    preorder(root->left,res);
20     preorder(root->right,res);
21 }
22    vector<int> preorderTraversal(TreeNode* root) {
23         vector<int> res;
24         preorder(root , res);
25         return res;
26    }
27};