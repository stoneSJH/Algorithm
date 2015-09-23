import java.util.ArrayList;
import java.util.List;

public class Solution {
    public int numSquares(int n) {
    	List<Integer> result = new ArrayList<Integer>();
    	for (int i = 0; i <= n; i++){
    		result.add(0);
    	}
        for (int i = 1; i <= n; i++){
        	result.set(i, i);
        	for (int j = 0; j < Math.sqrt(i); j++){
        		result.set(i, Math.min(result.get(i), result.get((int) (i-Math.pow(j,2)))+1));
        	}
        }
        return result.get(n);
    }
}