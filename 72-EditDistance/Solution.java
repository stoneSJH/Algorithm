package PA72;

public class Solution {
    public int minDistance(String word1, String word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        int[][] dp = new int[l1+1][l2+1];
        for (int i = 0; i <= l1; i++)
        	for (int j = 0; j <= l2; j++){
        		dp[i][j] = Integer.MAX_VALUE;
        	}
        for (int i = 0; i <= l1; i++)
        	dp[i][0] = i;
        for (int j = 0; j <= l2; j++)
        	dp[0][j] = j;
        for (int i = 0; i < l1; i++)
        	for (int j = 0; j < l2; j++){
        		if(word1.charAt(i) == word2.charAt(j))
        			dp[i+1][j+1] = Math.min(dp[i][j], dp[i+1][j+1]);
        		else
        			dp[i+1][j+1] = Math.min(Math.min(dp[i][j]+1,  dp[i+1][j+1]), Math.min(dp[i][j+1], dp[i+1][j])+1);
        	}
        return dp[l1][l2];
    }
}