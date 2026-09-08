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
14bool fun1(TreeNode* root1,TreeNode* root2){
15    if(root1==NULL && root2==NULL)return true;
16    if(root1==NULL || root2==NULL)return false;
17    if(root1->val!=root2->val)return false;
18    // fun call
19    bool b1=fun1(root1->left,root2->right);
20    bool b2=fun1(root1->right,root2->left);
21    if(b1&&b2)return true;
22    return false;
23}
24    bool isSymmetric(TreeNode* root) {
25        return fun1(root->left,root->right);
26    }
27};