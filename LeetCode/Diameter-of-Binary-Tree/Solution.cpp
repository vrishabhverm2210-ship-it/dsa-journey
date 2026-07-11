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
14int fun1(TreeNode* root, int &res){
15    if(root==NULL)return 0;
16   int r1=  fun1(root->left,res);
17   int r2= fun1(root->right,res);
18   // this for updating the diameter
19   int total=r1+r2;  // this part iss calculatinig the total dhande
20   res=max(total,res);
21// now height vala funxtion chalao
22return 1+max(r1,r2);  // THis for the height function
23}
24    int diameterOfBinaryTree(TreeNode* root) {
25        int res=0;
26        fun1(root,res);
27        return res;
28    }
29};