import java.util.Comparator;



class IntervalComparator implements Comparator<Interval> {
	@Override
    public int compare(Interval a, Interval b) {
        return a.start > b.start ? 1 : ((a.start == b.start) ? 0 : -1);
    }
}