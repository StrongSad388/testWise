import java.util.Scanner;

public class MessageDecoder {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the numeric string to decode: ");
        String numericString = scanner.nextLine().trim();
        scanner.close();
        int ways = numDecodings(numericString);
        System.out.println("Number of ways to decode the message: " + ways);
    }

    public static int numDecodings(String theNumericString) {
        if (theNumericString == null || theNumericString.length() == 0) {
            return 0;
        }

        int length = theNumericString.length();
        int[] dp = new int[length + 1];
        dp[0] = 1;
        dp[1] = theNumericString.charAt(0) != '0' ? 1 : 0;

        for (int i = 2; i <= length; i++) {
            int oneDigit = Integer.parseInt(theNumericString.substring(i - 1, i));
            int twoDigits = Integer.parseInt(theNumericString.substring(i - 2, i));

            if (oneDigit >= 1 && oneDigit <= 9) {
                dp[i] += dp[i - 1];
            }
            if (twoDigits >= 10 && twoDigits <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[length];
    }
}
