1class DiningPhilosophers {
2public:
3
4    mutex forks[5];
5
6    DiningPhilosophers() {
7    }
8
9    void wantsToEat(
10        int philosopher,
11        function<void()> pickLeftFork,
12        function<void()> pickRightFork,
13        function<void()> eat,
14        function<void()> putLeftFork,
15        function<void()> putRightFork
16    ) {
17
18        int left = philosopher;
19        int right = (philosopher + 1) % 5;
20
21        // Acquire both forks safely
22        scoped_lock lock(forks[left], forks[right]);
23
24        pickLeftFork();
25        pickRightFork();
26
27        eat();
28
29        putLeftFork();
30        putRightFork();
31    }
32};