package advanced.week4;// This class was created by PaintableToast
import java.util.ArrayList;
import java.util.Scanner;

public class C {
    public final static void main(final String[] args) {
        Scanner scanner = new Scanner(System.in);
        final int length = scanner.nextInt();
        int[][] gpi_list = new int[2][length];
        for (int i = 0; i < length; i++) {
            gpi_list[1][i] = scanner.nextInt();
            gpi_list[0][i] = i;
        }
        boolean swapped;
        int temp, temp2;
        for (int i = 0; i < length - 1; i++) {
            swapped = false;
            for (int j = 0; j < length - i - 1; j++)
                if (gpi_list[1][j] > gpi_list[1][j + 1]) {
                    temp = gpi_list[1][j];
                    gpi_list[1][j] = gpi_list[1][j + 1];
                    gpi_list[1][j + 1] = temp;
                    temp2 = gpi_list[0][j];
                    gpi_list[0][j] = gpi_list[0][j + 1];
                    gpi_list[0][j + 1] = temp2;
                    swapped = true;
                }
            if (!swapped) break;
        }
        int a, b, c;
        boolean found, run = true;
        ArrayList<Integer> dropout = new ArrayList<>();
        while (run)
        if (scanner.next().equalsIgnoreCase("QUESTION")) {
            a = scanner.nextInt() - 1;
            b = scanner.nextInt() - 1;
            c = 0;
            found = false;
            while (!found) {
                if (gpi_list[0][c] >= a && gpi_list[0][c] <= b)
                    if (!dropout.contains(gpi_list[0][c])) {
                        found = true;
                        break;
                    }
                c++;
            }
            System.out.println(gpi_list[0][c] + 1);
        } else {
            a = scanner.nextInt() - 1;
            if (a < 0) run = false;
            else dropout.add(a);
        }
    }
}
