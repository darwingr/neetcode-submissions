// Space: O((N x m) + (N x M))
//  N - users
//  m - max tweets for any user
//  M - max followees for any user
//  n - followee IDs
class Twitter {
    // O(N x M)
    unordered_map<int, unordered_set<int>> user_followees;

    int tweet_count = 0;
    // O(N x m)
    // user_id -> { (countstamp, tweet_id) }
    unordered_map<int, vector<pair<int,int>>> user_tweets;

public:
    Twitter() {}
    
    // O(1)
    void postTweet(int userId, int tweetId) {
        user_tweets[userId].push_back({tweet_count, tweetId});
        tweet_count++;
    }
    
    // O(n log n)
    vector<int> getNewsFeed(int userId) {
        auto& followees = user_followees[userId];
        followees.insert(userId);
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > most_recent; // min heap
        for (int f : followees)
            for (auto tweet : user_tweets[f]) {
                if (most_recent.empty() || most_recent.size() < 10)
                    most_recent.push(tweet);
                else if (most_recent.top() < tweet) {
                    most_recent.pop();
                    most_recent.push(tweet);
                }
            }
        followees.erase(userId);

        vector<int> result(most_recent.size());
        for (int i=result.size()-1; i>=0; i--) {
            result[i] = most_recent.top().second;
            most_recent.pop();
        }
        return result;
    }
    
    // O(1)
    void follow(int followerId, int followeeId) {
        user_followees[followerId].insert(followeeId);
    }
    
    // O(1)
    void unfollow(int followerId, int followeeId) {
        user_followees[followerId].erase(followeeId);
    }
};
