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
14void inorder(TreeNode* root, vector<int>&temp){
15    if(root==NULL)return;
16    inorder(root->left,temp);
17    temp.push_back(root->val);
18    inorder(root->right,temp);
19}
20    int kthSmallest(TreeNode* root, int k) {
21        vector<int>temp;
22        inorder(root,temp);
23        return temp[k-1];
24    }
25};