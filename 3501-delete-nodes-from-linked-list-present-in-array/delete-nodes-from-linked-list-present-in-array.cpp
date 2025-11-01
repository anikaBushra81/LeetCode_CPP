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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> removeSet(nums.begin(),nums.end());
        ListNode* dumy=new ListNode(0);
        dumy->next=head;
        ListNode* cur=head;
        ListNode* prev=dumy;

        while(cur)
        {
            if(removeSet.count(cur->val))
            {
                prev->next=cur->next;

            }
            else
            {
                prev=cur;
            }
            cur=cur->next;
        }
        return dumy->next;
    }
};