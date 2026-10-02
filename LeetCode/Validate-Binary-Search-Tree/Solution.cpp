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
16    // base condition
17    if(root==NULL)return;
18    fun1(root->left,prev);
19    // now our main logic
20    if(prev==NULL){
21        prev=root;
22    }
23    else{
24        if(prev->val >= root->val){
25            isvalid=false;
26        }
27        prev=root;
28    }
29    fun1(root->right,prev);
30}
31    bool isValidBST(TreeNode* root) {
32        TreeNode* prev=NULL;
33        fun1(root,prev);
34        return isvalid;
35    }
36};