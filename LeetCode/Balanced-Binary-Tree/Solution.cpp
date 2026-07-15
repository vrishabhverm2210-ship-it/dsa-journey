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
14bool isbalance=true;
15int fun1(TreeNode* root){
16    if(root==NULL)return 0;
17    int r1=fun1(root->left);
18    int r2=fun1(root->right);
19   if(abs(r1-r2)>1){
20    isbalance=false;
21   }
22   return 1+max(r1,r2);
23}
24    bool isBalanced(TreeNode* root) {
25        fun1(root);
26        return isbalance;
27    }
28};