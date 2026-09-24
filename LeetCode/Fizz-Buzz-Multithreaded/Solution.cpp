public static void main(String[] args) throws InterruptedException {
    FizzBuzz data = new FizzBuzz(15);
    Thread thread1 = new Thread(() -> {
        try {
            data.fizz(() -> System.out.print("fizz"));
        } catch (Exception e) {
        }
    });
    Thread thread2 = new Thread(() -> {
        try {
            data.buzz(() -> System.out.print("buzz"));
        } catch (Exception e) {
        }
    });
    Thread thread3 = new Thread(() -> {
        try {
            data.fizzbuzz(() -> System.out.print("fizzbuzz"));
        } catch (Exception e) {
        }
    });
    Thread thread4 = new Thread(() -> {
        try {
            data.number(i -> System.out.print(i));
        } catch (Exception e) {
        }
    });
    thread1.start();
    thread2.start();
    thread3.start();
    thread4.start();
    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
}