// Problem: Count Distinct Substrings
// Link: https://www.naukri.com/code360/problems/count-distinct-substrings_9617704
// Difficulty: Medium
// Approach: Trie (Insert all suffixes)
// Time: O(n²)
// Space: O(n²)


class Node{
public:
    Node* links[26];

    Node(){
        for(int i=0; i<26; i++){
            links[i] = nullptr;
        }
    }

    bool containsKey(char ch){
        return links[ch-'a'] != nullptr;
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }
};

int countDistinctSubstrings(string &s){
    Node* root = new Node();
    int cnt = 0;

    for(int i=0; i<s.size(); i++){
        Node* node = root;

        for(int j=i; j<s.size(); j++){
            if(!node->containsKey(s[j])){
                cnt++;
                node->put(s[j], new Node());
            }
            node = node->get(s[j]);
        }
    }
    return cnt+1;
}
