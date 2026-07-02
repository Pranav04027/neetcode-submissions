class Twitter {
public:
    int timestamp;

    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int,int>>> tweets;
    // userId -> {timestamp, tweetId}

    Twitter() {
        timestamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        struct Node {
            int time;
            int tweetId;
            int userId;
            int index;

            bool operator<(const Node& other) const {
                return time < other.time; // max heap
            }
        };

        priority_queue<Node> pq;

        // include user's own tweets
        following[userId].insert(userId);

        // push latest tweet from each followed user
        for (int followee : following[userId]) {

            if (tweets[followee].empty())
                continue;

            int idx = tweets[followee].size() - 1;

            pq.push({
                tweets[followee][idx].first,
                tweets[followee][idx].second,
                followee,
                idx
            });
        }

        vector<int> feed;

        while (!pq.empty() && feed.size() < 10) {

            Node curr = pq.top();
            pq.pop();

            feed.push_back(curr.tweetId);

            // push previous tweet from same user
            if (curr.index > 0) {

                int newIdx = curr.index - 1;

                pq.push({
                    tweets[curr.userId][newIdx].first,
                    tweets[curr.userId][newIdx].second,
                    curr.userId,
                    newIdx
                });
            }
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return;

        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return;

        following[followerId].erase(followeeId);
    }
};