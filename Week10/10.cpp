class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>s;
        long long i = 0, j = 0;
        while(true){
            if(i == pushed.size() && j == popped.size()){
                if(s.empty())
                    return true;
                else
                    return false;
            }
            while(i < pushed.size() && (s.empty() || s.top() != popped[j])){
                s.push(pushed[i]);
                ++i;
            }
            while(j < popped.size() && (!s.empty() && s.top() == popped[j])){
                s.pop();
                ++j;
            }
            if(i == pushed.size() && j < popped.size() && !s.empty())
                break;
        }
        return false;
    }
};
