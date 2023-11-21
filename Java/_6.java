import java.math.BigInteger;
import java.security.*;
import java.util.Base64;
import javax.crypto.Cipher;

public class _6
{
    public static String encryptThisString(String input) 
    {
        try 
        {
            MessageDigest md = MessageDigest.getInstance("SHA-1");
            byte[] messageDigest = md.digest(input.getBytes());
            BigInteger no = new BigInteger(1, messageDigest);
            String hashText = no.toString(16);
            while (hashText.length() < 32) 
            {
                hashText = "0" + hashText;
            }
            return hashText;
        } 
        catch (NoSuchAlgorithmException e) 
        {
            throw new RuntimeException(e);
        }
    }

    public static byte[] sign(String input, PrivateKey privateKey) throws Exception 
    {
        Signature signature = Signature.getInstance("SHA1withRSA");
        signature.initSign(privateKey);
        signature.update(input.getBytes());
        return signature.sign();
    }

    public static boolean verify(String input, byte[] signature, PublicKey publicKey) throws Exception 
    {
        Signature sig = Signature.getInstance("SHA1withRSA");
        sig.initVerify(publicKey);
        sig.update(input.getBytes());
        return sig.verify(signature);
    }

    public static byte[] encrypt(String input, PublicKey publicKey) throws Exception 
    {
        Cipher cipher = Cipher.getInstance("RSA");
        cipher.init(Cipher.ENCRYPT_MODE, publicKey);
        return cipher.doFinal(input.getBytes());
    }

    public static String decrypt(byte[] encrypted, PrivateKey privateKey) throws Exception 
    {
        Cipher cipher = Cipher.getInstance("RSA");
        cipher.init(Cipher.DECRYPT_MODE, privateKey);
        byte[] decryptedBytes = cipher.doFinal(encrypted);
        return new String(decryptedBytes);
    }

public static void main(String args[]) throws NoSuchAlgorithmException {
    try {
        KeyPairGenerator keyPairGenerator = KeyPairGenerator.getInstance("RSA");
        keyPairGenerator.initialize(2048);
        KeyPair keyPair = keyPairGenerator.generateKeyPair();

        PublicKey publicKey = keyPair.getPublic();
        PrivateKey privateKey = keyPair.getPrivate();

        System.out.println("Message to be Encrypted and Signed: ");
        String originalMessage = "Ajinkya";
        System.out.println("Original Message: " + originalMessage); // Print the original message
        System.out.println("");

        // Calculate SHA-1 hash of the original message
        String hashedMessage = encryptThisString(originalMessage);
        System.out.println("SHA-1 Hash: " + hashedMessage);
        System.out.println("");

        // Append the hash to the original message
        String messageToEncryptAndSign = originalMessage + hashedMessage;

        // Sign the entire message (message + hash) with the private key
        byte[] signature = sign(messageToEncryptAndSign, privateKey);
        System.out.println("Signature Generated: " + Base64.getEncoder().encodeToString(signature));
        System.out.println("");

        // Encrypt the entire message with the public key
        byte[] encryptedData = encrypt(messageToEncryptAndSign, publicKey);

        // Decrypt the ciphertext with the private key
        String decryptedData = decrypt(encryptedData, privateKey);
        System.out.println("Decrypted Data: " + decryptedData);
        System.out.println("");

        // Split the decrypted data to retrieve the original message and hash
        int messageLength = originalMessage.length();
        String decryptedMessage = decryptedData.substring(0, messageLength);
        String decryptedHash = decryptedData.substring(messageLength);

        // Verify the signature
        String combinedMessage = decryptedMessage + decryptedHash;
        boolean verified = verify(combinedMessage, signature, publicKey);
        System.out.println("Signature Verified: " + verified);
        System.out.println("");

        // Compare the original message with the decrypted message
        if (originalMessage.equals(decryptedMessage)) {
            System.out.println("Original Message and Decrypted Message Match.");
        } else {
            System.out.println("Original Message and Decrypted Message Do Not Match.");
        }

        // Print the true message after decryption
        System.out.println("True Message: " + decryptedMessage);
    } catch (Exception e) {
        e.printStackTrace();
    }
}


}


