1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13struct emp{
14    bool operator()( ListNode* &a,  ListNode* &b){
15      return a->val>b->val;
16    }
17};
18    ListNode* mergeKLists(vector<ListNode*>& lists) {
19        // make a min heap
20        priority_queue<ListNode*,vector<ListNode*>,emp>pq;
21
22        for(int i=0;i<lists.size();i++){
23           if(lists[i] != nullptr) {
24            pq.push(lists[i]);
25        }
26        }
27 ListNode*head=NULL;
28  ListNode* tail=NULL;
29
30  while(!pq.empty()){
31    ListNode* node=pq.top();
32    pq.pop();
33    if(node->next!=NULL)pq.push(node->next);
34    if(head==NULL){
35
36        head=node;
37        tail=node;
38    }
39    else{
40        tail->next=node;
41         tail=tail->next;
42    }
43  }
44        return head;
45    }
46};