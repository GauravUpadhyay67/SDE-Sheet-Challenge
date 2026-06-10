// Problem: Add Two Numbers as Linked List
// Link: https://leetcode.com/problems/add-two-numbers/
// Difficulty: Medium
// Approach: Traverse both lists, add digits with carry, build result list
// Time: O(max(n,m)) | Space: O(max(n,m))


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* node = head;
        int rem = 0;

        while(l1 && l2){
            int sum = l1->val + l2->val + rem;
            rem = sum/10;
            ListNode* newNode = new ListNode(sum%10);
            node->next = newNode;
            node = node->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){
            int sum = l1->val + rem;
            rem = sum/10;
            ListNode* newNode = new ListNode(sum%10);
            node->next = newNode;
            node = node->next;
            l1 = l1->next;
        }

        while(l2){
            int sum = l2->val + rem;
            rem = sum/10;
            ListNode* newNode = new ListNode(sum%10);
            node->next = newNode;
            node = node->next;
            l2 = l2->next;
        }

        if(rem){
            node->next = new ListNode(rem);
        }

        return head->next;
    }
};
