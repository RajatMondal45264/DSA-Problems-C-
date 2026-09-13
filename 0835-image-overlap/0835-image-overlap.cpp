class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int maxOverlap = 0;


        // Try Every Possible row Shift 
        for(int rowShift = -(n-1); rowShift <= n-1; rowShift++)
        {
            // Try all Possible columns Shift 
            for(int colShift = -(n-1); colShift <= n-1; colShift++)
            {
                int overlap = 0;
                //compare All cell
                for(int i = 0; i< n; i++)
                {
                    for(int j = 0;j< n; j++)
                    {
                        int newRow = i + rowShift;
                        int newCol = j + colShift;

                        if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n)
                        {
                            if(img1[i][j] == 1 && img2[newRow][newCol] == 1)
                            {
                                overlap++;
                            }
                        }
                    }
                }

                maxOverlap = max(maxOverlap , overlap);
            }
        }

        return maxOverlap;
    }
};