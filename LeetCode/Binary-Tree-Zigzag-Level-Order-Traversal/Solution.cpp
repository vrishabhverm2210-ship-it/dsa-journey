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
15         if (root == NULL)
16    return {};
17         vector<vector<int>> res;
18         queue<TreeNode*>q;
19         q.push(root);
20         int lefttoright=1;
21         while(!q.empty()){
22            int size=q.size();
23            vector<int>temp(size,0);
24            int start=0;
25            int end=size-1;
26            
27            while(size--){
28                TreeNode* node=q.front();
29                q.pop();
30                if(lefttoright==1){
31                    temp[start]=node->val;
32                    start++;
33                }
34                else {
35                    temp[end]=node->val;
36                    end--;
37                }
38
39                // now push the left child and the right child
40                if(node->left!=NULL)q.push(node->left);
41                if(node->right!=NULL)q.push(node->right);
42
43            }
44            lefttoright=1-lefttoright;
45            res.push_back(temp);
46                     }
47                     return res;
48         
49    }
50};