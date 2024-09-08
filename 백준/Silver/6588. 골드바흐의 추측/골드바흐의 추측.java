import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;

public class Main {

    public static final int MAX_SIZE = 100_0000;

    public static int[] verifyConjecture(boolean[] primes, int n) {
        for (int i = 3; i <= n / 2; i += 2) {
            if (primes[i] && primes[n-i]) {
                return new int[]{ i, n - i };
            }
        }

        return new int[]{ -1, -1 };
    }

    public static boolean[] getPrimes() {
        boolean[] primes = new boolean[MAX_SIZE + 1];
        Arrays.fill(primes, true);

        for (int i = 2; i * i <= MAX_SIZE; i++) {
            for (int j = i * i; j <= MAX_SIZE; j += i) {
                primes[j] = false;
            }
        }

        return primes;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        boolean[] primes = getPrimes();

        while (true) {
            int n = Integer.parseInt(br.readLine());
            if (n == 0)
                return;

            int[] elements = verifyConjecture(primes, n);
            if (elements[0] > 0) {
                System.out.println(n + " = " + elements[0] + " + " + elements[1]);
            } else {
                System.out.println("Goldbach's conjecture is wrong.");
            }
        }
    }
}