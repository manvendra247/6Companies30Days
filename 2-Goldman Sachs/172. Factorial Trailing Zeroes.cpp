class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        int n1 = n;
        for(int i=1;i<=5;i++){
            count += n1/5;
            n1/=5;
        }
        return count;
    }
};