class TrieNode{
    public:
    TrieNode* links[26];
    bool isFinished;
    TrieNode(){
        isFinished = false;
        for(int i = 0; i < 26; i++){
        links[i] = nullptr;
    }
    }
    bool isContains(char ch){
        return links[ch-'a']!=NULL;
    }

    void put(char ch, TrieNode* newNode){
        links[ch-'a']=newNode;
    }

    void setEnd(){
        isFinished=true;
    }

    bool isEnd(){
        return isFinished;
    }

    TrieNode* nextNode(char ch){
        return links[ch-'a'];
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root= new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->isContains(word[i])){
                TrieNode* newNode= new TrieNode;
                node->put(word[i], newNode);
            }
            node=node->nextNode(word[i]);
        }
        
        node->setEnd();
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->isContains(word[i])){
                return false;
            }
            node=node->nextNode(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(int i=0; i<prefix.length(); i++){
            if(!node->isContains(prefix[i])){
                return false;
            }
            node=node->nextNode(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */