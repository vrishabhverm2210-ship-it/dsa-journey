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
15    if(root->left==NULL && root->right ==NULL)return true;
16    return false;
17}
18void fun1(TreeNode* root, int targetSum,int sum, vector<int> & temp ,  vector<vector<int>>&ans){
19    // base condition
20    if(root==NULL)return ;
21
22       sum+=root->val;
23    temp.push_back(root->val);
24    if(isleaf(root)){
25        if(targetSum==sum){
26            ans.push_back(temp);
27        }
28          temp.pop_back();  // before returning pop jrur kr do
29        return;
30    }
31      fun1(root->left, targetSum , sum,temp,ans);
32        fun1(root->right, targetSum , sum,temp,ans);
33        temp.pop_back();
34      
35}
36    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
37        vector<int>temp;
38        vector<vector<int>>ans;
39        int sum=0;
40        fun1(root, targetSum , sum,temp,ans);
41        return ans;
42    }
43};