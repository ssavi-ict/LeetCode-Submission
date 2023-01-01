// https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution {
public:
    
    int to_int(string & number){
        int result = 0, n = number.size(), i = 0;
        if(number[i] == '-') i++;
        while(i < n){
            result *= 10;
            result += (number[i++] - '0');
        }
        if(number[0] == '-') result = -result;
        return result;
    }

    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int>op_str;
        int i = 0;
        while(i<n){
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/"){
                int number = to_int(tokens[i]);
                op_str.push(number);
            }
            else{
                int op1 = op_str.top(); op_str.pop();
                int op2 = op_str.top(); op_str.pop();
                int result;
                if(tokens[i] == "+"){
                    result = op1 + op2; 
                }
                else if(tokens[i] == "-"){
                    result = op2 - op1;
                }
                else if(tokens[i] == "*"){
                    result = op1 * op2;
                }
                else result = op2 / op1;
                op_str.push(result);
            }
            i++;
        }
        return op_str.top();
    }
};