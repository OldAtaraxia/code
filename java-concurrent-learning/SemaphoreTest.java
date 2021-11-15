import java.util.concurrent.Semaphore;

public class SemaphoreTest {
    static int count;
    static final Semaphore s = new Semaphore(1);
    static void addOne() throws InterruptedException {
        s.acquire();
        try {
            count += 1;
        } finally {
            s.release();
        }
    }
}
