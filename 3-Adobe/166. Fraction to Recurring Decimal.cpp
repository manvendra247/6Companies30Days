class Solution {
public:
    string fractionToDecimal(long long int numerator,long long int denominator) {
        string ans="";
        if(numerator*1ll*denominator<0){
            ans +='-';
        }
        numerator = abs(numerator);
        denominator = abs(denominator);
        string q = to_string(numerator/denominator);
        numerator = numerator%denominator;
        ans+=q;
        if(numerator==0)return ans;
        ans.push_back('.');
        numerator*=10;
        string temp = "";
        unordered_map<int,int>s;
        while(numerator){
            if(s.find(numerator)!=s.end()){
                temp.push_back(')');
                temp.insert(s[numerator],"(");
                break;
            }
            s.insert({numerator,temp.size()});
            if(numerator<denominator){
                temp.push_back('0');
            }else{
                temp += to_string(numerator/denominator);
                numerator = numerator%denominator;
            }
            numerator*=10;
        }
        
        return ans+temp;
    }
};