import java.util.ArrayList;
import java.util.List;


public class test {
	public static void main(String[] arg){
		List<Interval> result = new ArrayList<Interval>();
		Interval test1 = new Interval(15,18);
		result.add(test1);
		Interval test2 = new Interval(1,4);
		result.add(test2);
		Interval test3 = new Interval(4,5);
		result.add(test3);
		Interval test4 = new Interval(6,10);
		result.add(test4);
		//Interval test5 = new Interval(2,16);
		//result.add(test5);
		Solution sol = new Solution();
		result = sol.merge(result);
		for (int i = 0; i < result.size(); i++)
			System.out.println("["+result.get(i).start+","+result.get(i).end+"]");
	}
}
