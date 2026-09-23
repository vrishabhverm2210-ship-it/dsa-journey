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
14
15 void fun1(TreeNode* root, long long targetSum,int &count){
16    if(root==NULL)return ;
17    
18
19        if(targetSum==root->val){
20            count+=1;
21        }
22        fun1(root->left,targetSum-root->val,count);
23      fun1(root->right,targetSum-root->val,count);
24        
25
26    }
27
28    int pathSum(TreeNode* root, int targetSum) {
29        if(root==NULL)return 0;
30        int count=0;
31        int res=0;
32         fun1(root,targetSum,count);
33         
34    
35       count+=pathSum(root->left,targetSum);
36           
37      
38      count+=pathSum(root->right,targetSum);
39            
40return count;
41
42    }
43};