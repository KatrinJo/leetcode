class MyCalendarTwo {
	map<int, int> smap;

public:
	MyCalendarTwo() {
	}

	bool book(int start, int end) {
		bool res = true, flag = false;
		int intd = -1;

		auto sit = smap.begin();
		auto it = sit;
		for (; sit != smap.end() && sit->first < start; ++sit);

		if (sit == smap.end()) {
			smap[start] = 1;
			smap[end] = 0;
			return true;
		}
		else if (smap.count(start) == 0) {
			flag = true;
			if (sit == smap.begin())
				intd = 1;
			else {
				it = sit;
				--it;
				if (it->second >= 2) return false;
				intd = it->second + 1;
			}
		}

		auto eit = smap.begin();
		for (; eit != smap.end() && eit->first < end; ++eit);

		it = sit;
		for (; it != eit; ++it) {
			if (it->second >= 2) {
				for (eit = sit; eit != it; ++eit)
					--eit->second;
				return false;
			}
			++it->second;
		}

		if (flag)
			smap[start] = intd;

		if (smap.count(end) == 0) {
			it = eit;
			--it;
			smap[end] = it->second - 1;
		}

		if (start == 30) {
			for (auto & x : smap) {
				cout << "(" << x.first << "," << x.second << ")";
			}
		}

		return true;
	}
};


/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */