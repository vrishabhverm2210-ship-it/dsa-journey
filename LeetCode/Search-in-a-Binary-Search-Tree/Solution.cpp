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
14TreeNode* search(TreeNode* root, int val){
15    // base condition
16    if(root==NULL)return NULL;
17    // match the value
18    if(root->val==val){
19        return root;
20    }
21    if(root->val>val){
22      return   search(root->left , val);
23    }
24         return search(root->right,val);
25}
26    TreeNode* searchBST(TreeNode* root, int val) {
27        return search(root,val);
28    }
29};