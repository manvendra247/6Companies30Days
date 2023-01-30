class Solution {
public:
    struct myComp {
    constexpr bool operator()(
        pair<int, string> const& a,
        pair<int, string> const& b)
        const noexcept
    {
        if(a.first==b.first){
            return a.second > b.second;
        }
        else return a.first<b.first;
    }
};
    vector<string> topKFrequent(vector<string>& words, int k) {
        sort(words.begin(),words.end());
        int n= words.size();
        int currFrequency= 1;
        priority_queue<pair<int,string>, vector<pair<int,string>> , myComp > pq;
        
        for(int i = 0;i<words.size();i++){
            if(i!=n-1&&words[i]==words[i+1]) currFrequency++;
            else{
                pq.push({currFrequency,words[i]});
                currFrequency = 1;
            } 
        }
        vector<string>op;
        while(k--){
            op.push_back(pq.top().second);
            pq.pop();
        }
        return op;
    }
};