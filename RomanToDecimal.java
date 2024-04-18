import java.util.HashMap;

public class RomanToDecimal {
    
    public static int romanToDecimal(String roman) {
        // Create a hashmap to store the values of Roman numerals
        HashMap<Character, Integer> map = new HashMap<>();
        map.put('I', 1);
        map.put('V', 5);
        map.put('X', 10);
        map.put('L', 50);
        map.put('C', 100);
        map.put('D', 500);
        map.put('M', 1000);

        int decimal = 0;
        int prevValue = 0;

        // Traverse the string from right to left
        for (int i = roman.length() - 1; i >= 0; i--) {
            int curValue = map.get(roman.charAt(i));

            // If current value is greater than or equal to previous value, add it to result
            if (curValue >= prevValue) {
                decimal += curValue;
            } else { // If current value is less than previous value, subtract it from result
                decimal -= curValue;
            }

            prevValue = curValue;
        }

        return decimal;
    }

    public static void main(String[] args) {
        String roman = "MCMXCIV"; // Example Roman numeral string
        int decimal = romanToDecimal(roman);
        System.out.println("Roman numeral " + roman + " in decimal is: " + decimal);
    }
}
