class TweetCounts {
public:
    TweetCounts() {
        
    }
    unordered_map<string, map<int,int>> mp;
    void recordTweet(string tweetName, int time) {
        mp[tweetName][time]++;
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int d = 60;
        if(freq=="hour")d=3600;
        else if (freq=="day")d=86400;
        vector<int> min((endTime-startTime)/d+1,0);
        auto s =mp[tweetName];
        auto itr1 = s.upper_bound(startTime-1);
        auto itr2 = s.upper_bound(endTime);
        for(auto it = itr1;it!=s.end()&&it!=itr2;it++){
            min[(((*it).first-startTime)/d)]+=(*it).second;
        }
        return min;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */