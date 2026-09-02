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
14int fun1(TreeNode* root){
15    if(root==NULL)return 0;
16    if(root->left==NULL){
17        return 1+fun1(root->right);
18    }
19      if(root->right==NULL){
20        return 1+ fun1(root->left);
21    }
22
23    return 1+min(fun1(root->left), fun1(root->right));
24
25
26}
27    int minDepth(TreeNode* root) {
28        return fun1(root);
29    }
30};