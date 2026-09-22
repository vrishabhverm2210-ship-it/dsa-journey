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
13
14public:
15bool isleaf(TreeNode* root){
16    if(root->left==NULL && root->right ==NULL)return true;
17    return false;
18}
19void fun1(TreeNode* root, int targetSum,vector<vector<int>>& res, vector<int>&temp ,int &sum){
20    if(root==NULL)return ;
21
22      sum+=root->val;
23    temp.push_back(root->val);
24    if(isleaf(root)){
25        if(sum==targetSum){
26            res.push_back(temp);
27        }
28    
29            // BACKTRACK
30            sum -= root->val;
31            temp.pop_back();
32
33            return;
34    }
35  
36    fun1(root->left,targetSum,res,temp,sum);
37        fun1(root->right,targetSum,res,temp,sum);
38         sum-=root->val;
39        temp.pop_back();
40     
41        return;
42
43}
44    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
45        vector<vector<int>> res;
46        vector<int>temp;
47        int sum=0;
48        fun1(root,targetSum,res,temp,sum);
49        return res;
50    }
51};