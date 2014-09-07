class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, bool> visited;
        for (auto x: num) visited[x] = false;  // not visited
        int res = 0, len;
        for (auto x: num) {
            if (visited[x]) continue;
            len = 1;
            for (int tmp = x - 1; visited.count(tmp); --tmp) {
                visited[tmp] = true;
                ++len;
            }
            for (int tmp = x + 1; visited.count(tmp); ++tmp) {
                visited[tmp] = true;
                ++len;
            }
            res = max(res, len);
        }
        return res;
    }
};