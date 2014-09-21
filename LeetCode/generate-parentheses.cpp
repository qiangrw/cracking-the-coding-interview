class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            vector<string> res;
            string path = "";
            generate(0, 0, n, path, res);
            return res;
        }

        void generate(int left, int right, int n, string path, vector<string> &res) {
            if (path.size() == n * 2) {
                res.push_back(path);
                return;
            }
            if(left < n) generate(left + 1, right, n, path + '(', res);
            if(left > right) generate(left, right + 1, n, path + ')', res);
        }
};
