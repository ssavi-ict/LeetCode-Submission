// https://leetcode.com/problems/minimum-window-substring

class Solution {
public:
    string minWindow(string s, string t) {
        int s_len = s.size(), t_len = t.size();
        if(t_len > s_len) return "";

        vector<int>frequency(62, INT_MIN);

        int counter = 0;
        for(int i=0; i<t_len; i++){
            if( frequency[t[i]-'A'] == INT_MIN){
                counter++; frequency[t[i]-'A'] = 0;
            }
            frequency[t[i]-'A']++;
        }

        int left = 0, right = 0;
        int min_window = s_len + 5, final_left = -1;
        while(right < s_len){
            if(frequency[s[right]-'A'] != INT_MIN){
                frequency[s[right]-'A']--;
                if(frequency[s[right]-'A'] == 0) counter--;
            }

            while(counter == 0){
                if(right-left+1 < min_window){
                    min_window = right - left + 1;
                    final_left = left;
                }
                if(frequency[s[left]-'A'] != INT_MIN){
                    frequency[s[left]-'A']++;
                    if(frequency[s[left]-'A'] > 0) counter++;
                }
                left++;
            }
            right++;
        }
        if(min_window > s_len) return "";
        return s.substr(final_left, min_window);
    }
};