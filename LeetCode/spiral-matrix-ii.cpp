class Solution {
    public:
        vector<vector<int> > generateMatrix(int n) {
            vector<vector<int> > matrix;
            if (n == 0) return matrix;
            matrix = vector<vector<int> >(n, vector<int>(n, 0));

            int start_x = 0, start_y = 0;
            int end_x = n-1, end_y = n-1;
            int num = 1;
            while (true) {
                for (int j = start_y; j <= end_y; ++j) matrix[start_x][j] = num++;
                if (++start_x > end_x) break;
                for (int i = start_x; i <= end_x; ++i) matrix[i][end_y] = num++;
                if (--end_y < start_y) break;
                for (int j = end_y; j >= start_y; --j) matrix[end_x][j] = num++;
                if (--end_x < start_x) break;
                for (int i = end_x; i >= start_x; --i) matrix[i][start_y] = num++;
                if (++start_y > end_y) break;
            }
            return matrix;
        }
};
