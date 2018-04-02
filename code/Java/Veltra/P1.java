// Write a function to validate if a string is a palindrome ignoring spaces.
// “Hello World” is not a palindrome
// “A Toyota’s a Toyota” is a palindrome

// time complexity : O(n)
// space complexity: O(n)

public class P1 {
    public static void main(String argvs[]) {
        String str = "A Toyota’s a Toyota";
        if (validPalindrome(str)) {
            System.out.println(str + " is a palindrome");
        } else {
            System.out.println(str + " is not a palindrome");
        }
    }

    private static boolean validPalindrome(String str) {
        if (str == null) return false;
        int i = 0;
        int j = str.length() - 1;
        while(i < j) {
            if (!validCharacter(str.charAt(i))) { i++; continue; }
            if (!validCharacter(str.charAt(j))) { j--; continue; }
            if (Character.toLowerCase(str.charAt(i)) == Character.toLowerCase(str.charAt(j))) {
                i++; j--; continue;
            } else {
                return false;
            }
        }
        return true;
    }

    private static boolean validCharacter(char c) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            return true;
        }
        return false;
    }
}
