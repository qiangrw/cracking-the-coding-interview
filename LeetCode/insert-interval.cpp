/**
 *  Definition for an interval.
 *  struct Interval {
 *    int start;
 *    int end;
 *    Interval() : start(0), end(0) {}
 *    Interval(int s, int e) : start(s), end(e) {}
 *  };
 */
class Solution {
    public:
        vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
            auto it = intervals.begin();
            while (it != intervals.end()) {
                if (newInterval.end < it->start) {
                     // insert before it
                    intervals.insert(it, newInterval);
                    return intervals;
                } else if (newInterval.start <= it->end){
                    // included in it
                    if (newInterval.start >= it->start && newInterval.end <= it->end) return intervals;
                    // overlap
                    newInterval.start = min(it->start, newInterval.start);
                    newInterval.end = max(it->end, newInterval.end);
                    it = intervals.erase(it);
                } else ++it;
            }
            intervals.push_back(newInterval);
            return intervals;
        }
};
