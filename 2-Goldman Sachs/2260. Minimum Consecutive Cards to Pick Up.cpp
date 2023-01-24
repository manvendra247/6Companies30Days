class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_set<int>s;
        int j = 0, i =0;
        int size = INT_MAX;
        while(j<cards.size()){
            while(s.find(cards[j])!=s.end()){
                size = min(size,j-i+1);
                s.erase(cards[i]);
                i++;
            }
            s.insert(cards[j]);
            j++;
        }
        return size<INT_MAX?size:-1;
    }
};