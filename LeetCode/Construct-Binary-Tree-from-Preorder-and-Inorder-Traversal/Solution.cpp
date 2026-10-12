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
14int idx=0; // using this we will traverse the preorder vector
15TreeNode* fun1(vector<int>& preorder ,  unordered_map<int,int>&mpp1 ,int low, int high){
16    // base case
17    if(low>high)return NULL;
18 // create the node
19
20    TreeNode* node = new TreeNode(preorder[idx]);
21    idx++;
22    int id=mpp1[node->val];
23    node->left=fun1(preorder,mpp1,low,id-1);
24    node->right=fun1(preorder,mpp1,id+1,high);
25    return node;
26}
27    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
28      // firstly add all the elements of the inorder array into the mappp with it's index
29      unordered_map<int,int>mpp1;
30      for(int i=0;i<inorder.size();i++){
31        mpp1[inorder[i]]=i;
32      } 
33      return fun1(preorder,mpp1,0,preorder.size()-1);
34    }
35};