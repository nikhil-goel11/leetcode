class SummaryRanges {
    private:
        set<int> stream; 

        public:
            SummaryRanges() {}

                void addNum(int value) {
                        stream.insert(value); 
                            }

                                vector<vector<int>> getIntervals() {
                                        vector<vector<int>> res;
                                                if (stream.empty()) return res;
                                              auto it = stream.begin();
                              int start = *it, end = *it;
                                                ++it;

                                                                                for (; it != stream.end(); ++it) {
                                                                                            if (*it == end + 1) {

                                                                                                                            end = *it;
                                                                                                                                        } else {

                                                                                                                                                                        res.push_back({start, end});
                                                                                                                                                                                        start = end = *it;
                                                                                                                                                                                                    }
                                                                                                                                                                                                            }

                                                                                                                                                                                                                            res.push_back({start, end});
                                                                                                                                                                                                                                    return res;
                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                        };

