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
14TreeNode* getsmall( stack<TreeNode* >&asc){
15    TreeNode * small=asc.top();
16    asc.pop();
17    TreeNode* curr=small->right;
18    while(curr){
19        asc.push(curr);
20        curr=curr->left;
21    }
22    return small;
23}
24    int kthSmallest(TreeNode* root, int k) {
25        stack<TreeNode* >asc;
26        int ans;
27        TreeNode* t=root;
28        while(t){
29            asc.push(t);
30            t=t->left;
31        }
32        while(k--){
33            TreeNode* node=getsmall(asc);
34            ans=node->val;
35        }
36        return ans;
37    }
38};