import java.lang.ref.ReferenceQueue;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {

    public static void main(String[] args) {
	    Object counter = new Object();
        ReferenceQueue refQueue = new ReferenceQueue();
        counter = null;
        System.gc();
        String words = "Hello World";
        List<String> list = Arrays.asList(words.split(" "));
        long count = list.stream().filter(s -> s.length() > 5).max();
        System.out.println(count);
        Object[] objects = list.stream().toArray(String[]::new);
    }
}
