// https://leetcode.com/problems/path-with-minimum-effort

class Solution {
public:
    
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool isValid(int x, int y, int row, int col) {
        return x >= 0 && x < row && y >= 0 && y < col;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        int res = 0;
        
        priority_queue<Cell, vector<Cell>, Comparator> queue;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        queue.push(Cell(0, 0, 0));
        
        while(!queue.empty()) {
            Cell curr = queue.top();
            queue.pop();
            if(visited[curr.x][curr.y])
                continue;
            cout << curr.x << " " << curr.y << endl;
            visited[curr.x][curr.y] = true;
            res = max(curr.difference, res);
            if(curr.x == row-1 && curr.y == col-1)
                return res;

            for(auto direction: directions) {
                int adjX = curr.x + direction[0];
                int adjY = curr.y + direction[1];
                if(isValid(adjX, adjY, row, col) && !visited[adjX][adjY]) {
                    int diff = abs(heights[curr.x][curr.y] - heights[adjX][adjY]);
                    queue.push(Cell(adjX, adjY, diff));
                }
            }
        }
        return res;
        
        
    }
    
    class Cell {
        public:
            int x, y;
            int difference;
            Cell(int x, int y, int difference) {
                this->x = x;
                this->y = y;
                this->difference = difference;
            }
    };
    struct Comparator{
        bool operator()(Cell const& p1, Cell const& p2) {
            return p1.difference > p2.difference;
        }
    };
};