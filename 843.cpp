// 很有趣的题目

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        int n = wordlist.size();
        if (n <= 10) {
            for (int i = 0; i < n; ++i) 
                master.guess(wordlist[i]);
        }

        vector<string> similarity;
        vector<vector<int>> cnt(n, vector<int>(7,0));
        vector<pair<int, double>> myvec;
        
        string tmp;
        int i, j, d, idx;
        double mean, std;
        for (i = 0; i < n; ++i) {
            tmp.clear();
            mean = 0.0;
            for (j = 0; j < n; ++j) {
                d = calsimilarity(wordlist[i], wordlist[j]);
                tmp.push_back('0' + d);
                cnt[i][d] += 1;
                mean += d;
            }
            similarity.push_back(tmp);
            mean /= n;
            std = 0.0;
            for (auto it = cnt[i].begin(); it != cnt[i].end(); ++it) {
                std += (mean-*it) * (mean-*it);
            }
            myvec.push_back(make_pair(i, std));
        }
        sort(myvec.begin(), myvec.end(), [](const pair<int, double> & a, const pair<int, double> & b) {
            return a.second < b.second;
        });

        vector<bool> visted(n, false);

        i = myvec[0].first;
		vector<bool> chosen(n, true);
		while (true) {
			d = master.guess(wordlist[i]);
			if (d == 6)
				return;
			visted[i] = true;
			for (j = 0; j < n; ++j) {
				if (visted[j])
					chosen[j] = false;
				else if (similarity[i][j] != '0' + d)
					chosen[j] = false;
			}
			for (i = 0; i < n; ++i) {
				idx = myvec[i].first;
				if (chosen[idx]) {
					i = idx;
					break;
				}
			}
		}
    }
    int calsimilarity(const string & a, const string & b) {
        int res = 0;
        int l = a.length();
        for(int i = 0; i < l; ++i) 
            if (a[i] == b[i])
                ++res;
        return res;
    }
};