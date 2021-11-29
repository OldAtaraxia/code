package github.oldataraxia.ThreadPool;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;

public class MyThreadPool {
    // 利用阻塞队列实现生产者-消费者模式
    BlockingQueue<Runnable> workQueue;
    List<WorkerThread> threads = new ArrayList<>();
    MyThreadPool(int poolSize, BlockingQueue<Runnable> workQueue) {
        this.workQueue = workQueue;
        // 创建工作线程
        for (int i = 0; i < poolSize; i++) {
            WorkerThread thread = new WorkerThread();
            threads.add(thread);
            thread.start();
        }
    }

    void execute(Runnable command) throws InterruptedException {
        workQueue.put(command);
    }

    class WorkerThread extends Thread {
        public void run() {
            while(true) { //循环冲workQueue中取任务并执行
                Runnable task = null;
                try {
                    task = workQueue.take();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                task.run();
            }
        }
    }
}

class Test {
    public static void main(String[] args) throws InterruptedException {
        BlockingQueue<Runnable> workQueue = new LinkedBlockingQueue<>(2);
        MyThreadPool pool = new MyThreadPool(10, workQueue);
        pool.execute(new Runnable() {
            @Override
            public void run() {
                System.out.println("run");
            }
        });
    }
}

