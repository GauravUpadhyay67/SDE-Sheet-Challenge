// Problem: Clone Linked List with Random and Next Pointer
// Link: https://leetcode.com/problems/copy-list-with-random-pointer/
// Difficulty: Hard
// Approach: Interleave clone nodes, set random pointers, separate lists
// Time: O(n) | Space: O(1)



class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        Node* temp = head;

        while(temp){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }

        temp = head;
        while (temp) {
            if (temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }

        Node* dummyHead = new Node(-1);
        Node* copy = dummyHead;
        temp = head;

        while (temp) {
            copy->next = temp->next;
            temp->next = temp->next->next;

            copy = copy->next;
            temp = temp->next;
        }
        return dummyHead->next;
    }
};
