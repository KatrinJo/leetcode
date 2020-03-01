// 面积好想，但是内部的点会重复偶数次这个是真的没想到……

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int N = rectangles.size();
        int minx = rectangles[0][0], miny = rectangles[0][1];
        int maxx = rectangles[0][2], maxy = rectangles[0][3];
        long long int sum = 0;
        unordered_map<string,int> mymap;
        for (auto & rect : rectangles) {
            minx = min(minx, rect[0]);
            miny = min(miny, rect[1]);
            maxx = max(maxx, rect[2]);
            maxy = max(maxy, rect[3]);
            sum += ((long long int)rect[2] - rect[0]) * (rect[3] - rect[1]);
            mymap[to_string(rect[0])+","+to_string(rect[1])] += 1;
            mymap[to_string(rect[2])+","+to_string(rect[3])] += 1;
            mymap[to_string(rect[0])+","+to_string(rect[3])] += 1;
            mymap[to_string(rect[2])+","+to_string(rect[1])] += 1;
        }
        mymap[to_string(minx)+","+to_string(miny)] += 1;
        mymap[to_string(maxx)+","+to_string(maxy)] += 1;
        mymap[to_string(minx)+","+to_string(maxy)] += 1;
        mymap[to_string(maxx)+","+to_string(miny)] += 1;
        for (auto & x : mymap)
            if (x.second % 2) return false;
        long long int s = ((long long int)maxx - minx) * (maxy - miny);
        return (s == sum);
    }
};