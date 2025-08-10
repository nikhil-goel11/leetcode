class SummaryRanges {
    private:
        set<int> stream; // to store numbers in sorted order without duplicates

        public:
            SummaryRanges() {}

                void addNum(int value) {
                        stream.insert(value); // insert maintains sorted unique values
                            }

                                vector<vector<int>> getIntervals() {
                                        vector<vector<int>> res;
                                                if (stream.empty()) return res;

                                                        auto it = stream.begin();
                                                                int start = *it, end = *it;
                                                                        ++it;

                                                                                for (; it != stream.end(); ++it) {
                                                                                            if (*it == end + 1) {
                                                                                                            // extend the current interval
                                                                                                                            end = *it;
                                                                                                                                        } else {
                                                                                                                                                        // push current interval and start a new one
                                                                                                                                                                        res.push_back({start, end});
                                                                                                                                                                                        start = end = *it;
                                                                                                                                                                                                    }
                                                                                                                                                                                                            }
                                                                                                                                                                                                                    // push the last interval
                                                                                                                                                                                                                            res.push_back({start, end});
                                                                                                                                                                                                                                    return res;
                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                        };

