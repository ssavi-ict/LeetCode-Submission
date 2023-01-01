// https://leetcode.com/problems/minimum-window-substring

class Solution {
public:
    string minWindow(string s, string t) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int s_len = s.size(), t_len = t.size();
        if(s_len == 0 || t_len == 0 || s_len < t_len) return "";
        unordered_map<char, int>umap, check_map;
        for(int i=0; i<t_len; i++){
            umap[t[i]]++;
        }

        int left = 0, right = 0, char_size = umap.size();
        int l = -1, r = -1, min_window = s_len+ 5;

        bool r_increased = true;
        while(right < s_len){
            if(r_increased) check_map[s[right]]++;
            if(right - left + 1 < t_len){
                right++;
                continue;
            }
            
            r_increased = false;
            for(auto it=umap.begin(); it!=umap.end(); ++it){
                // cout<<right<<" "<<it->first<<' '<<it->second<<' '<<check_map[it->first]<<endl;
                if((left > right) || (check_map.find(it->first) == check_map.end()) || (check_map[it->first] < it->second)){
                    right++;
                    r_increased = true;
                    break;
                }
            }

            if(!r_increased){
                // cout<<right<<' '<<left<<endl;
                if(min_window > (right - left + 1)){
                    min_window = right - left + 1;
                    l = left, r = right;
                }
                check_map[s[left]]--;
                // cout<<"R "<<s[left]<<' '<<check_map[s[left]]<<endl;
                // if(check_map[s[left]] == 0) check_map.erase(s[left]);
                left++;
                r_increased = false;
            }
        }

        // cout<<l<<' '<<r<<endl;

        for(int i=left; i<s_len; i++){
            bool isReq = false;
            for(auto it=umap.begin(); it!=umap.end(); ++it){
                if(check_map[it->first] < it->second){
                    isReq = true;
                    break;
                }
            }
            if(isReq) break;
            check_map[s[i]]--;
            if((s_len - i + 1) > min_window){
                min_window = s_len - i + 1;
                l = i, r = s_len - 1;
            }
        }

        // cout<<l<<' '<<r<<' '<<min_window<<endl;
        if(min_window > s_len) return "";
        return s.substr(l, min_window);
    }
};