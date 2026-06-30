1/*
2// Definition for a Node.
3class Node {
4public:
5    int val;
6    Node* next;
7    Node* random;
8    
9    Node(int _val) {
10        val = _val;
11        next = NULL;
12        random = NULL;
13    }
14};
15*/
16
17class Solution {
18public:
19void insertAtTail( Node*& head,Node* &tail,int temp){
20   Node* newNode=new Node(temp);
21   if(head==NULL){
22    head=newNode;
23    tail=newNode;
24    return;
25   }
26   else{
27    tail->next=newNode;
28    tail=newNode;
29   }
30}
31    Node* copyRandomList(Node* head) {
32        // Create a clone list
33       Node* cloneHead=NULL;
34       Node* cloneTail=NULL;
35       Node * temp=head;
36       while(temp !=NULL){
37        insertAtTail(cloneHead,cloneTail,temp->val);
38        temp=temp->next;
39       }
40       // create a map
41       map<Node*,Node*>oldToNewNode;
42      Node* originalNode=head;
43      Node * cloneNode= cloneHead;
44
45      while(originalNode !=NULL && cloneNode !=NULL){
46        oldToNewNode[originalNode]=cloneNode;
47        originalNode=originalNode->next;
48        cloneNode=cloneNode->next;
49      }
50        // Ab random vaale ko point karao
51        // reset again
52        originalNode=head;
53        cloneNode=cloneHead;
54
55        while(originalNode != NULL){
56            cloneNode->random=oldToNewNode[originalNode->random];
57              originalNode=originalNode->next;
58        cloneNode=cloneNode->next;
59        }
60      
61      return cloneHead;
62    }
63};