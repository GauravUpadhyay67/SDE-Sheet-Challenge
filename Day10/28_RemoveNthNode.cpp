// Problem: Remove Nth Node From End of List
// Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Difficulty: Medium
// Approach: Two pointers — move fast pointer N steps ahead, then move both
// Time: O(n) | Space: O(1)


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int tn = n;
        ListNode* nextNode = head;
        
        while(nextNode && tn--){
            nextNode = nextNode->next;
        }

        ListNode* currNode = head;
        if(!nextNode){
            head = head->next;
            delete(currNode);
            return head;
        }

        while(nextNode && nextNode->next){
            currNode = currNode->next;
            nextNode = nextNode->next;
        }

        ListNode* nthNode = currNode->next;
        currNode->next = nthNode ? nthNode->next : NULL;
        delete(nthNode);
        return head;
    }
};
