// Problem: Implement Trie II (Prefix Tree)
// Link: https://www.naukri.com/code360/problems/implement-trie_1387095
// Difficulty: Hard
// Approach: Trie with Prefix Count & End Count
// Time:
//   Insert : O(L)
//   Count Words Equal To : O(L)
//   Count Words Starting With : O(L)
//   Erase : O(L)
// Space: O(N × L)



class Trie{
    struct Node{
        Node* links[26];

        int prefixCount;
        int endCount;

        Node(){
            for(int i=0; i<26; i++){
                links[i] = nullptr;
            }

            prefixCount = 0;
            endCount = 0;
        }
    };

    Node* root;

public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;

        for(char ch: word){

            int index = ch - 'a';
            if(node->links[index] == nullptr){
                node->links[index] = new Node();
            }

            node = node->links[index];
            node->prefixCount++;
        }

        node->endCount++;
    }

    int countWordsEqualTo(string &word){
        Node* node = root;

        for(char ch: word){
            int index = ch - 'a';

            if(node->links[index] == nullptr){
                return 0;
            }
            node = node->links[index];
        }

        return node->endCount;
    }

    int countWordsStartingWith(string &word){
        Node* node = root;

        for (char ch: word){
            int index = ch - 'a';

            if(node->links[index] == nullptr){
                return 0;
            }
            node = node->links[index];
        }

        return node->prefixCount;
    }

    void erase(string &word){
        Node* node = root;

        for(char ch: word){
            int index = ch - 'a';

            node = node->links[index];
            node->prefixCount--;
        }
        node->endCount--;
    }
};
