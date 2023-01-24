class Solution {
public:
    long long int side(vector<int>&p1, vector<int>&p2){
        int x = p2[0]-p1[0];
        int y = p2[1]-p1[1];
        return x*x+ y*y;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        map<long long int,int> sides;
        sides[side(p1,p2)]++;
        sides[side(p3,p2)]++;
        sides[side(p3,p4)]++;
        sides[side(p1,p3)]++;
        sides[side(p1,p4)]++;
        sides[side(p4,p2)]++;
        if(sides.size()==2&& (*sides.begin()).second==4 && (*(--sides.end())).second==2)return true;
    }
};