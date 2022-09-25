import java.util.*;

public class Pipeline {

    public static long sumOfPipes(long n, long k) {

        long left = 1;
        long right = k;

        while (left < right) {
            long mid = (left + right) / 2;
            long s = sum(mid, k);
            if (s == n) {
                return k - mid + 1;
            } else if (s > n) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return k - left + 2;
    }

    static long sum(long left, long right) {
        long s = 0;
        if (left <= right) {
            s = sum(right) - sum(left - 1);
        }
        return s;
    }

    static long sum(long k) {
        return k * (k + 1) / 2;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long n = in.nextLong();
        long k = in.nextLong();
        if (n == 1) {
            System.out.println(0);
        } else if (k >= n) {
            System.out.println(1);
        } else {
            n -= 1;
            k -= 1;

            if (sum(k) < n) {
                System.out.println(-1);
            } else {

                System.out.println(sumOfPipes(n, k));

            }
        }
    }
