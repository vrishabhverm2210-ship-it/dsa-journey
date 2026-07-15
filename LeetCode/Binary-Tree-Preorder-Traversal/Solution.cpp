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
14//  void preorder(TreeNode* root,  vector<int> &res){
15//     if(root==NULL){
16//         return;
17//     }
18//     res.push_back(root->val);
19//     preorder(root->left,res);
20//      preorder(root->right,res);
21//  }
22    vector<int> preorderTraversal(TreeNode* root) {
23        //  vector<int> res;
24        //  preorder(root , res);
25        //  return res;
26
27
28        // let's do this with morris traversal preorder(minor change hai inorder ke code se)
29         vector<int>res;
30        TreeNode*  curr =root;
31        while(curr != NULL){
32            if(curr ->left==NULL){
33                // if no left child ,print curr, and move to right
34                res.push_back(curr->val);
35                curr=curr->right;
36            }
37            else{ // find [predecessor of current node]
38            TreeNode* prev=curr->left;
39            while(prev->right !=NULL && prev->right!=curr){ // yeh predeccor mai curr vali cdn bhi check krni jruri hai, because nhi krnege toh infinite loop maar jayega
40                prev=prev->right;
41            }
42
43            //now pred. find krlia toh ab temporary link banao
44            if(prev -> right ==NULL){
45                prev->right =curr;
46                res.push_back(curr->val);
47                curr=curr->left;
48            }
49            else{
50                 // links jo temporary banye thai ,unko hatana hai
51                 prev->right=NULL;
52                //  res.push_back(curr->val);
53                 curr=curr->right;
54            }
55
56            }
57        }
58      return res;
59    }
60};