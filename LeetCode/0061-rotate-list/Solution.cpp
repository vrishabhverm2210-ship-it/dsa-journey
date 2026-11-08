/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)return NULL;
          int count=1;
            ListNode * last=head;
            while(last->next!=NULL){
                count++;
                last=last->next;
            }
            k=k%count;
            if(k==0)return head; // no need of rotation
            // LET'S CALCULATE (COUNT-K)TH TERM
            int times=count-k-1; 
              ListNode * node=head;
            while(times--){
               node=node->next;
            }
            // now do connections
            last->next=head;
              ListNode *newhead=node->next;
              node->next=NULL;
              return newhead;
    }
};