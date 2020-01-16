import java.io.BufferedReader;
import java.io.FileReader;
import java.util.LinkedList;

/**
 * 
 * This class computes the edit distance between two strings using dynamic
 * programming. The dynamic programming part is in the method printEditDistance().
 * 
 * @6.046 course staff
 * 
 */
public class DPEditDistance {
    public enum Operation {
        NOOP   (0, "initial", 0, 0),
        RIGHT  (0, "right",   1, 1),
        REPLACE(4, "replace", 1, 1),
        DELETE (2, "delete",  0, 1),
        INSERT (3, "insert",  1, 0);

        public final int cost;
        public final String text;
        public final int deltaI;
        public final int deltaJ;

        Operation(int cost, String text, int deltaI, int deltaJ) {
            this.cost = cost;
            this.text = text;
            this.deltaI = deltaI;
            this.deltaJ = deltaJ;
        }
    }

    public class Entry {
        private int cost;
        private Operation op;

        public Entry(int cost, Operation op) {
            this.cost = cost;
            this.op = op;
        }
    }

    private String x;
    private String y;
    private Entry t[][];

    public DPEditDistance(String inputFile) {
        try {
            BufferedReader reader = new BufferedReader(
                    new FileReader(inputFile));
            String line;

            line = reader.readLine(); /* Length of x */
            int m = Integer.parseInt(line);

            x = reader.readLine();
            if (m != x.length()) {
                throw new RuntimeException("x lengths do not match!");
            }

            line = reader.readLine();
            int n = Integer.parseInt(line);

            y = reader.readLine();
            if (n != y.length()) {
                throw new RuntimeException("y lengths do not match!");
            }
        } catch (Exception e) {
            System.err.println("Could not read from input file. " + e);
            e.printStackTrace();
            return;
        }
    }
    
    public DPEditDistance(String x, String y) {
        this.x = x;
        this.y = y;
    }

    public void printEditDistance() {
        t = new Entry[y.length() + 1][x.length() + 1];
        t[0][0] = new Entry(0, Operation.NOOP); // initial state
        
        for (int i = 0; i < y.length() + 1; i++) {
            for (int j = 0; j < x.length() + 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                int minCost = Integer.MAX_VALUE;
                Operation minCostOp = null;

                if (i > 0 && j > 0 && x.charAt(j - 1) == y.charAt(i - 1)) {
                    int c = t[i - 1][j - 1].cost + Operation.RIGHT.cost;
                    if (c < minCost) {
                        minCost = c;
                        minCostOp = Operation.RIGHT;
                    }
                }

                if (i > 0 && j > 0) {
                    int c = t[i - 1][j - 1].cost + Operation.REPLACE.cost;
                    if (c < minCost) {
                        minCost = c;
                        minCostOp = Operation.REPLACE;
                    }
                }

                if (i > 0) {
                    int c = t[i - 1][j].cost + Operation.INSERT.cost;
                    if (c < minCost) {
                        minCost = c;
                        minCostOp = Operation.INSERT;
                    }
                }

                if (j > 0) {
                    int c = t[i][j - 1].cost + Operation.DELETE.cost;
                    if (c < minCost) {
                        minCost = c;
                        minCostOp = Operation.DELETE;
                    }
                }

                t[i][j] = new Entry(minCost, minCostOp);
            }
        }
        
        System.out.println("x: " + x);
        System.out.println("y: " + y);
        System.out.println("Edit Distance: " + t[y.length()][x.length()].cost);
    }

    public void printOperations() {
        LinkedList<Operation> ops= new LinkedList<Operation>();
        int i = y.length(); // Start at state (n, m)
        int j = x.length();

        ops.addFirst(Operation.NOOP); // The final operation
        while (!(i == 0 && j == 0)) { // Backtrack until state (0,0)
            Operation o = t[i][j].op;
            ops.addFirst(o);
            i = i - o.deltaI; // Backtrack to the previous state
            j = j - o.deltaJ;
        }

        System.out.println();
        System.out.println("Oper    | c |Total| z");
        for (Operation o : ops) {
            System.out.printf("%-7s | %1d | %3d | %s\n", t[i][j].op.text,
                    t[i][j].op.cost, t[i][j].cost, y.substring(0, i) + "*"
                            + x.substring(j));
            i = i + o.deltaI; // Go to the next state
            j = j + o.deltaJ;
        }
    }

    public static void main(String[] args) {
        DPEditDistance editDistance;
        
        if (args.length != 1 && args.length != 2) {
            System.err.println("Usage: java DPEditDistance inputFile");
            return;
        } else if (args.length == 1) {
            editDistance = new DPEditDistance(args[0]);
        } else {
            editDistance = new DPEditDistance(args[0], args[1]);
        }
        
        editDistance.printEditDistance();
        editDistance.printOperations();
    }
}
