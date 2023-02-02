class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxd=0;
        for(int i=0;i<right.size();i++){
            maxd=max(maxd,n-right[i]);
        }
        for(int i=0;i<left.size();i++){
            maxd=max(maxd,left[i]);
        }
        return maxd;
    }
};