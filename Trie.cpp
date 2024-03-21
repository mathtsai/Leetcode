class Trie {
public:
    Trie *ch[26];
    bool isWord;
    Trie() {
        for(int i=0; i<26; i++) ch[i] = nullptr;
        isWord = false;
    }

    void insert(string word) {
        Trie *cur = this;
        for(auto c: word)
        {
            if(!cur->ch[c-'a'])
                cur->ch[c-'a'] = new Trie();
            cur = cur->ch[c-'a'];
        }
        cur->isWord = true;
    }

    bool search(string word) {
        Trie *cur = this;
        for(auto c: word)
        {
            if(cur->ch[c-'a'])
                cur = cur->ch[c-'a'];
            else return false;
        }
        return cur->isWord;
    }

    bool startsWith(string prefix) {
        Trie *cur = this;
        for(auto c: prefix)
        {
            if(cur->ch[c-'a'])
                cur = cur->ch[c-'a'];
            else return false;
        }
        return true;
    }
};
