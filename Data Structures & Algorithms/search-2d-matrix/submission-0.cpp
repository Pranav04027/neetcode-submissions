class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int column = matrix[0].size();
        int row = matrix.size();

        int lowrow = 0;
        int highrow = row - 1;

        while(lowrow <= highrow){
            int midrow = highrow - (highrow - lowrow) / 2;

            if(target >= matrix[midrow][0] && target <= matrix[midrow][column-1]){
                int lowcol = 0;
                int highcol = column - 1;

                while(lowcol<=highcol){
                    int midcol = highcol - (highcol - lowcol)/2;
                    if(target == matrix[midrow][midcol]){
                        return true;
                    }else if(target>matrix[midrow][midcol]){
                        lowcol = midcol + 1;
                    }else{
                        highcol = midcol - 1;
                    }

                }



                return false;


            }else if(target < matrix[midrow][0]){
                highrow = midrow-1;
            }else{
                lowrow = midrow+1;
            }
        }

        return false;

    }
};