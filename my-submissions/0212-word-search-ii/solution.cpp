
class Solution {
private:
    struct Trie {
        Trie* children[26];
        bool EOW;

        Trie() : EOW(false) {
            for (int i = 0; i < 26; ++i)
                children[i] = nullptr;
        }
    };

    void createTrie(Trie* root, const vector<string>& words) {
        for (const string& word : words) {
            Trie* temp = root;

            for (char c : word) {
                int idx = c - 'a';

                if (!temp->children[idx])
                    temp->children[idx] = new Trie();

                temp = temp->children[idx];
            }

            temp->EOW = true;
        }
    }

    void dfs(vector<vector<char>>& board, Trie* node,
             int i, int j, vector<string>& ans, string& word) {

        // 1. Validate coordinates before accessing the board.
        if (i < 0 || j < 0 ||
            i >= (int)board.size() ||
            j >= (int)board[0].size())
            return;

        if (board[i][j] == '.')
            return;

        char c = board[i][j];
        int idx = c - 'a';

        // 2. Follow the Trie edge matching the current character.
        if (!node->children[idx])
            return;

        Trie* next = node->children[idx];

        word.push_back(c);

        // 3. Record the word only after consuming the current character.
        if (next->EOW) {
            ans.push_back(word);
            next->EOW = false;  // Prevent duplicate results.
        }

        // 4. Mark the current cell as visited.
        board[i][j] = '.';

        // 5. Explore four adjacent cells.
        dfs(board, next, i + 1, j, ans, word);
        dfs(board, next, i - 1, j, ans, word);
        dfs(board, next, i, j + 1, ans, word);
        dfs(board, next, i, j - 1, ans, word);

        // 6. Backtrack.
        board[i][j] = c;
        word.pop_back();
    }

    void exist(vector<vector<char>>& board, Trie* root,
               vector<string>& ans, string& word) {
        if (board.empty() || board[0].empty())
            return;

        for (int i = 0; i < (int)board.size(); ++i) {
            for (int j = 0; j < (int)board[0].size(); ++j) {
                dfs(board, root, i, j, ans, word);
            }
        }
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        Trie* root = new Trie();
        createTrie(root, words);

        vector<string> ans;
        string word;

        exist(board, root, ans, word);

        return ans;
    }
};

