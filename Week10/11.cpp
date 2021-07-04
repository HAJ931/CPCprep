#include<bits/stdc++.h>
using namespace std;

bool isOperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

int retPrecedence(char c){
    if(c == '+' || c == '-')
        return 1;
    if(c == '*' || c == '/')
        return 2;
    return 0;
}

void performComputation(stack<int>& vals, stack<char>& ops){
    int val1, val2;
    char op;
    if(vals.size() < 2 || ops.empty())
        return;
    val2 = vals.top();
    vals.pop();
    val1 = vals.top();
    vals.pop();
    op = ops.top();
    ops.pop();
    switch(op){
        case '+':
            vals.push(val1 + val2);
            break;
        case '-':
            vals.push(val1 - val2);
            break;
        case '*':
            vals.push(val1 * val2);
            break;
        case '/':
            if(val2 != 0)
                vals.push(val1 / val2);
            else
                vals.push(0);
            break;
        default:
            vals.push(val1);
            vals.push(val2);
            break;
    }
}

int infixToPostfix(string infix){
    stack<int> val;
    stack<char> ops;
    for(int i = 0; i < infix.length(); ++i){
        //cout << "In iteration " << i << " of the loop\n";
        if(infix[i] == ' ')
            continue;
        if(infix[i] == '(')
            ops.push(infix[i]);
        else if(isdigit(infix[i])){
            int tempIndex = i, currVal = 0;
            while(tempIndex != infix.length() && isdigit(infix[tempIndex])){
                currVal *= 10;
                currVal += infix[tempIndex] - '0';
                ++tempIndex;
            }
            i = tempIndex - 1;
            cout << "Pushing: " << currVal << "\n";
            val.push(currVal);
        }
        else if(infix[i] == ')'){
            while(ops.top() != '('){
                performComputation(val, ops);
            }
            ops.pop();
        }
        else if(isOperator(infix[i])){
            while(!ops.empty() && retPrecedence(infix[i]) <= retPrecedence(ops.top())){
                performComputation(val, ops);
            }
            ops.push(infix[i]);
        }
        else return -1;
    }
    while(!ops.empty()){
        performComputation(val, ops);
    }
    return val.top();
}

int main(){
    string infix;
    cin >> infix;
    int ans = infixToPostfix(infix);
    cout << ans;
}
