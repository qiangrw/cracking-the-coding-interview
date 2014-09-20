class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int> > &matrix) {
            vector<int> res;
            if (matrix.empty()) return res;
            int m = matrix.size();
            int n = matrix[0].size();
            int start_x = 0, start_y = 0;
            int end_x = m-1, end_y = n-1;
            while (true) {
                for (int j = start_y; j <= end_y; ++j) res.push_back(matrix[start_x][j]);
                if (++start_x > end_x) break;
                for (int i = start_x; i <= end_x; ++i) res.push_back(matrix[i][end_y]);
                if (--end_y < start_y) break;
                for (int j = end_y; j >= start_y; --j) res.push_back(matrix[end_x][j]);
                if (--end_x < start_x) break;
                for (int i = end_x; i >= start_x; --i) res.push_back(matrix[i][start_y]);
                if (++start_y > end_y) break;
            }
            return res;
        }
};
