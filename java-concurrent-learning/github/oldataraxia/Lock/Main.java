package github.oldataraxia.Lock;

import java.util.concurrent.locks.StampedLock;

public class Main {
    final static StampedLock s = new StampedLock();

    public static void main(String[] args) {
        long stemp = s.readLock();
        try{
            // do something
        } finally{
            s.unlockRead(stemp);
        }

        long wtemp = s.writeLock();
        try {
            // do something
        } finally {
            s.unlockWrite(wtemp);
        }
    }
}

class Point {
    private int x, y;
    final StampedLock s1 = new StampedLock();
    int distanceFromOrigin() {
        // 乐观读
        long stamp = s1.tryOptimisticRead();
        int curX = x, curY = y;
        if(!s1.validate(stamp)) {
            stamp = s1.readLock();
            try {
                curX = x;
                curY = y;
            } finally {
                s1.unlockRead(stamp);
            }
        }
        return (int) Math.sqrt(curX * curX + curY * curY);
    }
}

