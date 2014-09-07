class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start.size() != end.size()) return 0;
        unordered_set<string> visited;
        queue<string> current, next;
        current.push(start);
        visited.insert(start);
        int len = 0;
        while (!current.empty()) {
            len += 1;
            while (!current.empty()) {
                string word = current.front();
                current.pop();
                if (word == end) return len;
                for (int i = 0; i < word.size(); ++i) {
                    char tmp = word[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[i] = c;
                        if (dict.count(word) && visited.count(word) == 0) {
                            next.push(word);
                            visited.insert(word);
                        }
                    }
                    word[i] = tmp;
                }
            }
            current.swap(next);
        }
        return 0;
    }
};