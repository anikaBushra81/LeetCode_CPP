class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        ListNode* tmp = head;
        int n = 1;
        while (tmp->next) {
            tmp = tmp->next;
            n++;
        }

        tmp->next = head;

        k = k % n;

        int steps = n - k;
        ListNode* newTail = head;
        for (int i = 1; i < steps; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;

        newTail->next = NULL;

        return newHead;
    }
};