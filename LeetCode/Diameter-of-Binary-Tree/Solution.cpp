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
14int fun1(TreeNode* root,int &res){
15    if(root==NULL)return 0;
16    int left=fun1(root->left,res);
17    int right=fun1(root->right,res);
18            int total=left+right;
19    res=max(res,total);
20    return 1+max(left,right);
21}
22    int diameterOfBinaryTree(TreeNode* root) {
23        int res=0;
24      fun1(root,res);
25        return res;
26    }
27};