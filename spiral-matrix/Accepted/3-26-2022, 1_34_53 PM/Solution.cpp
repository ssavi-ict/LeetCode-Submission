// https://leetcode.com/problems/spiral-matrix

class Solution
{
public:
    void storeValue(int cellNumber,int column,vector<vector<int>>& inputMatrix, vector<int>&result)
    {
        int rowIndex = cellNumber / column ;
        int columnIndex = cellNumber % column ;
        if(columnIndex == 0)
        {
            columnIndex = column;
            rowIndex--;
        }
        //cout<<rowIndex<<" "<<columnIndex<<" "<<cellNumber<<endl;
        result.push_back(inputMatrix[rowIndex][columnIndex-1]);
    }
    vector<int> spiralOrder(vector<vector<int>>& inputMatrix)
    {
        vector<int> result ;
        int row = inputMatrix.size();
        if( row == 0 ) return result ;
        int column = inputMatrix[0].size();
        int rowLimit = row-1, columnLimit = column, total = row * column, cellNumber = 0;

        while( rowLimit > 0 || columnLimit > 0)
        {
            for( int j = 1 ; j <= columnLimit && rowLimit >= 0 ; j++)
                storeValue(++cellNumber,column,inputMatrix,result);
            columnLimit--;

            for( int j = 1 ; j <= rowLimit && columnLimit >= 0 ; j++)
            {
                cellNumber += column;
                storeValue(cellNumber,column,inputMatrix,result);
            }
            rowLimit--;

            for( int j = 1 ; j <= columnLimit && rowLimit >= 0 ; j++)
                storeValue(--cellNumber,column,inputMatrix,result);
            columnLimit--;

            for( int j = 1 ; j <= rowLimit && columnLimit >= 0 ; j++)
            {
                cellNumber -= column;
                storeValue(cellNumber,column,inputMatrix,result);
            }
            rowLimit--;
        }
        return result;
    }
};