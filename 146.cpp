class LRUCache {
private:
    unordered_map<int, pair<int, int>> mymap;
    int times;
    int maxCap;
public:
    
    LRUCache(int capacity) {
        mymap.clear();
        times = 0;
        maxCap = capacity;
    }
    
    int get(int key) {
        if (mymap.count(key) == 0)
            return -1;
        int val = mymap[key].first;
        mymap[key] = make_pair(val, times);
        ++times;
        return val;
    }
    
    void put(int key, int value) {
        if (mymap.size() > maxCap) {
            int minkey = 0;
            int minTimes = times;
            for (auto it = mymap.begin(); it != mymap.end(); ++it) {
                auto tmp = *it;
                if ((it->second).second < minTimes) {
                    minkey = it->first;
                    minTimes = (it->second).second;
                }
            }
            mymap.erase(minkey);
        }
        mymap[key] = make_pair(value, times);
        ++times;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


// 想在O(1)时间完成，但好像还是很慢_(:з」∠)_
class LRUCache {
private:
	unordered_map<int, int> idxofkey;
	vector<vector<int>> mem;
	int start;
	int end;
	int maxcap;
	int times;
public:
	LRUCache(int capacity) {
		idxofkey.clear();
		maxcap = capacity;
		start = end = -1;
		times = 0;
		mem.resize(capacity, vector<int>(4, -1));
	}

	int get(int key) {
		if (idxofkey.count(key) == 0)
			return -1;
		int idx = idxofkey[key];

		if (start != idx) {
			if (end == idx) {
				end = mem[idx][2];
				mem[end][3] = -1;
			}
			else {
				int bef = mem[idx][2], next = mem[idx][3];
				mem[bef][3] = next;
				mem[next][2] = bef;				
			}
			mem[idx][2] = -1;
			mem[idx][3] = start;
			mem[start][2] = idx;
			start = idx;
		}
		return mem[idx][1];
	}

	void put(int key, int value) {
		if (maxcap == 1) {
			idxofkey.clear();
			mem[0][0] = key;
			mem[0][1] = value;
			idxofkey[key] = 0;
			mem[0][2] = mem[0][3] = -1;
			start = end = 0;
			return;
		}

		int idx = idxofkey.size();
		if (idx == maxcap) {
			if (idxofkey.count(key) != 0) {
				idx = idxofkey[key];
				mem[idx][1] = value;
				if (idx != start) {
					if (idx == end) 
						end = mem[end][2];
					else {
						int bef = mem[idx][2], next = mem[idx][3];
						mem[bef][3] = next;
						mem[next][2] = bef;
					}
					mem[idx][2] = -1;
					mem[idx][3] = start;
					mem[start][2] = idx;
					start = idx;
				}		
				return;
			}
			else {
				idxofkey.erase(mem[end][0]);
				idx = end;
				end = mem[end][2];
				mem[start][2] = idx;
			}	
		}
		else if (idx == 0) end = 0;
		else {
			if (idxofkey.count(key) != 0) {
				idx = idxofkey[key];
				mem[idx][1] = value;
				if (idx != start) {
					if (idx == end)
						end = mem[end][2];
					else {
						int bef = mem[idx][2], next = mem[idx][3];
						mem[bef][3] = next;
						mem[next][2] = bef;
					}
					mem[idx][2] = -1;
					mem[idx][3] = start;
					mem[start][2] = idx;
					start = idx;
				}
				return;
			}
			else 
				mem[start][2] = idx;
		}
								
		mem[idx][0] = key;
		mem[idx][1] = value;
		idxofkey[key] = idx;
		mem[idx][2] = -1;
		if (idx != start)
			mem[idx][3] = start;
		start = idx;
	}
	
};