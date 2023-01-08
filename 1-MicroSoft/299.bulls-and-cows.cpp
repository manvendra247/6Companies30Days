class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0,cows = 0;
        int digits1[10] = {0};
        int digits2[10] = {0};
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i])bulls++;
            else{
                digits1[secret[i]-'0']++;
                digits2[guess[i]-'0']++;
            }
        }
        for(int i = 0;i<10;i++)cows+=min(digits1[i],digits2[i]);
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};  