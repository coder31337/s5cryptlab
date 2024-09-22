import java.util.Scanner;
import java.security.MessageDigest;
import javax.crypto.SecretKeyFactory;
import javax.crypto.SecretKey;
import javax.crypto.spec.DESKeySpec;
import javax.crypto.Cipher;

class DES {
    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(System.in);

            System.out.print("Enter a key: ");
            String key = scanner.nextLine();
            byte[] keyBytes = key.getBytes("UTF8");
            MessageDigest md = MessageDigest.getInstance("SHA-1");
            byte[] keyHash = md.digest(keyBytes);
            SecretKeyFactory keyFactory = SecretKeyFactory.getInstance("DES");
            SecretKey desKey = keyFactory.generateSecret(new DESKeySpec(keyHash));

            System.out.print("Enter a message: ");
            String message = scanner.nextLine();
            byte[] messageBytes = message.getBytes("UTF8");

            Cipher desCipher = Cipher.getInstance("DES");
            desCipher.init(Cipher.ENCRYPT_MODE, desKey);
            byte[] ciphertextBytes = desCipher.doFinal(messageBytes);
            System.out.println("\nAfter encryption");
            System.out.print("Ciphertext is ");
            for (byte ci: ciphertextBytes)
                System.out.print(String.format("%x", ci));
            System.out.println();

            desCipher.init(Cipher.DECRYPT_MODE, desKey);
            byte[] plaintextBytes = desCipher.doFinal(ciphertextBytes);
            String plaintext = new String(plaintextBytes);
            System.out.println("\nAfter decryption");
            System.out.println("Plaintext is  " + plaintext);

        } catch (Exception e) {
            System.out.println("Error occurred");
        }
    }
}
