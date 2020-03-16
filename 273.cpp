class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        map<int, string> i2s;
        string names[30] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety", "Hundred"};
        int i;
        for (i = 0; i <= 20; ++i)
            i2s[i] = names[i];
        for (i = 21; i <= 28; ++i)
            i2s[10 * (i - 18)] = names[i];
        i2s[1000] = "Thousand";
        i2s[1000000] = "Million";
        i2s[1000000000] = "Billion";

        string tmp, res = "";
        int ooo = 1, low, hund;
        while(true) {
            low = num % 1000;
            tmp = "";
            hund = low / 100;
            if (hund) tmp += i2s[hund] + " " + i2s[100] + " ";
            low = low % 100;
            if (low <= 20 && low > 0) tmp += i2s[low] + " ";
            else if (low >= 21) {
                hund = (low / 10) * 10;
                if (hund) tmp += i2s[hund] + " ";
                hund = low % 10;
                if (hund) tmp += i2s[hund] + " ";
            }
            
            if ((ooo > 1) && (num % 1000)) tmp += i2s[ooo] + " ";
            res = tmp + res;

            num = num / 1000;
            if (num == 0)
                break;
            ooo *= 1000;
        }
        res.pop_back();
        return res;
    }
};