package github.oldataraxia.Lock;

import java.util.concurrent.CountDownLatch;
import java.util.concurrent.Executor;
import java.util.concurrent.Executors;

public class check {
    public static void main(String[] args) throws InterruptedException {
        Executor executor = Executors.newFixedThreadPool(2);
        while (存在未对账订单) {
            // 计数器初始化为2
            CountDownLatch latch = new CountDownLatch(2);
            executor.execute(() -> {
                pos = getPOrders();
                latch.countDown();
            });
            executor.execute(() -> {
                dos = getDOrders();
                latch.countDown();
            });
            // 等待两个查询操作结束
            latch.await();
            diff = check(pos, dos);
            save(diff);
        }
    }
}
