// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int mx_level;
    
    void solve(TreeNode * root, int vert, vector<vector<pair<int, int> > >&ans, int lvl){
        mx_level = max(mx_level, lvl);
        ans[vert].push_back(make_pair(lvl, root->val));
        if(root->left){
            solve(root->left, vert-1, ans, lvl+1);
        }
        if(root->right){
            solve(root->right, vert+1, ans, lvl+1);
        }
    }
    
    void get_level(TreeNode * root, int lvl, int & start_level, int & end_level){
        if(root->left){
            start_level = min(start_level, lvl-1);
            get_level(root->left, lvl-1, start_level, end_level);
        }
        
        if(root->right){
            end_level = max(end_level, lvl+1);
            get_level(root->right, lvl+1, start_level, end_level);
        }
    }
    
    vector<int>get_level_wise_sorted(vector< vector<pair<int ,int> > > &items, int column){
        map<int, vector<int>>level_value;
        vector<int>ret;
        
        for(int i=0; i<items[column].size(); i++){
            int c_level = items[column][i].first;
            int c_value = items[column][i].second;
            level_value[c_level].push_back(c_value);
        }
        
        for(auto it=level_value.begin(); it!=level_value.end(); ++it){
            sort(level_value[it->first].begin(), level_value[it->first].end());
            for(auto val: level_value[it->first]){
                ret.push_back(val);
            }
        }
        return ret;
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int start_level = 0, end_level = 0;
        get_level(root, 0, start_level, end_level);
        
        mx_level = 0;
        vector< vector<pair<int, int> > >rc_ans(end_level-start_level+1);
        solve(root, -start_level, rc_ans, 0);
        
        
        vector< vector<int>> ans;
        for(int i=0; i<rc_ans.size(); i++){
            ans.push_back(get_level_wise_sorted(rc_ans, i));
        }
        return ans;
    }
};