import java.util.ArrayList;
import java.util.List;


public class Solution {
	    public List<Interval> merge(List<Interval> intervals) {
	    	List<Interval> result = new ArrayList<Interval>();
	    	if (intervals.size() < 2)
	    		return intervals;
	    	quicksort(intervals);
	    	int begin = intervals.get(0).start;
	    	int end = intervals.get(0).end;
	    	int i = 1;
	    	while (i < intervals.size()){
	    		if (end >= intervals.get(i).start){
	    			if (end < intervals.get(i).end) 
	    				end = intervals.get(i).end;
	    		}
	    		else{
	    			Interval temp = new Interval(begin, end);
	    			result.add(temp);
	    			if (i < intervals.size()){
	    				begin = intervals.get(i).start;
	    				end = intervals.get(i).end;
	    			}
	    		}
	    		i++;
	    	}
	    	Interval temp = new Interval(begin, end);
	    	result.add(temp);
	    	return result;
	    }
    
    private int _find(List<Interval> intervals, int low, int high){
    	int middle = 0;
    	if (low < high){
    		Interval temp = intervals.get(low);
    		while (low < high){
    			while (low < high && temp.start <= intervals.get(high).start){
    				high--;
    			}
    			intervals.set(low, intervals.get(high));
    			while (low < high && temp.start >= intervals.get(low).start){
    				low++;
    			}
    			intervals.set(high, intervals.get(low));
    		}
    		intervals.set(low, temp);
    		middle = low;
    	}
    	return middle;
    }
    private void _quicksort(List<Interval> intervals, int low, int high){
    	if (low < high){
    		int middle = _find(intervals, low, high);
    		_quicksort(intervals, low, middle-1);
    		_quicksort(intervals, middle+1, high);
    	}
    }
    public void quicksort(List<Interval> intervals){
    	_quicksort(intervals, 0, intervals.size()-1);
    }
}