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
12int fun1(TreeNode* root, TreeNode* p, TreeNode* q ,  TreeNode* & ans){
13    // Base condtion
14    if(root==NULL)return 0;
15    // three conditions
16     int r1= fun1(root->left,p,q,ans);
17     int r2=fun1(root->right,p,q,ans);
18    int score=0;
19    if((root->val== p->val) || (root->val == q->val)){
20        score=1;
21    }
22    int total=score+r1+r2;
23    if(total==2 && ans ==NULL){
24        ans=root;
25    }
26    return total;
27}
28    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
29        TreeNode* ans=NULL;
30        fun1(root,p,q,ans);
31        return ans;
32    }
33};