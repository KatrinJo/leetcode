class MedianFinder {
private:
    struct maxcmp{
        bool operator() (const int & a, const int & b) {
            return a < b;
        }
    };
    struct mincmp{
        bool operator() (const int & a, const int & b) {
            return a > b;
        }
    };
    priority_queue<int, vector<int>, mincmp> minheap; // 最小堆
    priority_queue<int, vector<int>, maxcmp> maxheap; // 最大堆
    // 最大堆的堆顶元素必须要小于最小堆的堆顶元素
    // 最大堆的size=最小堆的size/最小堆的size+1
    
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        int minsize = minheap.size();
        int maxsize = maxheap.size();
        int topinmax, topinmin;

        if (minsize == 0 && maxsize == 0) {
            maxheap.push(num);
        }
        else if (minsize == 0) {
            topinmax = maxheap.top();
            maxheap.pop();
            if (num >= topinmax) {
                maxheap.push(topinmax);
                minheap.push(num);
            }
            else {
                maxheap.push(num);
                minheap.push(topinmax);
            }
        }
        else {
            maxheap.push(num);
            while(true) {
                while (maxheap.size() > minheap.size() + 1) {
                    topinmax = maxheap.top();
                    maxheap.pop();
                    minheap.push(topinmax);
                }
                while(maxheap.top() > minheap.top()) {
                    topinmax = maxheap.top();
                    maxheap.pop();
                    topinmin = minheap.top();
                    minheap.pop();
                    minheap.push(topinmax);
                    maxheap.push(topinmin);
                }
                if ((maxheap.size() >= minheap.size()) && 
                    (maxheap.size() <= minheap.size() + 1) &&
                    maxheap.top() <= minheap.top()
                    )
                    break;
            }
        }
    }
    
    double findMedian() {
        int minsize = minheap.size();
        int maxsize = maxheap.size();
        if (minsize == maxsize)
            return (minheap.top() + maxheap.top()) / 2.0;
        else
            return maxheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */