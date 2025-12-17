class Solution {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;

        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };

    void makeTrie(TrieNode* root, vector<string>& words) {
        for (const string &str : words) {
            TrieNode* temp = root;
            for (const char &c : str) {
                int idx = c - 'a';
                if (!temp -> children[idx])
                    temp -> children[idx] = new TrieNode();
                temp = temp -> children[idx];
            }
            temp -> isEnd = true;
        }
    }

    void search(vector<vector<char>>& board, TrieNode* node, int i, int j, vector<string>& found, string& word) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return;

        char curr = board[i][j];
        if (curr == '#' || !node->children[curr - 'a'])
            return;

        node = node->children[curr - 'a'];
        word.push_back(curr);

        if (node->isEnd) {
            found.push_back(word);
            node->isEnd = false;   // avoid duplicates
        }

        board[i][j] = '#';

        search(board, node, i + 1, j, found, word);
        search(board, node, i - 1, j, found, word);
        search(board, node, i, j + 1, found, word);
        search(board, node, i, j - 1, found, word);

        board[i][j] = curr;
        word.pop_back();
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        makeTrie(root, words);

        vector<string> found;
        string word;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                search(board, root, i, j, found, word);
            }
        }
        return found;
    }
};
