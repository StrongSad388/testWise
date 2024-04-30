import java.util.Scanner;

public class NumericStringDecoder {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the numeric string to decode: ");
        String numericString = scanner.nextLine().trim();
        scanner.close();
        
        String decodedString = decodeNumericString(numericString);
        
        System.out.println("Decoded string: " + decodedString);
    }
    
    public static String decodeNumericString(String numericString) {
        StringBuilder decodedString = new StringBuilder();
        
        for (int i = 0; i < numericString.length(); i++) {
            int numericValue = Character.getNumericValue(numericString.charAt(i));
            if (numericValue >= 1 && numericValue <= 26) {
                char decodedChar = (char) ('a' + numericValue - 1);
                decodedString.append(decodedChar);
            } else {
                // Append '?' for invalid numeric values
                decodedString.append('?');
            }
        }
        
        return decodedString.toString();
    }
}
