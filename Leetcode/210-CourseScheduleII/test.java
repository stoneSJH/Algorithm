
public class test {
	public static void main (String[] arg){
		int num = 2;
		int[][] re = new int[1][2];
		re[0][0] = 1;
		re[0][1] = 0;
		Solution sol = new Solution();
		int[] result = sol.findOrder(num, re);
		if (result == null) System.out.println("null");
		for (int i = 0; i < result.length; i++){
			System.out.println(result[i]);
		}
	}
}
