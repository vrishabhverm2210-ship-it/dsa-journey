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
12int fun1(TreeNode*root, TreeNode* p, TreeNode* q,TreeNode* &ans){
13    if(root==NULL)return 0;
14    int score1=fun1(root->left,p,q,ans);
15    int score2=fun1(root->right,p,q,ans);
16    int self=0;
17    if(root->val==p->val || root->val ==q->val){
18        self=1;
19    }
20    int total=score1+score2+self;
21    if(total==2 && ans==NULL){
22        ans=root;
23    }
24    return total;
25}
26    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
27         TreeNode* ans=NULL;
28         fun1(root,p,q,ans);
29         return ans;
30    }
31};