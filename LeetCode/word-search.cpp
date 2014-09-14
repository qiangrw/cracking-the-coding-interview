class Solution {
    public:
        bool dfs(vector<vector<char> > &board, vector<vector<bool> > &visited, const string &word, int cur, int i, int j) {
            if (cur == word.size()) return true;

            int m = board.size();
            int n = board[0].size();
            if (i < 0 || i >= m || j < 0 || j >= n) return false;
            if (visited[i][j]) return false;

            bool ret = false;
            visited[i][j] = true;
            if (board[i][j] == word[cur]) {
                ret = dfs(board, visited, word, cur+1, i+1, j) || dfs(board, visited, word, cur+1, i-1, j) || 
                    dfs(board, visited, word, cur+1, i, j+1) || dfs(board, visited, word, cur+1, i, j-1);
            }
            visited[i][j] = false;
            return ret;
        }

        bool exist(vector<vector<char> > &board, string word) {
            if (board.empty()) return false;
            int m = board.size();
            int n = board[0].size();
            vector<vector<bool> > visited(m, vector<bool>(n, false));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if(dfs(board, visited, word, 0, i, j)) return true;
                }
            }
            return false;
        }
};
