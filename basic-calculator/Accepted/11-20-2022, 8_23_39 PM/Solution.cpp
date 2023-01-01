// https://leetcode.com/problems/basic-calculator

class Solution {
public:
    const long long plus = 1e15;
    const long long minus = 1e16;

    int calculate(string s) {
        s = "(" + s + ")";
        stack<long long>mystack;
        long long number = 0, sign = 1, result = 0;

        for(int i=0; i<s.size(); i++){
            if(isdigit(s[i])){
                number = number * 10 + (int)(s[i] - '0');
            }
            else if(s[i] == '-'){
                result += (sign * number);
                sign = -1;
                number = 0;
            }
            else if(s[i] == '+'){
                result += (sign * number);
                sign = 1;
                number = 0;
            }
            else if(s[i] == '('){
                mystack.push(result);
                mystack.push((sign == 1) ? plus : minus);
                sign = 1; result  = 0;
            }
            else if(s[i] == ')'){
                result += (sign * number);
                long long st_top = mystack.top();
                mystack.pop();
                if(st_top == plus) result *= 1;
                else result *= -1;
                st_top = mystack.top(); mystack.pop();
                result += st_top;
                number = 0; sign = 1;
            }
        }
        return (int)result;
    }
};


