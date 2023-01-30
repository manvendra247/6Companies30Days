class Solution {
public:
    const int M = 1e9 +7;
    int pow(int x, int p){
        if(p==0)return 1;
        int a = pow(x,p/2);
        if(p%2)return (((a*1ll*a)%M)*x)%M;
        return ((a*1ll*a)%M)%M;
    }
    int distinctEchoSubstrings(string text) {
        unordered_set<int>s;
        int n = text.size();
        for(int l=1;l<=n/2;l++){
            int i =0;
            int hash1=0;
            int hash2=0;
            while(i<l){
                hash1 = ((hash1*1ll*27)%M+text[i])%M;
                i++;
            }
            while(i<2*l){
                hash2 = ((hash2*1ll*27)%M+text[i])%M;
                i++;
            }
            if(hash1==hash2){
                s.insert(hash1);
            }
            for(;i<n;i++){
                hash1 = ((hash1- text[i-2*l]*1ll*(pow(27,l-1)))%M+M)%M;
                hash1= (hash1*1ll*27 +text[i-l])%M;
                hash2 = ((hash2 - text[i-l]*1ll*(pow(27,l-1)))%M +M)%M;
                hash2= (hash2*1ll*27 +text[i])%M;
                if(hash1==hash2){
                    s.insert(hash1);
                }
            }
        }
        return s.size();
    }
};