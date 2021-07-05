class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() == 0)
            return 0;
        for(int i = 0; i < haystack.size(); ++i){
            if(haystack[i] == needle[0]){
                if(i + needle.size() - 1 > haystack.size())
                    return -1;
                bool flag = true;
                for(int j = 0; j < needle.size(); ++j){
                    if(needle[j] != haystack[i + j]){
                        flag = false;
                        break;
                    }
                }
                if(!flag)
                    continue;
                else return i;
            }
        }
        return -1;
    }
};
