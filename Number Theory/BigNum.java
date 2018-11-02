import java.util.Scanner;
import java.math.BigInteger;

/**
 *
 * @author Tinh Dao
 */
class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner (System.in);
        
        String s1 = scanner.nextLine();
        String s2 = scanner.nextLine();
        
        BigInteger a = new BigInteger(s1);
        BigInteger b = new BigInteger(s2);
        System.out.println(a.add(b));
        System.out.println(a.subtract(b));
        System.out.println(a.multiply(b));
        
        scanner.close ();
    }
    
}
