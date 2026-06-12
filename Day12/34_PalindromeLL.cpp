// Problem: Check if Linked List is Palindrome
// Link: https://leetcode.com/problems/palindrome-linked-list/
// Difficulty: Medium
// Approach: Find middle, reverse second half, compare both halves
// Time: O(n) | Space: O(1)


class Solution {
    ListNode* reverseLL(ListNode* currNode){
        ListNode* prevNode = NULL;

        while(currNode){
            ListNode* nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;

    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* l1 = head;
        ListNode* l2 = reverseLL(slow);

        while(l1 && l2){
            if(l1->val != l2->val){
                return false;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        return true;
    }
};
