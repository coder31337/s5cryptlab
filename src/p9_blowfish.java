import java.util.Scanner;
import java.security.MessageDigest;
import javax.crypto.spec.SecretKeySpec;
import javax.crypto.Cipher;

class Blowfish {
    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(System.in);

            System.out.print("Enter a key: ");
            String key = scanner.nextLine();
            byte[] keyBytes = key.getBytes();
            MessageDigest md = MessageDigest.getInstance("MD5");
            byte[] keyHash = md.digest(keyBytes);
            SecretKeySpec blowfishKey = new SecretKeySpec(keyHash, "Blowfish");

            System.out.print("Enter a message: ");
            String message = scanner.nextLine();
            byte[] messageBytes = message.getBytes();

            Cipher cipher = Cipher.getInstance("Blowfish");
            cipher.init(Cipher.ENCRYPT_MODE, blowfishKey);
            byte[] ciphertextBytes = cipher.doFinal(messageBytes);
            System.out.println("\nAfter encryption");
            System.out.print("Ciphertext is ");
            for (byte ci: ciphertextBytes)
                System.out.print(String.format("%x", ci));
            System.out.println();

            cipher.init(Cipher.DECRYPT_MODE, blowfishKey);
            byte[] plaintextBytes = cipher.doFinal(ciphertextBytes);
            String plaintext = new String(plaintextBytes);
            System.out.println("\nAfter decryption");
            System.out.println("Plaintext is " + plaintext);

        } catch (Exception e) {
            System.out.println("Error occurred");
        }
    }
}