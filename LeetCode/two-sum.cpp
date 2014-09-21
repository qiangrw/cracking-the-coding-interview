class Solution {
    public:
        vector<int> twoSum(vector<int> &numbers, int target) {
            unordered_map<int, int> dict;
            for (int i = 0; i < numbers.size(); ++i) dict[numbers[i]] = i;
            for (int i = 0; i < numbers.size(); ++i) {
                auto pos = dict.find(target - numbers[i]);
                if (pos != dict.end() && i != pos->second) return {i + 1, pos->second + 1};
            }
            return {};
        }
};
