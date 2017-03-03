class Solution {
    int min3(int a, int b, int c) {
        return min(min(a, b), c);
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (!matrix.size() || !matrix[0].size())
            return 0;
        vector<vector<int>> maxSquareSize(matrix.size(), vector<int>(matrix[0].size(), 0));
        
        for (int i=0; i<matrix.size(); i++)
            maxSquareSize[i][0] = (matrix[i][0] == '1') ? 1 : 0;
        for (int j=0; j<matrix[0].size(); j++)
            maxSquareSize[0][j] = (matrix[0][j] == '1') ? 1 : 0;
        
        for (int i=1; i<matrix.size(); i++) {
            for (int j=1; j<matrix[0].size(); j++) {
                if (matrix[i][j] == '0')
                    maxSquareSize[i][j] = 0;
                else
                    maxSquareSize[i][j] = min3(maxSquareSize[i][j-1], maxSquareSize[i-1][j-1], maxSquareSize[i-1][j]) + 1;
            }
        }
        int maxSize = 0;
        
        for (int i=0; i<maxSquareSize.size(); i++) {
            for (int j=0; j<maxSquareSize[0].size(); j++) {
                if (maxSquareSize[i][j] > maxSize)
                    maxSize = maxSquareSize[i][j];
            }
        }
        
        return maxSize*maxSize;
    }
};