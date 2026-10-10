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
14    bool operator()(ListNode*  a, ListNode * b){
15    return a->val>b->val;
16    }
17};
18    ListNode* mergeKLists(vector<ListNode*>& lists) {
19        // construct min heap
20        priority_queue<ListNode*,vector<ListNode*>,emp>pq;
21        for(auto i:lists){
22            if(i!=NULL){
23            pq.push(i);
24        }
25        }
26       ListNode* head=NULL;
27             ListNode* tail=NULL;
28        while(!pq.empty()){
29        ListNode* curr=pq.top();
30        pq.pop();
31        if(curr->next!=NULL)pq.push(curr->next);
32        if(head==NULL && tail==NULL){
33            head=curr;
34            tail=curr;
35            continue;
36        }
37        tail->next=curr;
38        tail=curr;
39
40      
41        }
42        return head;
43    }
44};