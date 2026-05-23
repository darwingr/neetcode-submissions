// Space: O(N x F + T)
//  N - users
//  F - follows
//  T - total tweets
class Twitter {
    // O(N x F)
    unordered_map<int, unordered_set<int>> user_followees;

    int tweet_count = 0;
    // O(N + T)
    // user_id -> { (countstamp, tweet_id) }
    unordered_map<int, vector<pair<int,int>>> user_tweets;

public:
    Twitter() {}
    
    // O(1) amortized
    void postTweet(int userId, int tweetId) {
        user_tweets[userId].push_back({tweet_count, tweetId});
        tweet_count++;
    }
    
    // O(F + T) - worst case where 1 user has all the tweets.
    //   Θ(F_u + T_u) - avg case
    //  Heap work is O(1) given 10 element limit.
    vector<int> getNewsFeed(int userId) {
        auto& followees = user_followees[userId];
        followees.insert(userId);
        // O(1) space
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > most_recent; // min heap
        // O(F)
        for (int f : followees)
            // O(T)
            for (auto tweet : user_tweets[f]) {
                // O(log 10) == O(1)
                if (most_recent.empty() || most_recent.size() < 10)
                    most_recent.push(tweet);
                else if (most_recent.top() < tweet) {
                    most_recent.pop();
                    most_recent.push(tweet);
                }
            }
        followees.erase(userId);

        // O(1)
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
