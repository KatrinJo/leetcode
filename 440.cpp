// 需要仔细转换……

class Solution {
public:

    int count_dis (string s1, string s2) {
        int slen1 = s1.length(), slen2 = s2.length();
        int n = -2;
        if (s1 > s2.substr(0, slen1)) {
            n = 0;
            for (int i = 0; i < (slen2 - slen1); ++i)
                n += pow(10, i);
        }
        if (s1 == s2.substr(0, slen1)) {
            n = stoi(s2) - stoi(s1) * pow(10, slen2 - slen1) + 1;
            for (int i = 0; i < (slen2 - slen1); ++i)
                n += pow(10, i);
        }
        return n;        
    }

    int findKthNumber(int n, int k) {
        vector<int> cnt(11, 0);
        string s = to_string(n), sStart = "", sEnd, sn = to_string(n);
        int sLen = s.length(), tmp;

        cnt[0] = 1;
        for (int i = 1; i <= sLen; ++i) {
            cnt[i] += cnt[i - 1] + pow(10, i);
        }
        
        int i;
        while(k > 0 && sStart.length() < sLen) {
            sStart.push_back('0');
            i = (sStart.length() == 1);
            k--;
            for (; i <= 9; ++i) {
                sStart.back() = '0' + i;
                tmp = count_dis(sStart, sn);
                if (tmp == -2) {
                    if (k >= cnt[sLen - sStart.length()]) 
                        k -= cnt[sLen - sStart.length()];
                    else 
                        break;
                }
                else if (tmp >= 0) {
                    if (k >= tmp)
                        k -= tmp;
                    else
                        break;
                }
            }
        }

        return stoi(sStart);
    }
};