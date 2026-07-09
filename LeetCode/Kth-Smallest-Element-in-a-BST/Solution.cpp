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
14TreeNode* getsmall(stack<TreeNode*>& asc) {
15    TreeNode* small = asc.top();
16    asc.pop();
17
18    TreeNode* curr = small->right;
19
20    while (curr) {
21        asc.push(curr);
22        curr = curr->left;
23    }
24
25    return small;
26}
27    int kthSmallest(TreeNode* root, int k) {
28        int ans;
29        stack<TreeNode*>asc;
30        TreeNode*t=root;
31        while(t){
32            asc.push(t);
33            t=t->left;
34        }
35        while(k--){
36          TreeNode* node=getsmall(asc);
37          ans=node->val;   
38        }
39         return ans;
40    }
41};