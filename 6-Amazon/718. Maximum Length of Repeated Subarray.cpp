class Solution {
public:
    const int M = 1e9+7;
    // rolling hash;
    int power(int n){
        if(n==0)return 1;
        long long int a = power(n/2);
        if(n%2)return (((a*a)%M)*103)%M;
        return (a*a)%M;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int length = 0;
        for(int l=min(nums1.size(),nums2.size());l>0;l--){
            int t = l;
            int hash1=0;
            int i=0;
            unordered_set<int> s;
            for(;i<t;i++){
                hash1=(hash1*1ll*103 + nums1[i])%M;
            }
            int hash2=0;
            int j=0;
            for(;j<t;j++){
                hash2=(hash2*1ll*103 + nums2[j])%M;
            }
            if(hash1==hash2)return l;
            s.insert(hash1);
            while(i<nums1.size()){
                hash1=((hash1-nums1[i-t]*1ll*power(t-1))%M+M)%M;
                hash1= (hash1*1ll*103 + nums1[i])%M;
                s.insert(hash1);
                i++;
            }
            int hash3=hash2;
            int k= j;
            if(s.find(hash3)!=s.end())return l;
            while(k<nums2.size()){
                hash3=((hash3-nums2[k-t]*1ll*power(t-1))%M+M)%M;
                hash3=(hash3*1ll*103 + nums2[k])%M;
                if(s.find(hash3)!=s.end())return l;
                k++;
            }
        }
        return 0;
    }
};