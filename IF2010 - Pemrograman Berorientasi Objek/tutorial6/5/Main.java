import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int[] data = new int[N];
        for (int i = 0; i < N; i++) {
            data[i] = sc.nextInt();
        }

        int T = sc.nextInt();
        if (T <= 0) {
            System.out.println("Jumlah thread harus >= 1");
            sc.close();
            return;
        }

        int[] sums    = new int[T];
        Thread[] threads = new Thread[T];


        int baseSize = N / T;
        int remainder = N % T;
        int currentStartIndex = 0;

        for (int i  = 0; i < T; i++){
            int segmentSize = baseSize + (i < remainder ? 1 : 0);
            int startIndex = currentStartIndex;
            int endIndex = currentStartIndex + segmentSize;

            threads[i] = new SumThread(data, sums, startIndex, endIndex, i);
            threads[i].start();

            currentStartIndex = endIndex;
        }

        for (int i = 0; i < T; i++) {
            threads[i].join();
        }

        int total = 0;
        for (int i = 0; i < T; i++) {
            System.out.println("Sum" + i + " = " + sums[i]);
            total += sums[i];
        }
        System.out.println("Total = " + total);

        sc.close();
    }

    private static class SumThread extends Thread {
        private final int[] data;
        private final int[] result;
        private final int dataStartIndex;
        private final int dataEndIndex;
        private final int threadIndex;

        public SumThread(int[] data, int[] result,
                        int dataStartIndex, int dataEndIndex,
                        int threadIndex) {
            this.data             = data;
            this.result           = result;
            this.dataStartIndex   = dataStartIndex;
            this.dataEndIndex     = dataEndIndex;
            this.threadIndex      = threadIndex;
        }

        @Override
        public void run() {
            int sum = 0;
            for (int i = dataStartIndex; i < dataEndIndex; i++) {
                sum += data[i];
            }
            result[threadIndex] = sum;
        }
    }
}