1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10class Solution {
11public:
12int fun1(TreeNode* root, TreeNode* p, TreeNode* q ,TreeNode* & ans){
13    if(root==NULL)return 0;
14
15    int r1=fun1(root->left,p,q,ans);
16    int r2=fun1(root->right,p,q,ans);   
17    int self=0;
18    if(p->val==root->val || q->val == root->val){
19        self=1;
20    }
21    int total=r1+r2+self;
22    if(total==2 && ans==NULL){
23        ans=root;
24    }
25    return total;
26}
27    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
28        TreeNode*  ans=NULL;
29        fun1(root,p,q,ans);
30        return ans;
31    }
32};