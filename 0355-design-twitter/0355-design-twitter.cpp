class Twitter {
    private:
        unordered_map<int, unordered_set<int>> following;
            vector<pair<int, int>> tweets;

            public:
                Twitter() {}

                    void postTweet(int userId, int tweetId) {
                            tweets.push_back({userId, tweetId});
                                }

                                    vector<int> getNewsFeed(int userId) {
                                            vector<int> feed;
                                                    for (int i = tweets.size() - 1; i >= 0 && feed.size() < 10; --i) {
                                                                int uid = tweets[i].first;
                                                                            int tid = tweets[i].second;
                                                                                        if (uid == userId || following[userId].count(uid)) {
                                                                                                        feed.push_back(tid);
                                                                                                                    }
                                                                                                                            }
                                                                                                                                    return feed;
                                                                                                                                        }

                                                                                                                                            void follow(int followerId, int followeeId) {
                                                                                                                                                    if (followerId != followeeId)
                                                                                                                                                                following[followerId].insert(followeeId);
                                                                                                                                                                    }

                                                                                                                                                                        void unfollow(int followerId, int followeeId) {
                                                                                                                                                                                following[followerId].erase(followeeId);
                                                                                                                                                                                    }
                                                                                                                                                                                    };
