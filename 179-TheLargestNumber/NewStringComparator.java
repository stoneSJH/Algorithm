package PA179;

import java.util.Comparator;

public class NewStringComparator implements Comparator<String> {

	@Override
	public int compare(String arg0, String arg1) {
		// TODO Auto-generated method stub
		String s1 = arg0 + arg1;
		String s2 = arg1 + arg0;
		int ret = s1.compareTo(s2);
		return (-1*ret);
	}

}
