// Problem: Rotate Linked List
// Link: https://leetcode.com/problems/rotate-list/
// Difficulty: Hard
// Approach: Find length, make circular, break at (len - k%len - 1)
// Time: O(n) | Space: O(1)


class Solution {
    int lenLL(ListNode* head){
        int len = 0;
        while(head){
            head = head->next;
            len++;
        }
        return len;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;
        
        int n = lenLL(head);
        k %= n;

        if(k == 0) return head;
        ListNode* temp = head;

        while(k--){
            temp = temp->next;
        }

        ListNode* node = head;
        while(temp->next){
            node = node->next;
            temp = temp->next;
        }
        
        temp->next = head;
        head = node->next;
        node->next = NULL;
        return head;
    }
};
