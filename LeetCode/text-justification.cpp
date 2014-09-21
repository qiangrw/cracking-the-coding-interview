class Solution {
    public:
        vector<string> fullJustify(vector<string> &words, int L) {
            vector<string> res;
            vector<string> v;
            int cur_len = 0, i = 0;
            string line;
            while (i < words.size()) {
                int space = (cur_len == 0) ? 0 : 1;
                if (cur_len + words[i].size() + space <= L) {    
                    v.push_back(words[i]);
                    cur_len += (space + words[i].size());
                    ++i;
                } else {
                    // cannot hold in this line.
                    int total_space = L - cur_len;
                    // A line other than the last line might contain only one word. 
                    if (v.size() == 1) {
                        line = v[0];
                        line += string(total_space, ' ');
                    } else {
                        int per_space = total_space / (v.size() - 1);
                        int left_space = total_space - per_space * (v.size()-1);
                        line = v[0];
                        for (int w = 1; w < v.size(); ++w) {
                            if (left_space >= 1) {
                                line += ' ';
                                --left_space;
                            }
                            line += string(per_space + 1, ' ') + v[w];
                        }
                    }
                    res.push_back(line);
                    cur_len = 0;
                    v.clear();
                }
            }

            // process the last line.
            line = v[0];
            for (int w = 1; w < v.size(); w++) line += ' ' + v[w];
            line += string(L - cur_len, ' ');
            res.push_back(line);
            return res;
        }
};
