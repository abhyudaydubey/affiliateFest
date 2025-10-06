import java.util.Base64;

public class Base64Encoder {

    public static void main(String[] args) {
        String originalString = "Hello, G!";
        
        // Encode
        String encodedString = Base64.getEncoder().encodeToString(originalString.getBytes());
        
        System.out.println("Original: " + originalString);
        System.out.println("Base64 Encoded: " + encodedString);
    }
}
