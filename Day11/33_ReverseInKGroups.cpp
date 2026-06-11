// Problem: Reverse Linked List in Group of Size K
// Link: https://leetcode.com/problems/reverse-nodes-in-k-group/
// Difficulty: Hard
// Approach: Reverse K nodes at a time recursively, connect groups
// Time: O(n) | Space: O(n/k) recursion stack

class Solution {
public:
    ListNode* findKthNode(ListNode* temp, int k){
        int cnt = 1;
        while(temp && cnt != k){
            temp = temp->next;
            cnt++;
        }
        return temp;
    }

    ListNode* reverseLL(ListNode* head){
        ListNode* prevNode = NULL;
        ListNode* currNode = head;

        while(currNode){
            ListNode* nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while(temp){
            ListNode* kthNode = findKthNode(temp, k);

            if(!kthNode){
                if(prevLast) prevLast->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseLL(temp);

            if(temp == head){
                head = kthNode;
            }
            else{
                prevLast->next = kthNode;
            }
            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};
