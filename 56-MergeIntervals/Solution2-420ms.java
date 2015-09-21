import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


public class Solution2 {
	    public List<Interval> merge(List<Interval> intervals) {
	    	List<Interval> result = new ArrayList<Interval>();
	    	if (intervals.size() < 2)
	    		return intervals;
	    	Collections.sort(intervals, new IntervalComparator());
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
}
