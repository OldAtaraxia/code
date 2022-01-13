import java.lang.ref.ReferenceQueue;

public class Main {

    public static void main(String[] args) {
	    Object counter = new Object();
        ReferenceQueue refQueue = new ReferenceQueue();
        counter = null;
        System.gc();
        String

    }
}
