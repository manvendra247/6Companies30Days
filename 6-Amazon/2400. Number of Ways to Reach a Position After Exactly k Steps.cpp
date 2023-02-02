class Solution {
public:
    const int M = 1e9+7;
    int power(long long int a,int p){
        if(p==0)return 1;
        long long int x= power(a,p/2);
        if(p%2)return (((x*x)%M)*a)%M;
        return (x*x)%M;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        int x = (k-abs(endPos-startPos));
        if(x<0|| x%2==1)return 0;
        vector<long long int>fact(k+1,0);
        fact[0]=1;
        for(int i=1;i<=k;i++){
            fact[i] = (fact[i-1]*i)%M;
        }
        int r = abs(endPos-startPos)+ x/2;
        int l = x/2;
        // return (fact[k]/((fact[l]*fact[r])))%M;
        
        // (A/B)%M = (A*B^-1)%M;
        // B^-1 = (B^M-2)%M;  calculate inverse;
        long long int binv = power((fact[r]*fact[l])%M,M-2);
        return (fact[k] * binv)%M;
        
    }
};