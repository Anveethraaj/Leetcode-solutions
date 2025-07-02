class Solution {
    public int uniquePathsWithObstacles(int[][] A) {
        int r=A.length;
        int c=A[0].length;
        int [][] dp=new int[r][c];
        for(int j=0;j<c;j++)
        {
            if(A[0][j]==1)
            break;
            dp[0][j]=1;
        }
        for(int i=0;i<r;i++)
        {
            if(A[i][0]==1)
            break;
            dp[i][0]=1;
        }
        for(int i=1;i<r;i++)
        {
            for(int j=1;j<c;j++)
            {
                if(A[i][j]==1)
                {
                    dp[i][j]=0;
                }
                else
                {
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
    return dp[r-1][c-1];
    }
}