class Solution {
    public:
        void combine(vector<string> &input, vector<string> &output, string a) {
            for (auto c: a)
              for (auto x: input)
                output.push_back(x + c);
        }

        vector<string> letterCombinations(string digits) {
            vector<string> input, output(1, "");
            vector<string> dmap = { "abc", "def", "ghi", "jkl", "mno",
                "pqrs", "tuv", "wxyz" };
            for (int i = 0; i < digits.size(); ++i) {
                input = output;
                vector<string>().swap(output);
                combine(input, output, dmap[digits[i] - '2']);
            }
            return output;
        }
};
