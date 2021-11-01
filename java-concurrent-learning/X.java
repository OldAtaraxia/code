public class X {
    synchronized void foo() {
        // 临界区
    }
    synchronized static void bar() {
        // 临界区
    }
    Object obj = new Object();
    void baz() {
        synchronized (obj) {
            // 临界区
        }
    }
}
