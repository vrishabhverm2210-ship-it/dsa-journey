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
14  TreeNode* fun1(TreeNode* root, int val){
15    // base condition
16    if(root==NULL)return NULL;
17
18    // three condition bnegi
19    if(root->val==val){
20        return root;
21    }
22    else if(root->val>val){
23        return fun1(root->left,val);
24    }
25    return fun1(root->right,val);
26  }
27
28    TreeNode* searchBST(TreeNode* root, int val) {
29        return fun1(root,val);
30    }
31};