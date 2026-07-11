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
16    if(root->left==NULL && root->right==NULL)return 1;
17    if(root->left==NULL)return 1+fun1(root->right);
18    if(root->right==NULL)return 1+fun1(root->left);
19    // now normalfun
20    int r1=fun1(root->left);
21    int r2=fun1(root->right);
22    return 1+min(r1,r2);
23}
24    int minDepth(TreeNode* root) {
25        return fun1(root);
26    }
27};