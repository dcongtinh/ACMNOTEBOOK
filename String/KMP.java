import java.io.File;
import java.util.Scanner;
 
public class KMPimplement {
    public static class FastReader {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader() {
            br = new BufferedReader(new
                     InputStreamReader(System.in));
        }
 
        String next() {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() {
            return Integer.parseInt(next());
        }
 
        long nextLong() {
            return Long.parseLong(next());
        }
 
        double nextDouble() {
            return Double.parseDouble(next());
        }
 
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(new File("KMP.inp"));
 
        String source = scanner.nextLine();
        String s      = scanner.nextLine();
 
        scanner.close();
 
        int m = 0, i = 0;
        int n = source.length();
        int sublen = s.length ();
        int[] T = new int [sublen];
        // create T
        int k = 2, cnd = 0;
        T[0] = -1; T[1] = 0;
        while (k < sublen) {
            if (s.charAt(k-1) == s.charAt(cnd)) {
                T[k] = cnd + 1;
                k ++;
                cnd ++;
            } else if (cnd > 0) cnd = T[cnd];
            else {
                T[k] = 0;
                k++;
            }
        }
 
        // end create
        int pos = -1;
        while (m + i < n) {
            if (s.charAt(i) == source.charAt(m+i)) {
                i ++;
                if (i == sublen) {
                    pos = m;
                    break;
                }
            } else {
                if (T[i] > -1)
                {
                    i = T[i];
                    m += i-T[i];
                } else {
                    i = 0; m ++;
                }
            }
        }
 
        System.out.print(pos);
    }
}