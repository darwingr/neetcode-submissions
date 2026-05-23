#include <ranges>
class Twitter {
    int tweet_count = 0;
    // O(U + T)
    unordered_map<
        int,
        vector<pair<int, int>> // count serial, tweet ID
    > user_tweets;

    // O(U + F)
    unordered_map<int, unordered_set<int>> user_followees;

public:
    Twitter() {}
    
    // O(1)
    void postTweet(int userId, int tweetId) {
        user_tweets[userId].push_back({tweet_count, tweetId});        
        tweet_count++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > most_recent; // min heap

        queue<int> followees;
        for (int f : user_followees[userId])
            followees.push(f);
        followees.push(userId);
        followees.push(-1); //sentinel

        /* each id to a queue, -1 on end
           while queue is not empty
              if id -1 inc the back index, reinsert to queue
              if followee_tweets.size-idx && (size min_heap < 10 or front latest tweet is > top)
                add back indexed tweet to heap, re-queue the followee
              else
                nothing
        */
        size_t back_index = 0;
        while (followees.size() > 1) {
            int followee = followees.front();
            followees.pop();

            if (followee == -1) {
                back_index++;
                followees.push(followee);
            }
            else if (user_tweets[followee].size() - back_index > 0) {
                auto next_most_recent = *(user_tweets[followee].end() - 1 - back_index);

                if (most_recent.size() < 10) {
                    most_recent.push(next_most_recent);
                    followees.push(followee);
                }
                else if (most_recent.top() < *(user_tweets[followee].end() - 1 - back_index)) {
                    most_recent.pop();
                    most_recent.push(next_most_recent);
                    followees.push(followee);
                }
            }
        }
        
        vector<int> result(most_recent.size());
        for (int i=result.size()-1; i>=0; i--) {
            result[i] = most_recent.top().second;
            most_recent.pop();
        }
        return result;
    }
    
    // O(1)
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        user_followees[followerId].insert(followeeId);
    }
    
    // O(1)
    void unfollow(int followerId, int followeeId) {
        user_followees[followerId].erase(followeeId);
    }
};
