public class Test {
    private static long count = 0;
    synchronized private void add10K() {
        int idx = 0;
        while(idx++ < 10000) {
            count += 1;
        }
    }

    public static long calc() throws InterruptedException {
        final Test test = new Test();
        Thread th1 = new Thread(() -> {
            test.add10K();
        });
        Thread th2 = new Thread(() -> {
            test.add10K();
        });
        th1.start();
        th2.start();
        th1.join();
        th2.join();
        return count;
    }

}
