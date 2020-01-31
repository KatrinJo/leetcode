// 一开始看错题意。后来发现是整体偏移。先分了长度一样的在一个组里，后来发现可以不用，因为直接用了hash。见Solution2

class Solution {
public:
    /**
     * @param strings: a string array
     * @return: return a list of string array
     */
    vector<vector<string>> groupStrings(vector<string> &strings) {
        // write your code here
        int n = strings.size(), l = 0;
        if (n == 0) {
            return vector<vector<string>>{};
        }
        vector<vector<string>> res, diffLenWords;
        unordered_map<int, int> lenInIdx;
        
        for (int i = 0; i < n; i++) {
            l = strings[i].length();
            if (lenInIdx.find(l) == lenInIdx.end()) {
                lenInIdx[l] = diffLenWords.size();
                diffLenWords.push_back(vector<string>{strings[i]});
            }
            else {
                diffLenWords[lenInIdx[l]].push_back(strings[i]);
            }
        }
        unordered_map<string, int> myhash;
        string interStr = "";
        
        for (auto & x : diffLenWords) {
            vector<vector<string>> tmp;
            myhash.clear();
            l = x[0].length();
            for (auto & y : x) {
                interStr = "";
                for (int i = 0; i < l-1; ++i) {
                    interStr.push_back((y[i+1] - y[i] + 26) % 26);
                }
                if (myhash.find(interStr) == myhash.end()) {
                    myhash[interStr] = tmp.size();
                    tmp.push_back(vector<string>{y});
                }
                else {
                    tmp[myhash[interStr]].push_back(y);
                }
            }
            for (auto y : tmp)
                res.push_back(y);
        }
        return res;
    }
};


class Solution2 {
public:
    /**
     * @param strings: a string array
     * @return: return a list of string array
     */
    vector<vector<string>> groupStrings(vector<string> &strings) {
        // write your code here
        int n = strings.size(), l = 0;
        if (n == 0) {
            return vector<vector<string>>{};
        }
        vector<vector<string>> res;
        unordered_map<string, vector<string>> myhash;
        
        string interStr = "";
        
        for (int i = 0; i < n; i++) {
            l = strings[i].length();
            interStr = "";
            for (int j = 0; j < l-1; ++j) {
                interStr.push_back((strings[i][j+1] - strings[i][j] + 26) % 26);
            }
            //if (myhash.find(interStr) == myhash.end()) {
            //    myhash[interStr] = vector<string>{strings[i]};
            //}
            //else {
                myhash[interStr].push_back(strings[i]);
            //}
        }
        for (auto & x : myhash) {
            res.push_back(x.second);
        }
        
        return res;
    }
};
