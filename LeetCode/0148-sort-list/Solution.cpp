
class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* head = NULL;
        ListNode* tail = NULL;

        while (a && b) {
            ListNode* node;

            if (a->val < b->val) {
                node = new ListNode(a->val);
                a = a->next;
            } else {
                node = new ListNode(b->val);
                b = b->next;
            }

            if (head == NULL) {
                head = tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
        }

        while (a) {
            ListNode* node = new ListNode(a->val);

            if (head == NULL) {
                head = tail = node;
            } else {
                tail->next = node;
                tail = node;
            }

            a = a->next;
        }

        while (b) {
            ListNode* node = new ListNode(b->val);

            if (head == NULL) {
                head = tail = node;
            } else {
                tail->next = node;
                tail = node;
            }

            b = b->next;
        }

        return head;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = NULL;

        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        return merge(left, right);
    }
};
