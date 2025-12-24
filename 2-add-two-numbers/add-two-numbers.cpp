class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        int c = 0;

        while (l1 != nullptr || l2 != nullptr || c) {
            int sum = c;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            c = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
        }

        return dummy->next;
    }
};
