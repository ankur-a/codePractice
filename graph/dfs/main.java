import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.FilterInputStream;
import java.io.BufferedInputStream;
import java.util.LinkedList;
import java.util.ArrayList;
import java.io.InputStream;
/**
 * @author khokharnikunj8
 */
public class main {
    public static void main(String[] args) {
        new Thread(null, new Runnable() {
            public void run() {
                new main().solve();
            }
        }, "1", 1 << 26).start();
    }
    void solve() {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        ScanReader in = new ScanReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Minimisethemagic solver = new Minimisethemagic();
        solver.solve(1, in, out);
        out.close();
    }
    static class Minimisethemagic {
        private ArrayList<Integer>[] arrayList;
        private int[] array;
        private long[] ans_ar;
        private int bfs(int node) {
            LinkedList<Integer> linkedList = new LinkedList<>();
            linkedList.add(1);
            while (linkedList.size() != 0) {
                int temp = linkedList.remove(0);
                if (temp == 1) {
                    if (arrayList[1].size() < 2) return 1;
                    if (arrayList[1].size() > 2) throw new RuntimeException();
                } else {
                    if (arrayList[temp].size() < 3) return temp;
                    if (arrayList[temp].size() > 3) throw new RuntimeException();
                }
                for (int i = 0; i < arrayList[temp].size(); i++) {
                    linkedList.add(arrayList[temp].get(i));
                }
            }
            return -1;
        }
        private long findIt(int node, int p) {
            long temp = array[node];
            for (int i = 0; i < arrayList[node].size(); i++) {
                if (arrayList[node].get(i) == p) continue;
                temp += findIt(arrayList[node].get(i), node);
            }
            return ans_ar[node] = temp;
        }
        public void solve(int testNumber, ScanReader in, PrintWriter out) {
            int n = in.scanInt();
            if (n < 1 || n > 100000) throw new RuntimeException();
            int value = in.scanInt();
            if (value < 1 || value > 1000000000) throw new RuntimeException();
            array = new int[n + 2];
            arrayList = new ArrayList[n + 2];
            ans_ar = new long[n + 2];
            for (int i = 0; i <= n + 1; i++) arrayList[i] = new ArrayList<>();
            for (int i = 1; i <= n; i++)
                if ((array[i] = in.scanInt()) < 1 || array[i] > 1000000000) throw new RuntimeException();
            array[n + 1] = value;
            for (int i = 0; i < n - 1; i++) {
                int x = in.scanInt();
                int y = in.scanInt();
                arrayList[x].add(y);
                arrayList[y].add(x);
            }
            int node = bfs(1);
            if (node == -1) throw new RuntimeException("Really ? ");
            System.out.println(node);
            arrayList[node].add(n + 1);
            findIt(1, -1);
            long ans = 0;
            for (int i = 0; i <= n + 1; i++) ans += ans_ar[i];
            out.println(ans);
        }
    }
    static class ScanReader {
        private byte[] buf = new byte[4 * 1024];
        private int index;
        private BufferedInputStream in;
        private int total;
        public ScanReader(InputStream inputStream) {
            in = new BufferedInputStream(inputStream);
        }
        private int scan() {
            if (index >= total) {
                index = 0;
                try {
                    total = in.read(buf);
                } catch (Exception e) {
                    e.printStackTrace();
                }
                if (total <= 0) return -1;
            }
            return buf[index++];
        }
        public int scanInt() {
            int integer = 0;
            int n = scan();
            while (isWhiteSpace(n)) n = scan();
            int neg = 1;
            if (n == '-') {
                neg = -1;
                n = scan();
            }
            while (!isWhiteSpace(n)) {
                if (n >= '0' && n <= '9') {
                    integer *= 10;
                    integer += n - '0';
                    n = scan();
                }
            }
            return neg * integer;
        }
        private boolean isWhiteSpace(int n) {
            if (n == ' ' || n == '\n' || n == '\r' || n == '\t' || n == -1) return true;
            else return false;
        }
    }
}