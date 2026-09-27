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
14void fun1(TreeNode* root, long long targetSum,long long &sum,int &count){
15    if(root==NULL)return ;
16    sum+=root->val;
17    if(sum==targetSum) count+=1;
18    
19    fun1(root->left,targetSum,sum,count);
20    fun1(root->right,targetSum,sum,count);
21     sum-=root->val;
22
23}
24    int pathSum(TreeNode* root, int targetSum) {
25        if(root==NULL)return 0 ;
26
27      int count=0;
28        long long sum=0;
29        fun1(root,targetSum,sum,count);
30
31       count+=pathSum(root->left,targetSum);
32       count+=pathSum(root->right,targetSum);
33       return count;
34
35
36    }
37};