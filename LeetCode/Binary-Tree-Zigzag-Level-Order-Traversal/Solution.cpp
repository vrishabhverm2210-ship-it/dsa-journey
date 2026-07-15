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
14bool lefttoright=1;
15    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
16        if (root == NULL)
17    return {};
18        vector<vector<int>> res;
19        queue<TreeNode*>q;
20        q.push(root);
21        while(!q.empty()){
22            int size=q.size();
23            vector<int>temp(size);
24            int start=0;
25            int end=size-1;
26            while(size--){
27                TreeNode* node=q.front();
28                q.pop();
29                if(lefttoright==1){
30                    temp[start]=node->val;
31                    start++;
32                }
33                else{
34                    temp[end]=node->val;
35                    end--;
36                }
37                if(node->left!=NULL)q.push(node->left);
38                if(node->right !=NULL)q.push(node->right);
39            }
40            lefttoright=1-lefttoright;
41            res.push_back(temp);
42        }
43        return res;
44    }
45};