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
15        if(root==NULL)return {};
16        bool lefttoright=1; 
17        queue<TreeNode*>q;
18        q.push(root);
19        vector<vector<int>>res;
20        while(!q.empty()){
21            int size=q.size();
22            vector<int>temp(size);
23            int start=0;
24            int end=size-1;
25            while(size--){
26                TreeNode* node=q.front();
27                q.pop();
28                // check the left to right condition
29                if(lefttoright==1){
30                    temp[start]=node->val;
31                    start++;
32                }
33                else{
34                    temp[end]=node->val;
35                    end--;
36                }
37                // insert their childrens
38                if(node->left !=NULL)q.push(node->left);
39                if(node->right !=NULL)q.push(node->right);
40            }
41            lefttoright=1-lefttoright;
42            res.push_back(temp);
43
44        }
45        return res;
46    }
47};