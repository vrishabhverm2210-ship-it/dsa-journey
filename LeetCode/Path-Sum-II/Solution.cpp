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
18void fun1(TreeNode* root, int targetSum, int sum,vector<vector<int>>&ans, vector<int>&temp){
19if(root==NULL)return;
20sum+=root->val;
21temp.push_back(root->val);
22
23 if(isleaf(root)){
24        if(sum==targetSum){
25            ans.push_back(temp);
26        }
27       
28    }
29    fun1(root->left,targetSum,sum,ans,temp);
30     fun1(root->right,targetSum,sum,ans,temp);
31     temp.pop_back();
32}
33
34    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
35        vector<vector<int>>ans;
36        vector<int>temp;
37        int sum=0;
38        fun1(root,targetSum,sum,ans,temp);
39        return ans;
40    }
41};