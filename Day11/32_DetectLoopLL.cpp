// Problem: Detect a Loop in Linked List
// Link: https://leetcode.com/problems/linked-list-cycle/
// Difficulty: Medium
// Approach: Floyd's Cycle Detection — slow & fast pointer
// Time: O(n) | Space: O(1)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        ListNode* slow = head;
        ListNode* fast = head;

        do{
            slow = slow->next;
            if(fast) fast = fast->next;
            if(!slow || !fast) return false;
            fast = fast->next;            
        }while(slow != fast);
        return true;
    }
};
