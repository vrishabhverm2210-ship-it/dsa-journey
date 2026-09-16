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
16    // basic idea is that we will calculate the max height of both left and right part and we will add it for the resultant diameter
17    int left=fun1(root->left,res);
18    int right=fun1(root->right,res);
19    int total=left+right;
20    res=max(res,total);
21    return 1+max(left,right);
22    
23}
24    int diameterOfBinaryTree(TreeNode* root) {
25        int res=0;
26         fun1(root,res);
27         return res;
28        
29    }
30};