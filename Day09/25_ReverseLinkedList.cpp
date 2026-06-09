// Problem: Reverse Linked List
// Link: https://leetcode.com/problems/reverse-linked-list/
// Difficulty: Medium
// Approach: Iterative — 3 pointers (prev, curr, next)
// Time: O(n) | Space: O(1)


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* currNode = head;
        ListNode* prevNode = NULL;
        ListNode* nextNode = head;

        while(currNode){
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;
    }
};
