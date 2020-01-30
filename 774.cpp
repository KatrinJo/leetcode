// 神奇的二分法，自己绝对想不出来


class Solution {
public:
    /**
     * @param stations: an integer array
     * @param k: an integer
     * @return: the smallest possible value of D
     */
    double minmaxGasDist(vector<int> &stations, int k) {
        double left = 0, right = 0, eps = 1e-6, median = 0;
        int n = stations.size(), cnt = 0;
        vector<int> dis(n-1,0);
        for (int i = 0; i < n - 1; ++i) {
            dis[i] = stations[i+1]-stations[i];
            // left = left > dis[i] ? dis[i] : left;
            right = right > dis[i] ? right : dis[i];
        }
        //cout << left << endl << right << endl;
        while(right - left > eps) {
            median = (left + right) / 2;
            cnt = 0;
            for (int i = 0; i < n - 1; ++i) {
                cnt += int(ceil(dis[i] / median)) - 1;
            }
            if (cnt <= k) {
                right = median;
            }
            else if (cnt > k) {
                left = median;
            }
        }
        return median;
    }
};
