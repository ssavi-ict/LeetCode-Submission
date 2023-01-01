// https://leetcode.com/problems/binary-tree-vertical-order-traversal

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
    
    vector< pair<int, int> >mapped[101];
    
    int mx, mn, mxDepth;
    void solve(TreeNode *root, int lvl, int depth){
        if(!root) return;
        
        mx = max(mx, lvl); 
        mn = min(mn, lvl);
        mxDepth = max(mxDepth, depth);
        mapped[depth].push_back(make_pair(root->val, lvl));
        
        if(root->left){
            solve(root->left, lvl-1, depth+1);
        }
        if(root->right){
            solve(root->right, lvl+1, depth+1);
        }
    }
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        mx = -101, mn = 101, mxDepth = -1;
        solve(root, 0, 0);
        vector< vector<int>>ans;
        if(root){
            int offset = -mn;
            ans.resize(-mn+mx+1);
            for(int i=0; i<=mxDepth; i++){
                for(int j=0; j<mapped[i].size(); j++){
                    int node = mapped[i][j].first, val = mapped[i][j].second;
                    ans[val+offset].push_back(node);
                }
            }
        }
        return ans;
    }
};

/*

root(3, 0, mapped) => mapped[0] = {3, 0} | mx = 0, mn = 0
left-> (9, -1, mapped) => mapped[1] = {9, -1} | mx = 0, mn = -1
left-> (4, -2, mapped) => mapped[2] = {4, -2} | mx = 0, mn = -2
right->(0, 0, mapped) => mapped[3] = {0, 0} | mx = 0, mn = -2
right->(8, 1, mapped) => mapped[4] = {8, 1} | mx = 1, mn = -2
left->(1, 0, mapped) => mapped[5] = {1, 0} | mx = 1, mn = -2
right->(7, 2, mapped) => mapped[6] = {7, 2} | mx = 2, mn = -2

offset = -(-2) = 2
ans[2] = {3, 0, 1}
ans[1] = {9}
ans[0] = {4}
ans[3] = {8}
ans[4] = {7}

*/






