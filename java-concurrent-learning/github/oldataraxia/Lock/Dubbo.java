package github.oldataraxia.Lock;

import java.util.concurrent.TimeoutException;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Dubbo {
    private final Lock lock = new ReentrantLock();
    private final Condition condition = lock.newCondition();

    // 调用方等待结果
    Object get(int timeout) {
        long start = System.nanoTime();
        lock.lock();
        try {
            while(!isDone()) {
                done.await(timeout);
                long cur = System.nanoTime();
                if (isDone() || cur - start > timeout) {
                    break;
                }
            }
        }finally {
            lock.unlock();
        }
        if(!isDone()) {
            throw new TimeoutException();
        }
        return returnFromException();
    }

    bool isDone() {
        return response != null;
    }

    private void doReceived(Response res) {
        lock.lock();
        try {
            response = res;
            if (done != null) {
                done.signal();
            }
        } finally {
            lock.unlock();
        }
    }
}


