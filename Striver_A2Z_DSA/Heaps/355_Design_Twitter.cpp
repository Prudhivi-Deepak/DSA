// class user{
//     map<int, int, greater<int>> tweetsIds;
//     map<int, int, greater<int>> feed;
//     vector<int> followers;
//     vector<int> followee;
// }

#include <bits/stdc++.h>
using namespace std;

class Twitter {
    public:
        unordered_map<int, map<int, int, greater<int>> > user_tweets;
        unordered_map<int,unordered_set<int>> user_followeeids;
        int timestamp;
        Twitter() {
            this->timestamp = 0;
            this->user_tweets = {};
            this->user_followeeids = {};
        }
        
        void postTweet(int userId, int tweetId) {
            this->timestamp = this->timestamp +1;
            this->user_tweets[userId].insert({this->timestamp,tweetId});
        }
        
        vector<int> getNewsFeed(int userId) {
            map<int,int, greater<int>> feed = this->user_tweets[userId];
            unordered_set<int> following = this->user_followeeids[userId];
            
            for(int i: following){
                feed.insert(this->user_tweets[i].begin(), this->user_tweets[i].end());
            }
    
            vector<int> top_ten_tweets;
            int cnt = 0;
            for(auto i=feed.begin(); i!=feed.end();i++){
                cnt++;
                top_ten_tweets.push_back(i->second);
                if(cnt==10) break;
            }
    
            return top_ten_tweets;
        }
        
        void follow(int followerId, int followeeId) {
            if(followerId != followeeId)
                this->user_followeeids[followerId].insert(followeeId);
        }
        
        void unfollow(int followerId, int followeeId) {
            if(followerId != followeeId)
                this->user_followeeids[followerId].erase(followeeId);
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