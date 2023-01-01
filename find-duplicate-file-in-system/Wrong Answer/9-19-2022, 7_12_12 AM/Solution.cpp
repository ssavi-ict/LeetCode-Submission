// https://leetcode.com/problems/find-duplicate-file-in-system

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        int n = size(paths);
        unordered_map<string, vector<string>>umap;
        
        for(int i=0; i<n; i++){
            stringstream ss(paths[i]);
            string part, base_path = "";
            bool base = 0;
            while(ss >> part){
                if(base == 0){
                    base_path += part;
                }
                else{
                    int dir_length = size(part);
                    string file_name = "", file_content = "";
                    bool in_content = false;
                        
                    for(int j=0; j<dir_length; j++){
                        if(part[j] != '(' && !in_content){
                            file_name += part[j];
                        }
                        else if(part[j] == '(' || part[j] == ')') in_content = true;
                        else file_content += part[j];
                    }
                    file_name = base_path + "/" + file_name;
                    // cout<<file_name<<endl;
                    umap[file_content].push_back(file_name);
                }
                base = 1;
            }
        }
        
        vector<vector<string>>ans;
        for(auto it = umap.begin(); it!=umap.end(); ++it){
            ans.push_back(it->second);
        }
        return ans;
    }
};