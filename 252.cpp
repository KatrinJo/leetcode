/**
 * Definition of Interval:
 * class Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    bool canAttendMeetings(vector<Interval> &intervals) {
        // Write your code here
        int n = intervals.size();
        if (n <= 1) return true;
        sort(intervals.begin(), intervals.end(), [](const Interval & a, const Interval & b) {
            return a.start < b.start;
        });
        for (int i = 0; i < n - 1; ++i) {
            if (intervals[i].end > intervals[i+1].start) return false;
        }
        return true;        
    }
};