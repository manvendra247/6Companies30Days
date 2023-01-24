class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans =0;
        int min_no = INT_MAX;
        int neg = 0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                if(matrix[i][j]<0)neg++;
                min_no = min(min_no, abs(matrix[i][j]));
                ans += abs(matrix[i][j]);
            }
        }
        if(neg&1){
            ans -= 2*min_no;
        }
        return ans;
    }
};