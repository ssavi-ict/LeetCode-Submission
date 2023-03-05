/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    
    pair<int, int> build_grid(vector<vector<int>> & grid, int x_start, int y_start, int end_x, int end_y){
        // cout<<"Build "<<x_start<<' '<<y_start<<' '<<end_x<<' '<<end_y<<endl;
        int one = 0, zero = 0;
        for(int i=x_start; i<end_x; i++){
            for(int j=y_start; j<end_y; j++){
                if(grid[i][j]) one++;
                else zero++;
            }
        }
        // cout<<one<<' '<<zero<<endl;
        return {one, zero};
    }

    Node* build(Node * root,  vector<vector<int>>& grid, int start_x, int start_y, int end_x, int end_y) {
        pair<int, int>counter = build_grid(grid, start_x, start_y, end_x, end_y);

        if(counter.first == 0 || counter.second == 0){
            Node * ret_node = new Node();
            ret_node->isLeaf = true;
            ret_node->val = grid[start_x][start_y];
            return ret_node;
        }

        int mid_x = (end_x - start_x) / 2;
        int mid_y = (end_y - start_y) / 2;
        root->val = grid[start_x][start_y];
        root->isLeaf = false;
        if(!root->isLeaf) root->val = 1;

        root->topLeft = new Node();
        root->topRight = new Node();
        root->bottomLeft = new Node();
        root->bottomRight = new Node();

        root->topLeft = build(root->topLeft, grid, start_x, start_y, start_x+mid_x, start_y+mid_y);
        root->topRight = build(root->topRight, grid, start_x, start_y+mid_y, start_x+mid_x, end_y);
        root->bottomLeft = build(root->bottomLeft, grid, start_x+mid_x, start_y, end_x, start_y+mid_y);
        root->bottomRight = build(root->bottomRight, grid,  start_x+mid_x, start_y+mid_y, end_x, end_y);
        return root;
    }

    Node* construct(vector<vector<int>>& grid) {
        Node * root = new Node();
        int n = grid.size(), m = grid[0].size();
        return build(root, grid, 0, 0, n, m);
    }
};
