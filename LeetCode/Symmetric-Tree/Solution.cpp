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
14bool fun1(TreeNode* p , TreeNode* q){
15    if(p == NULL && q ==NULL)return true;
16    if(p ==NULL || q==NULL)return false;
17    if(p->val != q->val)return false;
18    // now make recursive call as we are treating one tree as two tree on basis of its left and right chlid
19    bool r1=fun1(p->left, q->right);  // mirror condition
20    bool r2=fun1(p->right,q->left);
21    if(r1==true && r2== true)return true;
22    return false;
23}
24    bool isSymmetric(TreeNode* root) {
25        return fun1(root->left,root->right);
26    }
27};