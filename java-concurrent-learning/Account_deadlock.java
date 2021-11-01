public class Account_deadlock {
    private int balance;
    void transfer(Account_deadlock target, int amt) {
        synchronized (this){
            synchronized (target) {
                if(this.balance > amt) {
                    this.balance -= amt;
                    target.balance += amt;
                }
            }
        }
    }
}
