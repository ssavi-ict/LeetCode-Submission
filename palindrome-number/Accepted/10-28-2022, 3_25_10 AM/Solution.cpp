// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x < 10) return true;
        vector<int>myVector;
        int number = x;

        while(number){
            myVector.push_back(number % 10);
            number /= 10;
        }

        int n = myVector.size();
        for(int i=0; i<n/2; i++){
            if(myVector[i] != myVector[n-i-1]) return false;
        }
        return true;
    }
};