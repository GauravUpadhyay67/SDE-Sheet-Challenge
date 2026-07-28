// Problem: Complete String (Longest Word with All Prefixes)
// Link: https://www.naukri.com/code360/problems/complete-string_2687860
// Difficulty: Medium
// Approach: Trie
// Time: O(N × L)
// Space: O(N × L)


class Trie{
    struct Node{
        Node* links[26];
        bool isEnd;

        Node(){
            for(int i=0; i<26; i++) {
                links[i] = nullptr;
            }
            isEnd = false;
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
        }
        node->isEnd = true;
    }

    bool check(string &word){
        Node* node = root;

        for(char ch: word){
            int index = ch - 'a';
            node = node->links[index];

            if(node == nullptr || node->isEnd == false){
                return false;
            }
        }
        return true;
    }
};

string completeString(int n, vector<string> &a){
    Trie trie;

    for(auto &word: a){
        trie.insert(word);
    }

    string ans = "";

    for(auto &word : a){
        if(trie.check(word)){
            if(word.size() > ans.size()){
                ans = word;
            }
            else if(word.size() == ans.size() && word < ans){
                ans = word;
            }
        }
    }
    return ans == "" ? "None" : ans;
}
