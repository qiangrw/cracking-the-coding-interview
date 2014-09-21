class Solution {
    public:
        string convert(string s, int nRows) {
            if (nRows <= 1) return s;
            vector<vector<char> > v(nRows);
            bool zig=true;
            auto it = s.begin();
            int zigRow = 0;
            while (it != s.end()) {
                if (zig) {
                    for (int r = 0; r < nRows; ++r) {
                        if (it == s.end()) break;
                        v[r].push_back(*it);
                        ++it;
                    }
                    zigRow = nRows-2;
                    if (zigRow != 0) zig = false;
                } else {
                    v[zigRow].push_back(*it);
                    ++it;
                    --zigRow;
                    if (zigRow == 0) zig = true;
                }
            }
            string res;
            for (const auto &x: v)
              for (const auto &y: x) 
                res += y;
            return res;
        }
};
