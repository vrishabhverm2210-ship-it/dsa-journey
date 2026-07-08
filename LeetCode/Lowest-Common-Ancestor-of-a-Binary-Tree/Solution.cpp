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
12 int fun1(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode* &ans ){
13    // must base conditon
14    if(root ==NULL)return 0;
15    int score=0;
16    // go and check in the left part
17   int r1= fun1(root->left,p,q,ans);
18    // go in the right part
19    int r2=fun1(root->right,p,q,ans);
20    // comapre whether the root itself matches or not
21    int self=0;
22    if((root->val == p->val )|| (root->val == q->val)){
23     self=1;
24    }
25    score=r1+r2+self;
26    if(score==2 && ans==NULL){
27        ans=root;
28    }
29   return score; 
30 }
31    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
32        TreeNode* ans=NULL;
33        fun1(root,p,q,ans);
34        return ans;
35    }
36};