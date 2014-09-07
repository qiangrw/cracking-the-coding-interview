class Solution {
public:
    void gen_path(vector<vector<string>> &res, unordered_map<string, vector<string> > &parents, 
                    vector<string> &path, string &start, string &word) {
        path.push_back(word);
        if (start == word) {
            res.push_back(path);
            reverse(res.back().begin(), res.back().end());
        } else {
            for (auto s: parents[word]) {
                gen_path(res, parents, path, start, s);
            }
        }
        path.pop_back();
    }

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>> res;
        if (start.size() != end.size()) return res;
        unordered_set<string> visited;
        unordered_map<string, vector<string> > parents;
        unordered_set<string> current, next;
        current.insert(start);
        visited.insert(start);
        bool flag = false;
        while (!current.empty() && !flag) {
            for (auto word: current) visited.insert(word);
            for (auto word: current) {
                for (int i = 0; i < word.size(); ++i) {
                    string origin = word;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == origin[i]) continue;
                        word[i] = c;
                        if (word == end) flag = true;
                        if (dict.count(word) && visited.count(word) == 0) {
                            next.insert(word);
                            parents[word].push_back(origin);
                        }
                    }
                    word[i] = origin[i];
                }
            }
            current.clear();
            current.swap(next);
        }
        vector<string> path;
        if (flag) gen_path(res, parents, path, start, end);
        return res;
    }
};