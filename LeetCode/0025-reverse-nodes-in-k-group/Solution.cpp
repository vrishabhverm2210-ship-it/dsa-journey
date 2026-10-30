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
void reverse(ListNode*  head,int times){
    ListNode* curr=head;
    ListNode* prev=NULL;
    while(times--){
        ListNode* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }

}
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)return NULL;
        ListNode* left=head;
        ListNode* right=NULL;
        ListNode* prevleft=NULL;
        ListNode* res=NULL;
        while(true){
            right=left;
            for(int i=0;i<k-1;i++){
                if(right==NULL)break;
            
            right=right->next;
            }
        // Once we able to find right then normal logic
        if(right){
            ListNode* nextleft=right->next;
            reverse(left,k);
            if(prevleft){
                prevleft->next=right;
            }
            prevleft=left;
            if(res==NULL)res=right; // storing first right for returning the answer

            left=nextleft;
        }
        else{  // right nhi find kr paye
        if(prevleft){
            prevleft->next=left;
        }
        if(res==NULL)res=left;
        break;
  }
       }
        return res;
    }
};