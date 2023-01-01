// https://leetcode.com/problems/spiral-matrix

class Solution
{
public:
    
    vector<int> spiralOrder(vector<vector<int>>& Matrix)
    {
        vector<int> result ;
        if(Matrix.size() == 0) return result;
        int topRow = 0, bottomRow = Matrix.size()-1;
        int leftColumn = 0 , rightColumn = Matrix[0].size()-1;
        
        while( topRow <= bottomRow && leftColumn <= rightColumn)
        {
            for( int i = leftColumn ; i <= rightColumn ; i++) result.push_back(Matrix[topRow][i]);
            topRow++;
            for( int i = topRow ; i <= bottomRow ; i++) result.push_back(Matrix[i][rightColumn]);
            rightColumn--;
            if( topRow <= bottomRow){
                for( int i = rightColumn ; i >= leftColumn ; i--) result.push_back(Matrix[bottomRow][i]);
                bottomRow--;
            }
            if( leftColumn <= rightColumn){
                for( int i = bottomRow ; i >= topRow ; i--) result.push_back(Matrix[i][leftColumn]);
                leftColumn++;
            }
            
        }
        return result;
    }
};