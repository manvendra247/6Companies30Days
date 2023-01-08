class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                long long int val ;
                switch(tokens[i].back()){
                    case '+': val = a+b;
                        break;
                    case '-': val = b-a;
                        break;
                    case '*': val = a*1LL*b;
                        break;
                    case '/': val = b/a;
                        break;
                }
                st.push(val);
            }else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
}; 