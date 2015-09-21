import java.io.IOException;


public class test {
	public static void main(String args[]) throws IOException {
		Solution so = new Solution();
		char [][]grid = new char [3][3];
		grid[0][0] = '1';
		grid[0][1] = '1';
		grid[0][2] = '1';
		grid[1][0] = '0';
		grid[1][1] = '1';
		grid[1][2] = '0';
		grid[2][0] = '1';
		grid[2][1] = '1';
		grid[2][2] = '1';
		System.out.println(so.numIslands(grid));
		
	}
}
