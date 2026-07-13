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
15TreeNode* fun1(vector<int>& preorder, unordered_map<int,int> &mpp1,int low,int high){
16    // make a base case
17    if(high<low)return NULL;
18    // make a node (SYNTAX)
19    TreeNode* node = new TreeNode(preorder[idx]);  // for now it's left and right child is null
20    idx++;
21    // now search this node from the inorder map
22    int id=mpp1[node->val];  // we got our id from this step
23    // make to call to decide that which part should be proceeseed in right and which to left
24    node->left=fun1(preorder,mpp1,low,id-1);
25    node->right=fun1(preorder,mpp1,id+1,high);
26    return node;
27}
28    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
29        // store inorder traversal in the map
30        unordered_map<int,int>mpp1;
31        for(int i=0;i<inorder.size();i++){
32            mpp1[inorder[i]]=i;
33        }
34        // once store so let's call the function(in which we are traversing the preorder array step by step)
35        int low=0;
36        int high=preorder.size()-1;
37         return  fun1(preorder,mpp1,low,high);
38
39    }
40};