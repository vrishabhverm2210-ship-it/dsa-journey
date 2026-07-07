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
14    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
15          if(root==NULL)return {};
16        vector<vector<int>> res;
17        queue<TreeNode*>q;
18        q.push(root);
19        bool leftToright=1;
20        while(!q.empty()){
21            int size=q.size();
22            vector<int>temp(size);
23            int start=0;
24            int last=size-1;
25            while(size--){
26                TreeNode* node=q.front();
27                q.pop();
28                if(leftToright==1){
29                 temp[start]=node->val;
30                 start++;
31                }
32                else{
33                 temp[last]=node->val;
34                 last--;
35                }
36                if(node->left !=NULL)q.push(node->left);
37                if(node->right !=NULL)q.push(node->right);
38            }
39          leftToright=1-leftToright;
40            res.push_back(temp);
41        }
42        return res;
43    }
44};