import java.util.Scanner;
import java.security.*;
import javax.crypto.Cipher;

public class RSA {
    static void printAsHex(byte[] byteArray) {
        for (byte b: byteArray)
                System.out.print(String.format("%x", b));
            System.out.println();
    }

    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(System.in);

            KeyPairGenerator keyPairGen = KeyPairGenerator.getInstance("RSA");
            keyPairGen.initialize(512);
            KeyPair keyPair = keyPairGen.genKeyPair();
            PrivateKey privateKey = keyPair.getPrivate();
            PublicKey publicKey = keyPair.getPublic();

            System.out.print("Enter a message: ");
            String message = scanner.nextLine();
            byte[] messageBytes = message.getBytes("UTF8");

            System.out.println("\nPublic key is");
            printAsHex(publicKey.getEncoded());

            Cipher cipher = Cipher.getInstance("RSA");
            cipher.init(Cipher.ENCRYPT_MODE, publicKey);
            byte[] ciphertextBytes = cipher.doFinal(messageBytes);
            System.out.println("\nAfter encryption");
            System.out.println("Ciphertext is");
            printAsHex(ciphertextBytes);

            System.out.println("\n\nPrivate key is");
            printAsHex(privateKey.getEncoded());

            cipher.init(Cipher.DECRYPT_MODE, privateKey);
            byte[] plaintextBytes = cipher.doFinal(ciphertextBytes);
            String plaintext = new String(plaintextBytes);
            System.out.println("\nAfter decryption");
            System.out.println("Plaintext is " + plaintext);

        } catch (Exception e) {
            System.out.println("Error occured");
        }
    }
}
