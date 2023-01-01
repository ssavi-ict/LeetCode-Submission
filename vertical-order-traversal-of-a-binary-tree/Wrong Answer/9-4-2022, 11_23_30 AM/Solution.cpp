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
     
    void solve(TreeNode * root, int vert, vector<vector<pair<int, int> > >&ans, int lvl){
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
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int start_level = 0, end_level = 0;
        get_level(root, 0, start_level, end_level);
        
        // cout<<start_level<<' '<<end_level<<endl;
        vector< vector<pair<int, int> > >rc_ans(end_level-start_level+1);
        solve(root, -start_level, rc_ans, 0);
        
        
        vector< vector<int>> ans(end_level - start_level + 1);
        for(int i=0; i<rc_ans.size(); i++){
            vector<int>sorted_list;
            int pre_level = -1;
            for(int j=0; j<rc_ans[i].size(); j++){
                if(rc_ans[i][j].first != pre_level){
                    pre_level = rc_ans[i][j].first;
                    if(sorted_list.size() > 0){
                        sort(sorted_list.begin(), sorted_list.end());
                        for(auto it: sorted_list){
                            ans[i].push_back(it);
                        }
                    }
                    sorted_list.clear();
                }
                
                if(rc_ans[i][j].first == pre_level){
                    sorted_list.push_back(rc_ans[i][j].second);
                }
                
            }
            if(sorted_list.size() > 0){
                // cout<<1<<endl;
                sort(sorted_list.begin(), sorted_list.end());
                for(auto it: sorted_list){
                    ans[i].push_back(it);
                }
            }
            // cout<<'1'<<endl;
        }
        return ans;
    }
};