// Problem: LRU Cache
// Link: https://leetcode.com/problems/lru-cache/
// Difficulty: Medium
// Approach: HashMap + Doubly Linked List — O(1) get and put
// Time: O(1) | Space: O(capacity)


class LRUCache {
    class Node{
    public:
        int key, val;
        Node* next;
        Node* prev;

        Node(int k, int v){
            key = k;
            val = v;
            next = NULL;
            prev = NULL;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*>mp;

    int maxCap, currCap;



public:
    LRUCache(int capacity) {
        maxCap = capacity;
        currCap = 0;
        head->next = tail;
        head->prev = NULL;
        tail->prev = head;
        tail->next = NULL;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];
        removeNode(node);
        addNode(node);
        return node->val;
    }

    void addNode(Node* newNode){
       head->next->prev = newNode;
       newNode->next = head->next;
       head->next = newNode;
       newNode->prev = head;
    }

    void removeNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        node->prev = NULL;
        node->next = NULL;
    }
    
    void put(int key, int value) {

        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->val = value;
            removeNode(node);
            addNode(node);
            return;
        }

        if(currCap == maxCap){
            Node* lru = tail->prev;
            removeNode(lru);
            mp.erase(lru->key);
            delete lru;
            currCap--;
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
        currCap++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
