class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i = 0; i < s.length();){
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')'){
                if(!st.empty())
                    st.pop();
                else{
                    s.erase(s.begin() + i);
                    --i;
                }
            }
            ++i;
        }
        while(!st.empty()){
            int index = st.top();
            st.pop();
            s.erase(s.begin() + index);
        }
        return s;
    }
};
