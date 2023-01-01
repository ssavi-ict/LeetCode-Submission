// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    vector<string>ansList;
    string arrList[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void rec(int idx, string str, int len, string cur){
        if(idx == len){
            // cout << cur <<endl;
            if(cur.size()) ansList.push_back(cur);
            return;
        }
        
        int number = (str[idx] - '0');
        // cout << number <<endl;
        for(int i=0; i<arrList[number].size(); i++){
            rec(idx+1, str, len, cur+arrList[number][i]);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        rec(0, digits, digits.size(), "");
        /*for(int i=0; i<ansList.size(); i++){
            cout << ansList[i] <<endl;
        }*/
        return ansList;
    }
};