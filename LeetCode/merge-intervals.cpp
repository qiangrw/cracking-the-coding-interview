/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    public:
        vector<Interval> merge(vector<Interval> &intervals) {
            vector<Interval> res;
            if (intervals.empty()) return res;
            sort(intervals.begin(), intervals.end(), [&](Interval a, Interval b) { return a.start < b.start;});
            res.push_back(intervals[0]);
            for (int i = 1; i < intervals.size(); ++i) {
                if(intervals[i].start > res.back().end) {
                    res.push_back(intervals[i]);
                } else {
                    res.back().end = max(res.back().end, intervals[i].end);
                }
            }
            return res;
        }
};
