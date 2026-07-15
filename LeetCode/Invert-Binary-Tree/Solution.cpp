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
14 TreeNode* fun1( TreeNode* root){
15    if(root==NULL)return NULL;
16    swap(root->left,root->right);
17      fun1(root->left);
18      fun1(root->right);
19     return root;
20
21 }
22    TreeNode* invertTree(TreeNode* root) {
23       return fun1(root);
24    }
25};