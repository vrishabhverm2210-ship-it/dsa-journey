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
15    // base case
16    if(root==NULL)return  0;
17    //  if(root->left==NULL && root->right==NULL)return 1;
18    // now for min case specially 
19    if(root->left==NULL){
20        return  1+fun1(root->right);
21    }
22    if(root->right==NULL){
23        return 1+fun1(root->left);
24    }
25    // if normal case
26    int r1=fun1(root->left);
27    int r2=fun1(root->right);
28    return 1+min(r1,r2);
29}
30    int minDepth(TreeNode* root) {
31        return fun1(root);
32    }
33};