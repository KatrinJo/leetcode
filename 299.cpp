class Solution {
public:
    string getHint(string secret, string guess) {
        int lena = secret.length(), lenb = guess.length();
        int a = 0, b = 0, cnt[10] = {0};
        for (int i = 0; i < lena; ++i) {
            if (secret[i] == guess[i])
                ++a;
            else 
                ++cnt[secret[i] - '0'];        
        }
        for (int i = 0; i < lenb; ++i) {
            if (secret[i] != guess[i] && cnt[guess[i] - '0']) {
                --cnt[guess[i] - '0'];
                ++b;
            }
        }
        return to_string(a) + "A" + to_string(b) + "B";
    }
};