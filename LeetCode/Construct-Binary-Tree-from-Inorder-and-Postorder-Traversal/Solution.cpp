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
14TreeNode* fun1(vector<int>& postorder,unordered_map<int,int> &mpp1,int low,int high,int &idx){
15    if(low>high)return NULL;
16TreeNode* node=new TreeNode(postorder[idx]);
17idx--;
18int id=mpp1[node->val];
19node->right=fun1(postorder,mpp1,id+1,high,idx);
20node->left=fun1(postorder,mpp1,low,id-1,idx);
21
22
23return node;
24}
25    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
26        unordered_map<int,int>mpp1;
27        for(int i=0;i<inorder.size();i++){
28            mpp1[inorder[i]]=i;
29        }
30        int idx=postorder.size()-1;
31         return fun1(postorder,mpp1,0,inorder.size()-1,idx);
32    }
33};