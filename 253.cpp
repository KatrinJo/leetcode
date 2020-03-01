// 比较难想象……

/**
 * Definition of Interval:
 * classs Interval {
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
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        // Write your code here
        int n = intervals.size();
        if (n <= 1) return n;
        
        map<int, int> m;
        for (auto & x: intervals) {
            m[x.start] += 1;
            m[x.end] -= 1;
        }
        int res = 0, room = 0;
        for (auto & x : m) {
            res = max(res, room += x.second);
        }
        return res;
    }
};