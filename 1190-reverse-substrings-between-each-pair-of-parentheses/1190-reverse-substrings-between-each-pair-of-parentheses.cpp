class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        if(s.size()<=1)return s;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                string str="";
                while(st.top()!='('){
                    str+=st.top();
                    st.pop();
                }
                st.pop();
                for(int j=0;j<str.size();j++){
                    st.push(str[j]);
                }
            }else{
                st.push(s[i]);
            }
        }
        string res="";
        while(!st.empty()){
            if(st.top()!='(' && st.top()!=')')
                res+=st.top();
            st.pop();
        }
        //int n=s.size();
        reverse(res.begin(),res.end());
        return res;
    }
};