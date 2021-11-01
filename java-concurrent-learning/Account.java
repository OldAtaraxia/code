import java.util.ArrayList;
import java.util.List;

class Allocator {
    private static List<Object> als = new ArrayList<>();
    // 一次申请所有资源
    synchronized boolean apply(Object from, Object to) {
        if(als.contains(from) || als.contains(to)) {
            return false;
        } else {
            als.add(from);
            als.add(to);
        }
        return true;
    }
    // 归还资源
    synchronized void free(Object from, Object to) {
        als.remove(from);
        als.remove(to);
    }
}

public class Account {
    private int id;
    private int balance;
    // 转账 按照从小到大的顺序锁定账户
    void tranfer(Account target, int amt) {
        Account left = this;
        Account right = target;
        if(this.id > target.id) {
            left = target;
            right = this;
        }
        synchronized (left) {
            synchronized (right) {
                if (this.balance > amt) {
                    this.balance -= amt;
                    target.balance += amt;
                }
            }
        }
    }
}
