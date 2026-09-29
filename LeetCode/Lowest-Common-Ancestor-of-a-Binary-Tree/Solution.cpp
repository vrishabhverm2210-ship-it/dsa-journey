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
12TreeNode*ans =NULL;
13int fun1(TreeNode* root, TreeNode* p, TreeNode* q){
14    if(root==NULL)return 0;
15
16    int left=fun1(root->left,p,q);
17    
18    int right=fun1(root->right,p,q);
19    int self=0;
20    if(root->val==p->val   || root->val==q->val ){
21        self=1;
22    }
23    int total=left+right+self;
24
25    if(total==2 && ans==NULL)ans=root;
26    return left+right+self;
27
28}
29    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
30        
31        fun1(root,p,q);
32        return ans;
33    }
34};