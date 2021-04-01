class Solution {
public:
    string convertToTitle(int columnNumber) {
        int temp = columnNumber, currChar;
        string columnTitle;
        while (temp > 0){
            currChar = temp % 26;
            if(currChar == 0)
                currChar = 26;
            columnTitle.insert(columnTitle.begin(), currChar + 'A' - 1);
            temp = (temp - currChar) / 26;
        }
        return columnTitle;
    }
};
