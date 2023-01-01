// https://leetcode.com/problems/decode-string

class Solution {
public:

    int to_int(string s){
        int num = 0;
        for(int i=0; i<s.size(); i++){
            num = num * 10 + (s[i] - '0');
        }
        return num;
    }

    string concateNtime(int n, string s){
        string ret = "";
        while(n--){
            ret += s;
        }
        return ret;
    }

    string to_str(char ch){
        string s = "";
        s += ch;
        return s;
    }

    string decodeString(string s) {
        s = "[" + s + "]";  // [3[a]2[bc]]
        int n = s.size();   // 11
        string st = "", num = "";
        stack<string>myStack;
        // cout<<s<<endl;

        for(int i=0; i<n; i++){
            // cout<<i<<' '<<myStack.size()<<endl;
            if(s[i]>='a' && s[i]<='z'){
                st += s[i];
            }
            else if(s[i] >='0' && s[i]<='9'){
                // cout<<"St "<<st<<endl;
                if(st.size() > 0){
                    myStack.push(st); st.clear();
                }
                num += s[i];
            }
            else if(s[i] == '['){
                // cout<<"Num "<<num<<endl;
                if(num.size() > 0){
                    myStack.push(num); num.clear();
                }
                myStack.push(to_str(s[i]));
            }
            else{
                string new_str = st;
                st.clear();
                while(myStack.top() != "["){
                    // cout<<new_str<<" Top "<<myStack.top()<<endl;
                    if(myStack.top()[0] >= '0' && myStack.top()[0] <= '9'){
                        int concate = to_int(myStack.top());
                        new_str = concateNtime(concate, new_str);
                    }
                    else{
                        new_str = myStack.top() + new_str;
                    }
                    myStack.pop();
                    // myStack.push(new_str);
                }
                if(myStack.top() == "["){
                    myStack.pop();
                    if(!myStack.empty()){
                        int concate = to_int(myStack.top());
                        new_str = concateNtime(concate, new_str);
                        myStack.pop();
                    }
                }
                myStack.push(new_str);
            }
        }
        return myStack.top();
    }
};