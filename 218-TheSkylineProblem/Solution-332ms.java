import java.util.ArrayList;
import java.util.List;

public class Solution {
    public List<int[]> getSkyline(int[][] buildings) {
        return getSkyline(buildings, 0, buildings.length-1);
    }
    private List<int[]> getSkyline(int[][] buildings, int low, int high){
        List<int[]> result = new ArrayList<>();
        if(low > high)
        	return result;
        if(low == high){
            result.add(new int[]{buildings[low][0], buildings[low][2]});//get the left-up key point
            result.add(new int[]{buildings[low][1], 0});//get the right-down key point
            return result;
        }
        int mid = (low + high) / 2;
        //divide and conquer
        //hold two list
        List<int[]> left = getSkyline(buildings, low, mid);
        List<int[]> right = getSkyline(buildings, mid+1, high);
        result = _findPoint(result, left, right);
        return result;
    }
    
    private List<int[]> _findPoint(List<int[]> result, List<int[]>_leftSide, List<int[]>_rightSide){
    	//lmax->max in _leftSide, rmax->max in _rightSide, hold this two value to get the max height
    	//cmax->the max in lmax&rmax
    	int lmax = 0, rmax = 0, cmax = 0, max = 0;
    	for (int i = 0, j = 0; i < _leftSide.size() || j < _rightSide.size(); ){
    		//always get the left point(becuz the key point always in the left -- which x is lower)
    		//if leftpoint.x < rightpoint.x the use leftpoint.x o.w. use rightpoint.x
    		//also deal with the boundary condition([xn,0])
    		if ((i < _leftSide.size() && j < _rightSide.size() && _leftSide.get(i)[0] < _rightSide.get(j)[0])
    				|| j >= _rightSide.size()){
    			lmax = _leftSide.get(i)[1];
    			cmax = Math.max(lmax, rmax);
    			if (cmax != max){
    				int[] tmp = new int[]{_leftSide.get(i)[0], cmax};
    				result.add(tmp);
    				max = cmax;
    			}
    			i++;
    		}
    		//same as above
    		else if ((i < _leftSide.size() && j < _rightSide.size() && _leftSide.get(i)[0] > _rightSide.get(j)[0])
    				|| i >= _leftSide.size()){
    			rmax = _rightSide.get(j)[1];
    			cmax = Math.max(lmax, rmax);
    			if (cmax != max){
    				int[] tmp = new int[]{_rightSide.get(j)[0], cmax};
    				result.add(tmp);
    				max = cmax;
    			}
    			j++;
    		}
    		//when leftpoint.x == rightpoint.x, we pick the y-higher one
    		//if so, both left and right is done, so i++ & j++ 
    		else if (i < _leftSide.size() && j < _rightSide.size() && _leftSide.get(i)[0] == _rightSide.get(j)[0]){
    			rmax = _rightSide.get(j)[1];
    			lmax = _leftSide.get(i)[1];
    			cmax = Math.max(rmax, lmax);
    			if (cmax != max){
    				int[] tmp = new int[]{_leftSide.get(i)[0], cmax};
    				result.add(tmp);
    				max = cmax;
    			}
    			i++;
    			j++;
    		}
    	}
    	return result;
    }
}