import java.util.ArrayList;
import java.util.List;

class Allocator {
    private List<Object> als;
    synchronized void apply(Object from, Object to) {
        while(als.contains(from) || als.contains(to)) {
            try{
                wait();
            }catch (Exception e) {
                e.printStackTrace();
            }
            als.add(from);
            als.add(to);
        }
    }

    synchronized void free(Object from, Object to) {
        als.remove(from);
        als.remove(to);
        notifyAll();
    }
}
