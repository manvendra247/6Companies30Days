class StockPrice {
public:
    StockPrice() {
        
    }
    map<int,int> mp;
    map<int,int>s;
    void update(int timestamp, int price) {
        if(mp.find(timestamp)!=mp.end()){
            s[mp[timestamp]]--;
            if(s[mp[timestamp]]==0)s.erase(mp[timestamp]);
        }
        mp[timestamp]=price;
        s[price]++;
    }
    
    int current() {
        auto it = mp.end();
        return (*--it).second;
    }
    
    int maximum() {
        auto it = s.end();
        return (*(--it)).first;
    }
    
    int minimum() {
        return (*s.begin()).first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */