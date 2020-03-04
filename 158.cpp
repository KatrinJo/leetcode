// 没理清逻辑……

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {   
private:
    char buff[4];
    int start = 4;
    int end = 4;
    
public:
    /**
     * @param buf destination buffer
     * @param n maximum number of characters to read
     * @return the number of characters read
     */
    
    int read(char *buf, int n) { // buf 以'\0'结尾
        // Write your code here
        int res = 0, i;
        
        for (i = start; i < end; ++i)
            buf[res++] = buff[i];
            
        while(res < n) {
            end = read4(buff);
            start = end;
            if (end == 0) return res;
            for (start = 0; start < end; ++start) {
                if (res == n) break;
                buf[res++] = buff[start];
            }
        }
        buf[res] = '\0';
        
        return res;
    }
};