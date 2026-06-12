// Problem: Flattening of Linked List
// Link: https://www.geeksforgeeks.org/flattening-a-linked-list/
// Difficulty: Hard
// Approach: Merge sort style — recursively flatten and merge bottom lists
// Time: O(n*m) | Space: O(1)


class Solution {
  public:
    Node* mergeTwoSortedLL(Node* head, Node* nextHead) {
        Node* dummy = new Node(0);
        Node* tail = dummy;

        while (head && nextHead) {
            if (head->data < nextHead->data) {
                tail->bottom = head;
                head = head->bottom;
            } else {
                tail->bottom = nextHead;
                nextHead = nextHead->bottom;
            }
            tail = tail->bottom;
        }
    
        if (head) tail->bottom = head;
        else tail->bottom = nextHead;
    
        return dummy->bottom;
    }

    
    Node* solve(Node* head){
        if(!head->next) return head;
        
        Node* nextHead = solve(head->next);
        
        return head = mergeTwoSortedLL(head, nextHead);
    }
    
    Node *flatten(Node *root) {
        return solve(root);
    }
};
