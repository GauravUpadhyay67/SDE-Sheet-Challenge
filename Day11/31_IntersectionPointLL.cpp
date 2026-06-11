// Problem: Find Intersection Point of Y Linked List
// Link: https://leetcode.com/problems/intersection-of-two-linked-lists/
// Difficulty: Medium
// Approach: Two pointers — when one reaches end, redirect to other list's head
// Time: O(n+m) | Space: O(1)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* h1 = headA;
        ListNode* h2 = headB;
        while(h1 && h2){
            h1 = h1->next;
            h2 = h2->next;
        }

        if(!h1) h1 = headB;
        if(!h2) h2 = headA;

        while(h1 != h2){
            h1 = h1->next;
            h2 = h2->next;

            if(!h1 && !h2) return NULL;
            if(!h1) h1 = headB;
            if(!h2) h2 = headA;
        }
        return h1;

        
    }
};
