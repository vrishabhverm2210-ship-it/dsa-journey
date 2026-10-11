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
14bool isleaf(TreeNode* root){
15    if(root->left==NULL && root->right==NULL)return true;
16    return false;
17}
18void fun1(TreeNode* root, int targetSum,int& sum, vector<vector<int>>& res,vector<int>&temp){
19    if(root==NULL)return ;
20    sum+=root->val;
21    temp.push_back(root->val);
22  
23    if(isleaf(root)){
24        if(sum==targetSum){
25            res.push_back(temp);
26        }
27        sum-=root->val;
28        temp.pop_back();
29        return ;
30    }
31      fun1(root->left,targetSum,sum,res,temp);
32        fun1(root->right,targetSum,sum,res,temp);
33   sum-=root->val;
34        temp.pop_back();
35
36}
37    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
38           vector<vector<int>> res;
39           vector<int>temp;
40           int sum=0;
41           fun1(root,targetSum,sum,res ,temp);
42           return res;
43    }
44};