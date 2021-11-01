public class SafeCalc {
    long value = 0;
    synchronized long get() {
        return value;
    }
    synchronized void addOne() {
        value += 1;
    }
}
