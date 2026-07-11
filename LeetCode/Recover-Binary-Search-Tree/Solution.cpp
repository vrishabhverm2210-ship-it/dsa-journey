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
14TreeNode* wrong1first=NULL;
15TreeNode* wrong1second=NULL;
16TreeNode* wrong2first=NULL;
17TreeNode* wrong2second=NULL;
18int glt=0;
19void fun1(TreeNode* root ,TreeNode* &prev){
20    if(root==NULL)return;
21    fun1(root->left,prev);
22    if(prev == NULL){
23        prev=root;
24    }
25    else{
26        if(root->val<=prev->val){
27           if(glt==0){
28            wrong1first=prev;
29            wrong1second=root;
30            glt++;
31           }
32           else{
33            wrong2first=prev;
34            wrong2second=root;
35            glt++;
36           }
37        }
38        prev=root;
39    }
40      fun1(root->right,prev);
41}
42    void recoverTree(TreeNode* root) {
43        TreeNode* prev=NULL;
44        fun1(root,prev);
45        if(glt==1){
46        swap(wrong1first->val,wrong1second->val);
47    }
48    else{
49        swap(wrong1first->val,wrong2second->val);
50    }
51
52    }
53};