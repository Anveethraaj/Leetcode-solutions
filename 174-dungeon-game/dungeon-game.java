class Solution {
    public int calculateMinimumHP(int[][] A) {
        int r=A.length;
        int c=A[0].length;
        int dp[][]=new int[r][c];
        for(int i=r-1;i>=0;i--)
        {
            for(int j=c-1;j>=0;j--)
            {
                if(i==r-1 && j==c-1)
                {
                    dp[i][j]=A[i][j]>0?1:1-A[i][j];
                }
                else if(i==r-1)
                {
                    dp[i][j]=dp[i][j+1]-A[i][j]>0?dp[i][j+1]-A[i][j]:1;
                }
                else if(j==c-1)
                {
                    dp[i][j]=dp[i+1][j]-A[i][j]>0?dp[i+1][j]-A[i][j]:1;
                }
                else
                {
                    int mh=Math.min(dp[i][j+1],dp[i+1][j])-A[i][j];
                    dp[i][j]=mh>0?mh:1;
                }
            }
        }
        return dp[0][0];
    }
}