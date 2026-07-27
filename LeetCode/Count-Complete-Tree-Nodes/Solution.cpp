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
14int fun1(TreeNode* root){
15    TreeNode* temp=root;
16    int h=0;
17    while(temp){
18       h++;
19       temp=temp->left;
20           }
21           return h;
22}
23int fun2(TreeNode* root){
24    TreeNode* temp=root;
25    int h=0;
26    while(temp){
27       h++;
28       temp=temp->right;
29           }
30           return h;
31}
32// int fun3(TreeNode* root){
33//     if(root==NULL)return 0;
34//     int left=fun3(root->left);
35//     int right=fun3(root->right);
36//     return 1+left+right;
37// }
38    int countNodes(TreeNode* root) {
39        if(root==NULL)return 0;
40        // use complete binary tree property
41        int lh=fun1(root);
42        int rh=fun2(root);
43       
44
45       // if lh == rh (means jo hmara tree hai vo complete hain puri tarah se toh hum O(1) mai nikal skte hain)
46       if(lh==rh){
47        return (1 << lh) -1;
48       }
49       // else normal method
50       return 1+countNodes(root->left)+countNodes(root->right);
51    }
52};