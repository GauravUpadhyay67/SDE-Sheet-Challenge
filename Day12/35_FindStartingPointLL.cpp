// Problem: Find Starting Point of Loop in LL
// Link: https://leetcode.com/problems/linked-list-cycle-ii/
// Difficulty: Medium
// Approach: Floyd's Cycle Detection — after meeting point, reset one pointer to head
// Time: O(n) | Space: O(1)


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                fast = head;

                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
