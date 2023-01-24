class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int x = bottom -1;
        int mc = 0;
        sort(special.begin(),special.end());
        for(auto el:special){
            mc = max(mc,el-x-1);
            x = el;
        }
        mc = max(mc,top-x);
        return mc;
    }
};