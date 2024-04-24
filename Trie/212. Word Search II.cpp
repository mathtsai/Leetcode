class Node
{
public:
    int word;
    Node *ch[26];
    Node()
    {
        word = -1;
        for(int i=0; i<26; i++)
            ch[i] = nullptr;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node();
    }
    void insert(string &s, int id)
    {
        Node *tmp = root;
        for(auto &c: s)
        {
            if(!tmp->ch[c-'a'])
                tmp->ch[c-'a'] = new Node();

            tmp = tmp->ch[c-'a'];
        }
        tmp->word = id;
    }
};

class Solution {
public:
    int m,n;
    int dx[4] = {1,0,-1,0}, dy[4] = {0,-1,0,1};
    bool vis[12][12];
    bool mark[30001];
    void dfs(int x, int y, Node *cur, vector<vector<char>>& board)
    {
        char c = board[x][y];
        if(!cur->ch[c-'a']) return;

        vis[x][y] = true;
        cur = cur->ch[c-'a'];
        if(cur->word != -1)
            mark[cur->word] = true;

        for(int i=0; i<4; i++)
        {
            int nx = x+dx[i], ny = y+dy[i];
            if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny])
            {
                dfs(nx, ny, cur, board);
            }
        }
        vis[x][y] = false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *T = new Trie();
        for(int i=0; i<words.size(); i++)
            T->insert(words[i], i);

        m = board.size(), n = board[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                memset(vis, false, sizeof(vis));
                dfs(i, j, T->root, board);
            }
        }

        vector<string> ans;
        for(int i=0; i<words.size(); i++)
        {
            if(mark[i])
                ans.push_back(words[i]);
        }
        return ans;
    }
};
