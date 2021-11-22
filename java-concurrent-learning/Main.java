import java.util.concurrent.atomic.AtomicLong;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Main {
    static long var;
    private static Lock lock = new ReentrantLock();
    private static Object InterruptedException;

    public static void main(String[] args) throws InterruptedException {


        lock.lockInterruptibly();
    }
}