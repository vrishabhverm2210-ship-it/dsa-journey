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
12TreeNode*  solve(TreeNode* root, TreeNode* p, TreeNode* q){
13    // base case
14    if(root==NULL){
15        return NULL;
16    }
17    if(root==p || root==q){   // p and q are pointers (we can only compare them with 
18        return root;
19    }
20    TreeNode* leftans=solve(root->left,p,q);
21     TreeNode* rightans=solve(root->right,p,q);
22     // make 4 cases
23     if(leftans!=NULL && rightans!=NULL){
24        return root;
25     }
26     else if(leftans!=NULL &&rightans==NULL){
27        return leftans;
28     }
29      else if(leftans==NULL &&rightans!=NULL){
30        return rightans;
31     }
32     else{
33        return NULL;
34     }
35    
36}
37    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
38       return solve(root,p,q); 
39    }
40};