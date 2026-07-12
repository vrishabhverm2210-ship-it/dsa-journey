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
14TreeNode*  wrong1first=NULL;
15TreeNode* wrong2first=NULL;
16TreeNode* wrong1second=NULL;
17TreeNode* wrong2second=NULL;
18int count=0;
19void fun1(TreeNode*  root,TreeNode*  &prev){
20    // base case
21    if(root==NULL)return;
22    fun1(root->left,prev);
23    if(prev==NULL){
24        prev=root;
25    }
26    else{  // we have to handle mistake in this case itself
27         if(prev->val>=root->val){
28            if(count==0){
29                wrong1first=prev;
30                wrong1second=root;
31                count++;
32            }
33            else{
34                wrong2first=prev;
35                wrong2second=root;
36                count++;
37            }
38         }
39         prev=root;  // must condition required to maintain the regular flow
40    }
41    fun1(root->right,prev);
42}
43
44    void recoverTree(TreeNode* root) {
45        TreeNode* prev=NULL;
46        fun1(root,prev);
47        if(count==1){
48            // means ek hi wrong pair hai adjacent (normally swap them)
49            swap(wrong1first->val,wrong1second->val);
50        }
51        else{
52            swap(wrong1first->val,wrong2second->val);
53        }
54    }
55};