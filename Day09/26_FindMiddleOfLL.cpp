// Problem: Find Middle of Linked List
// Link: https://leetcode.com/problems/middle-of-the-linked-list/
// Difficulty: Easy
// Approach: Slow & Fast pointer (Tortoise & Hare)
// Time: O(n) | Space: O(1)


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
        }
        return slow;
    }
};
