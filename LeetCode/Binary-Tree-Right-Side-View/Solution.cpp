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
14    vector<int> rightSideView(TreeNode* root) {
15        if(root==NULL)return {};
16            queue<TreeNode*>q;
17            vector<int>res;
18            q.push(root);
19            while(!q.empty()){
20                int size=q.size();
21                vector<int>temp(size);
22                int low=0;
23                int high=size-1;
24                while(size--){
25               TreeNode* node=q.front();
26                q.pop();
27                temp[low]=node->val;
28                low++;
29                if(node->left)q.push(node->left);
30                if(node->right)q.push(node->right);
31                }
32                res.push_back(temp[high]);
33            }
34           return res;
35    }
36};