import java.util.Scanner;
import java.security.MessageDigest;

class Hashing {
    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(System.in);
            
            System.out.print("Enter a message: ");
            String message = scanner.nextLine();
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] hash = md.digest(message.getBytes());
            System.out.print("Hash is ");
            for (byte b: hash)
                System.out.print(String.format("%x", b));
            System.out.println();

        } catch (Exception e) {
            System.out.println("Error occurred");
        }
    }
}
