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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>>ans;
        queue<TreeNode *>treeNodes;
        treeNodes.push(root);
        bool isReverse = false;

        while(!treeNodes.empty()){
            int qSize = treeNodes.size();
            vector<int>nodeValues;
            while(qSize--){
                auto topNode = treeNodes.front();
                nodeValues.push_back(topNode->val);
                treeNodes.pop();
                if(topNode->left) treeNodes.push(topNode->left);
                if(topNode->right) treeNodes.push(topNode->right);
            }
            if(isReverse) reverse(nodeValues.begin(), nodeValues.end());
            isReverse = !isReverse;
            ans.push_back(nodeValues);
        }
        return ans;
    }
};