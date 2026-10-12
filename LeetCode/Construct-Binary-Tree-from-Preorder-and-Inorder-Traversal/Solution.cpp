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
14int idx=0;
15 TreeNode* fun1(vector<int>&preorder,int i,int j,unordered_map<int,int>&mpp1){
16           if(i>j)return NULL;
17         TreeNode* node=new TreeNode(preorder[idx]);
18         int id=mpp1[node->val];
19         idx++;
20         node->left=fun1(preorder,i,id-1,mpp1);
21         node->right=fun1(preorder,id+1,j,mpp1);
22         return node;
23
24 }
25    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
26        unordered_map<int,int>mpp1;
27        for(int i=0;i<inorder.size();i++){
28            mpp1[inorder[i]]=i;
29        }
30        return fun1(preorder,0,preorder.size()-1, mpp1);
31    }
32};