class Solution {
public:
    int prob = 1;
    vector<vector<vector<int>>> vis;
    vector<vector<vector<double>>>t;
    double move(int n, int k , int r , int c){
        if(r<0||r>=n||c<0||c>=n||k<0)return 0;
        // if(k<0)return 0;
        if(vis[r][c][k]!=-1)return t[r][c][k];
        double count = 0;
        if(k==0){
            t[r][c][k]=1.0;
            return t[r][c][k];
        }
        count +=move(n, k-1,r+2,c-1);
        count +=move(n, k-1,r+2,c+1);
        count +=move(n, k-1,r-2,c-1);
        count +=move(n, k-1,r-2,c+1);
        count +=move(n, k-1,r-1,c+2);
        count +=move(n, k-1,r+1,c+2);
        count +=move(n, k-1,r-1,c-2);
        count +=move(n, k-1,r+1,c-2);
        vis[r][c][k]=1;
        // if(count==0){
        //     t[r][c][k]=0;
        // } 
        // else 
            t[r][c][k]= (count*1.0/8);
        return t[r][c][k];
        
    }
    double knightProbability(int n, int k, int row, int column) {
        // if(n==1&&k>0)return 0;
        vis.resize(n,vector<vector<int>>(n,vector<int>(k+1,-1)));
        t.resize(n,vector<vector<double>>(n,vector<double>(k+1,0)));
        return move(n,k,row,column);  
    }
};