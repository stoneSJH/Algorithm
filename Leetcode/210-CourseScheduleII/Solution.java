import java.util.ArrayList;
import java.util.List;



public class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int[][] graph = new int[numCourses][numCourses];
        for (int i = 0; i < numCourses; i++)
        	for (int j = 0; j < numCourses; j++)
        		graph[i][j] = -1;
        int[] state = new int[numCourses];
        List<Integer> result = new ArrayList<Integer>();
        int[] ret = new int[numCourses];
        if (numCourses == 1){
            return new int[0];
        }
        if (prerequisites.length == 0){
            return new int[0]; 
        }
        for (int i = 0; i < prerequisites.length; i++){
        	int j = 0;
        	for (; j < numCourses; j++)
        		if (graph[prerequisites[i][1]][j] == -1) break;
        	graph[prerequisites[i][0]][j] = prerequisites[i][1];
        }
        
        for (int i = 0; i < numCourses; i++){
        	if (!DFS(state, graph, i, result, numCourses)){
        		return new int[0];
        	}
        }
        for (int j = 0; j < result.size(); j++)
    	    ret[j] = result.get(j);
        return ret;
    }
    private boolean DFS(int[] state, int[][] graph, int pos, List<Integer> result, int numCourses){
    	if (state[pos] == 1) return true;
    	if (state[pos] == 2) return false;
    	
    	state[pos] = 2;
    	for (int i = 0; i < numCourses; i++){
    		if (graph[pos][i] != -1)
    			if (!DFS(state, graph, graph[pos][i], result, numCourses))
    				return false;	
    	}
    	state[pos] = 1;
    	result.add(pos);
    	return true;
    }
}