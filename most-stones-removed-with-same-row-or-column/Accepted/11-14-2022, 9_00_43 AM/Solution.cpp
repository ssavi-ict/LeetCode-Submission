// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column

class Solution {
public:

    void try_removing_stones(vector<vector<int>> & stones, vector<bool>&stone_removed, int current_stone, int total_stone){

        stone_removed[current_stone] = true;
        for(int i=0; i<total_stone; i++){
            if(stones[i][0] != stones[current_stone][0] && stones[i][1] != stones[current_stone][1]) continue;
            if(stone_removed[i] || current_stone == i) continue;
            try_removing_stones(stones, stone_removed, i, total_stone);
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = size(stones);
        vector<bool>stone_removed(n+1, false);
        int counter = 0;
        for(int i=0; i<n; i++){
            if(!stone_removed[i]){
                try_removing_stones(stones, stone_removed, i, n);
                counter++;
            }
        }
        return n - counter;
    }
};