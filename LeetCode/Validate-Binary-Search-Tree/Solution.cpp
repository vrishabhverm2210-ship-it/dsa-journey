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
14bool isvalid=true;
15void fun1(TreeNode* root, TreeNode* &prev){
16    // base case
17    if(root==NULL)return ;
18    // left call
19    fun1(root->left,prev);
20    // main condition to check
21    if(prev==NULL){
22        prev=root;
23    }
24    else{
25        if(prev->val>=root->val){
26            isvalid=false;
27        }
28        prev=root;
29    }
30    fun1(root->right,prev);
31}
32    bool isValidBST(TreeNode* root) {
33        TreeNode* prev=NULL;
34        fun1(root,prev);
35        return isvalid;
36    }
37};