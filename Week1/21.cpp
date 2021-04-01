class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size(), colNo = 0;
        for(int i = 0; i < n; ++i){
            colNo = colNo * 26 + (columnTitle[i] - 'A' + 1);
        }
        return colNo;
    }
};
