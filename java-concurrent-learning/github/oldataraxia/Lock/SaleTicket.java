package github.oldataraxia.Lock;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class Ticket {
    // sum of all the tickets
    private  int number = 30;

    // 可重入锁
    private final ReentrantLock lock = new ReentrantLock();
    public void sale() {
        lock.lock();
        try {
            if(number > 0) {
                System.out.println(Thread.currentThread().getName() + "卖出了第" + number-- + "张票" + " 剩余: " + number);
            }
        }finally {
            lock.unlock();
        }
    }
}

public class SaleTicket {
    public static void main(String[] args) {
        Ticket ticket = new Ticket();
        new Thread(() -> {
            for(int i = 0; i < 30; i++) {
                ticket.sale();
            }
        }, "AA").start();
        new Thread(() -> {
            for(int i = 0; i < 30; i++) {
                ticket.sale();
            }
        }, "BB").start();
        new Thread(() -> {
            for(int i = 0; i < 30; i++) {
                ticket.sale();
            }
        }, "CC").start();
    }
}


class Test {
    private final Lock rtl = new ReentrantLock();
    int value;

    public int get() {
        rtl.lock();
        try {
            return value;
        } finally {
            rtl.unlock();
        }
    }

    public void addOne() {
        rtl.lock();
        try {
            value = 1 + get();
        } finally {
            rtl.unlock();
        }
    }
}