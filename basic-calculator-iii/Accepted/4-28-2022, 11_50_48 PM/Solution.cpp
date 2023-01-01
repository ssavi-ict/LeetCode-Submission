// https://leetcode.com/problems/basic-calculator-iii

class Solution {
public:
    unordered_map<char, int> signedPrior;
    
    long long strToNum(string &s, int l, int r)
    {
        long long num = 0;
        for(int i=l ; i<=r ; i++){
            long long digit = s[i] - '0';
            num *= 10;
            num += digit;
        }
        return num;
    }
    
    long long FuN(string &s, int l, int r)
    {
        long long partitionIdx = 1e9, mnPrior = 1e9, openBracket = 0, num = 0;
        for(int i=l ; i<=r ; i++){
            if(s[i] >= '0' && s[i] <= '9'){
                continue;
            }
            else if(s[i] == '(')
                openBracket++;
            else if(s[i] == ')')
                openBracket--;
            else if(!openBracket){
                if(signedPrior[s[i]] <= mnPrior){
                    mnPrior = signedPrior[s[i]];
                    partitionIdx = i;
                }
            }
        }
        //cout<<l<<' '<<r<<' '<<mnPrior<<' '<<partitionIdx<<endl;
        
        if(mnPrior == 1e9 && s[l] == '(' && s[r] == ')')
            return FuN(s, l+1, r-1);
        else if(mnPrior == 1e9)
            return strToNum(s, l, r);
        else{
            long ret1 = FuN(s, l, partitionIdx-1);
            long ret2 = FuN(s, partitionIdx+1, r);
            if(mnPrior == 1)
                return ret1 + ret2;
            else if(mnPrior == 2)
                return ret1 - ret2;
            else if(mnPrior == 3)
                return ret1 / ret2;
            else
                return ret1 * ret2;
        }
    }
    
    int calculate(string s) {
        int n = s.size();
        signedPrior['+'] = 1;
        signedPrior['-'] = 2;
        signedPrior['/'] = 3;
        signedPrior['*'] = 4;
        return FuN(s, 0, n-1);
    }
};