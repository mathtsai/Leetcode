#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    Node* ch[26];
    bool isWord;
    Node(){
        for(int i=0; i<26; i++) ch[i] = nullptr;
        isWord = false;
    }
    ~Node(){
        for(int i=0; i<26; i++)
        {
            if(ch[i])
            {
                delete ch[i];
                cout << "delete child " << (char)('a'+i) << '\n';
            }
        }
    }
};

class Trie{
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    ~Trie(){
        delete root;
        cout << "delete root\n";
    }

    void insert(string word) {
        Node* cur = root;
        for(auto c: word)
        {
            if(!cur->ch[c-'a'])
                cur->ch[c-'a'] = new Node();
            cur = cur->ch[c-'a'];
        }
        cur->isWord = true;
    }

    bool search(string word) {
        Node* cur = root;
        for(auto c: word)
        {
            if(cur->ch[c-'a'])
                cur = cur->ch[c-'a'];
            else return false;
        }
        return cur->isWord;
    }

    bool startsWith(string prefix) {
        Node* cur = root;
        for(auto c: prefix)
        {
            if(cur->ch[c-'a'])
                cur = cur->ch[c-'a'];
            else return false;
        }
        return true;
    }
};

int main()
{
    Trie T;
    T.insert("apple");
    T.insert("b");
    cout << T.search("app") << '\n';
    cout << T.startsWith("app") << '\n';
    cout << T.search("apple") << '\n';
}
