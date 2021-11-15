import java.util.List;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class BlockedQueue<T> {
    final int maxSize = 10;
    public List<T> items;
    final Lock lock = new ReentrantLock();
    // condition variable for waiting
    final Condition notFull = lock.newCondition();
    final Condition notEmpty = lock.newCondition();

    // 入队
    void enq(T x) {
        lock.lock();
        try {
            while (items.size() == maxSize) {
                // items is full, wait
                // wait until notFull condition is signaled
                notFull.await();
            }
            items.add(x);
            notEmpty.signal();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        } finally {
            lock.unlock();
        }
    }
    // 出队
    T deq() {
        lock.lock();
        try {
            while (items.size() == 0) {
                // items is empty, wait
                // wait until notEmpty condition is signaled
                notEmpty.await();
            }
            T x = items.remove(0);
            notFull.signal();
            return x;
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        } finally {
            lock.unlock();
        }
    }


}
