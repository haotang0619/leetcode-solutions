class Twitter {
public:
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets; // [time, id]
    int time = 0;

    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int, int, int>> pq; // [time, user, idx]
        for(auto& x : following[userId]) {
            int sz = tweets[x].size();
            if(sz > 0) pq.push({tweets[x][sz - 1].first, x, sz - 1});
        }
        int sz = tweets[userId].size();
        if(sz > 0) pq.push({tweets[userId][sz - 1].first, userId, sz - 1});
        
        vector<int> ans;
        while(ans.size() < 10 && !pq.empty()) {
            auto [time, u, idx] = pq.top();
            pq.pop();
            ans.push_back(tweets[u][idx].second);
            if(idx > 0) pq.push({tweets[u][idx - 1].first, u, idx - 1});
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
