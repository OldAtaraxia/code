import java.util.List;
import java.util.Vector;
import java.util.concurrent.Semaphore;
import java.util.function.Function;

public class ObjectPool<T, R> {
    final List<T> pool;
    final Semaphore sem;
    ObjectPool(int size, T t) {
        pool = new Vector<T>(){};
        for(int i = 0; i < size; i++) {
            pool.add(t);
        }
        sem = new Semaphore(size);
    }
    R exec(Function<T, R> func) {
        T t = null;
        sem.acquire();
        try {
            t = pool.remove(0);
            return func.apply(t);
        } finally {
            pool.add(t);
            sem.release();
        }
    }
}

class Test {
    public static void main(String[] args) {
        ObjectPool<Long, String> pool = new ObjectPool<Long, String>(10, 0);
        pool.exec(t -> {
            System.out.println(t);
            return t.toString();
        })
    }
}
