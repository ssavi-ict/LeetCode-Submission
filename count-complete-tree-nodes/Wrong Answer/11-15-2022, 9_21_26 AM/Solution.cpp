// https://leetcode.com/problems/count-complete-tree-nodes

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

    int getHeight(TreeNode * root){
        if(!root->left) return 0;
        return 1 + getHeight(root->left);
    }

    vector<int>getPath(int Node){
        vector<int>path;
        while(Node){
            path.emplace_back(Node);
            Node >>= 1;
        }
        return path;
    }

    bool checkPathExist(TreeNode * root, int leafMid){
        // cout<<leafMid<<endl;
        vector<int>trackPath = getPath(leafMid);
        int startFrom = size(trackPath) - 1;
        if(root->val != trackPath[startFrom]) return false;

        // for(int i=0; i<=startFrom; i++) cout<<trackPath[i]<<endl;

        while(root && startFrom > 0){
            // if(root->val != trackPath[startFrom]) return false;
            // cout<<"H "<<trackPath[startFrom - 1]<<endl;
            if(root->left && (root->left->val == trackPath[startFrom - 1])) root = root->left;
            else if(root->right && (root->right->val == trackPath[startFrom - 1])) root = root->right;
            else return false;
            startFrom--;
        }
        // cout<<"R "<<leafMid<<endl;
        return true;
    }

    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int height = getHeight (root);
        int leafLeft = (1<<height), leafRight = (1 << (height + 1)) - 1;
        // cout<<leafLeft<<' '<<leafRight<<endl;
        // int count = height + 1;
        while(leafLeft <= leafRight){
            int leafMid = leafLeft + (leafRight - leafLeft)/2;
            if(checkPathExist(root, leafMid)) leafLeft = leafMid + 1;
            else leafRight = leafMid - 1;
        }
        // if(checkPathExist(root, leafLeft)) return leafLeft;
        return leafRight;
    }
};