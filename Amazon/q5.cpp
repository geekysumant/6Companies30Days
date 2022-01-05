lass TrieNode{
public:
    TrieNode* children[26];
    bool isTerminal;

    TrieNode() {
        isTerminal = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }

    bool containsKey(char ch) {
        return children[ch - 'a'] != NULL;
    }
};
class Solution {
public:
    TrieNode* root;
    void insert(TrieNode* root, string &word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i]))
                node->children[word[i] - 'a'] = new TrieNode();
            node = node->children[word[i] - 'a'];
        }
        node->isTerminal = true;
    }
    void help(TrieNode* root, vector<string>&vec, string word) {
        if (root->isTerminal) {
            vec.push_back(word);
        }
        for (int i = 0; i < 26; i++) {
            if (root->children[i]) {
                word += ('a' + i);
                help(root->children[i], vec, word);
                word.pop_back();
            }
        }

    }
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        root = new TrieNode();
        for (int i = 0; i < n; i++) {
            insert(root, contact[i]);
        }
        string pre = "";
        vector<vector<string>>ans;
        for (int i = 0; i < s.length(); i++) {
            pre += s[i];
            TrieNode* node = root;
            bool flag = 0;
            for (auto ch : pre) {
                if (!node->containsKey(ch)) {
                    ans.push_back({"0"});
                    flag = 1;
                    break;
                }
                node = node->children[ch - 'a'];
            }
            if (flag)
                continue;
            vector<string> res;
            help(node, res, pre);
            ans.push_back(res);
        }
        return ans;
    }
};