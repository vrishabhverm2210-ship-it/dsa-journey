1/*
2// Definition for a Node.
3class Node {
4public:
5    int val;
6    vector<Node*> neighbors;
7    Node() {
8        val = 0;
9        neighbors = vector<Node*>();
10    }
11    Node(int _val) {
12        val = _val;
13        neighbors = vector<Node*>();
14    }
15    Node(int _val, vector<Node*> _neighbors) {
16        val = _val;
17        neighbors = _neighbors;
18    }
19};
20*/
21
22class Solution {
23public:
24void dfs(Node* &node,unordered_map<Node*,Node*>&mpp1,Node* &clone){
25
26for(int i=0; i<node->neighbors.size(); i++){
27    Node* neigh = node->neighbors[i];
28        if(mpp1.find(neigh)==mpp1.end()){
29            Node* newNode = new Node(neigh->val);
30             mpp1[neigh]=newNode;
31             clone->neighbors.push_back(newNode);
32               dfs(neigh, mpp1, newNode);
33        }
34        else{
35            clone->neighbors.push_back(mpp1[neigh]);
36        }
37    }
38}
39
40    Node* cloneGraph(Node* node) {
41        if(node == NULL) return NULL;
42        unordered_map<Node*,Node*>mpp1;   // original vs clone
43        Node* clone= new Node(node->val);
44      mpp1[node]=clone;
45            dfs(node,mpp1,clone);
46            return clone;
47      
48    }
49};