// Problem: Delete Node in a Linked List O(1)
// Link: https://leetcode.com/problems/delete-node-in-a-linked-list/
// Difficulty: Medium
// Approach: Copy next node's value, skip next node
// Time: O(1) | Space: O(1)


class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
