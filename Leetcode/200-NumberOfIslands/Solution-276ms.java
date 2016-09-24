
public class Solution {
    public int numIslands(char[][] grid) {
        int result = 0;
        for (int i = 0; i < grid.length; i++){
        	for (int j = 0; j < grid[i].length; j++){
        		if (grid[i][j] == '1'){
        			result++;
        			DFS(grid, i, j);
        		}
        	}
        }
        return result;
    }
    
    private void DFS(char[][] grid, int i, int j){
    	if (i >= 0 && i < grid.length && j >= 0 && j < grid[i].length
    			&& grid[i][j] == '1'){
    		grid[i][j] = '2';
    		DFS(grid, i-1, j);
    		DFS(grid, i+1, j);
    		DFS(grid, i, j-1);
    		DFS(grid, i, j+1);
    	}
    	else return;
    }
}