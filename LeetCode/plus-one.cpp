class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            int len = digits.size();
            vector<int> output(len + 1, 0);
            int c = 1;
            for(int i = len-1; i >= 0; --i) {
                int sum = digits[i] + c;
                output[i+1] = sum % 10;
                c = sum / 10;
            }
            if(c == 1) output[0] = 1;
            else output.erase(output.begin());
            return output;
        }
};
