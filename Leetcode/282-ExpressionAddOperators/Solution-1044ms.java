import java.util.ArrayList;
import java.util.List;

public class Solution {
    public List<String> addOperators(String num, int target) {
        List<String> result = new ArrayList<String>();
        DFS(result, 0, target, "", num, 0);
        return result;
    }
    private void DFS(List<String> result, long totalValue, int target, String currentState,
    					String toDeal, long lastStep){
    	if (toDeal.length() == 0){
    		if (totalValue == target)
    			result.add(currentState);
    		return;
    	}
    	
    	for (int i = 1; i <= toDeal.length(); i++){
    		String component = toDeal.substring(0, i);
    		if (component.length() > 1 && component.charAt(0) == '0'){
    			return;
    		}
    		String left = toDeal.substring(i);
    		if (currentState.length() > 0){
    			DFS(result, totalValue+Long.valueOf(component), target, 
    					currentState+"+"+component, left, Long.valueOf(component));
    			DFS(result, totalValue-Long.valueOf(component), target,
    					currentState+"-"+component, left, -1*Long.valueOf(component));
    			DFS(result, totalValue-lastStep+lastStep*Long.valueOf(component), target,
    					currentState+"*"+component, left, lastStep*Long.valueOf(component));
    		}
    		else
    			DFS(result, Long.valueOf(component), target,
    					component, left, Long.valueOf(component));
    	}
    }
}