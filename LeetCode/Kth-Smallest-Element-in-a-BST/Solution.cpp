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
14void inorder(TreeNode* root,TreeNode* &prev, int& k ,int & count){
15    if(root==NULL)return;
16   
17    inorder(root->left,prev,k,count);
18     count++;
19      if(count==k){
20        prev=root;
21    return;
22    }
23    inorder(root->right,prev,k,count);
24}
25    int kthSmallest(TreeNode* root, int k) {
26     TreeNode* prev=NULL;
27     int count=0;
28        inorder(root,prev,k,count);
29        return prev->val;
30    }
31};