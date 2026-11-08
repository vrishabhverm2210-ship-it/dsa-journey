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
        int count=1;
        if(head==NULL)return NULL;
         ListNode* temp=head;
         while(temp->next!=NULL){
            temp=temp->next;
            count++;
         }
         int rotate=k%count;
         if(rotate==0)return head;
         int times=count - rotate-1;
          ListNode* curr=head;
         while(times--){
          curr=curr->next;
         }
 ListNode* next1=curr->next;
         temp->next=head;
         curr->next=NULL;
         return next1;
         
    }
};