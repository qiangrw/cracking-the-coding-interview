class Solution {
    public:
        int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
            int start = 0, end = gas.size();
            int tank = 0, res = 0;
            while (start < end) {
                tank += gas[start] - cost[start];
                ++start;
                while (tank < 0 && start < end) {
                    --end;
                    tank += gas[end] - cost[end];
                    res = end;
                }
            }
            return (tank >= 0) ? res : -1;
        }
};
