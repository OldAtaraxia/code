package github.oldataraxia.Lock;

import java.util.Date;
import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReadWriteLock;
import java.util.concurrent.locks.ReentrantReadWriteLock;

public class Cache<K, V> {
    final Map<K, V> m= new HashMap<>();
    final ReadWriteLock rwl = new ReentrantReadWriteLock();
    final Lock r = rwl.readLock();
    final Lock w = rwl.writeLock();

    V get(K key) {
        V v = null;
        r.lock();
        try {
            v = m.get(key);
        } finally {
            r.unlock();
        }

        if (v != null) {
            // 缓存中存在v
            return v;
        }
        w.lock();
        try {
            v = m.get(key);
            if (v == null) {
                // 查询数据库
                v = db.get(key);
                m.put(key, v);
            }
         } finally {
            w.unlock();
        }
        return v;
    }

    V put(String key, Date v) {
        w.lock();
        try {
            return m.put(key, v);
        } finally {
            w.unlock();
        }
    }
}

class CacheData {
    Object data;
    volatile boolean cacheValid;
    final ReadWriteLock rwl = new ReentrantReadWriteLock();
    final Lock r = rwl.readLock();
    final Lock w = rwl.writeLock();

    void processCacheData() {
        r.lock();
        if (!cacheValid) {
            r.unlock();
            w.lock();
            try {
                if (!cacheValid) {
                    data =  ...;
                    cacheValid = true;
                }
                r.lock();
            } finally {
                w.unlock();
            }
        }
        try {
            use(data);
        } finally {
            r.unlock();
        }
    }
}
