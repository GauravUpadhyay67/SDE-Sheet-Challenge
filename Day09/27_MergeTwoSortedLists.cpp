// Problem: Merge Two Sorted Lists
// Link: https://leetcode.com/problems/merge-two-sorted-lists/
// Difficulty: Hard
// Approach: Iterative — dummy node + compare and link
// Time: O(n+m) | Space: O(1)


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* tempHead = new ListNode(-1);
        ListNode* ptr = tempHead;
        ListNode* l1 = list1;
        ListNode* l2 = list2;

        while(l1 && l2){
            if(l1->val <= l2->val){
                ptr->next = l1;
                l1 = l1->next;
                ptr = ptr->next;
                ptr->next = NULL;
            }
            else{
                ptr->next = l2;
                l2 = l2->next;
                ptr = ptr->next;
                ptr->next = NULL;
            }
        }

        if(l1){
            ptr->next = l1;
        }

        if(l2){
            ptr->next = l2;
        }
        
        ptr = tempHead->next;

        tempHead->next = NULL;
        delete(tempHead);
        return ptr;
    }
};
