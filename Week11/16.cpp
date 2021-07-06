class Solution {
public:
    int countSegments(string s) {
        if(s.size() == 0)
            return 0;
        int num = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == ' ' && num){
                ++num;
                while(i < s.size() && s[i] == ' ')
                    ++i;
                if(i == s.size())
                    --num;
                --i;
            }
            else if(s[i] != ' ' && num == 0)
                num = 1;
        }
        return num;
    }
};
