// Given two list, merge them in sorted order.
// A=[1,3,9],B=[2,9,4]
// Solution is [1, 2, 3, 4, 9, 9]

// time complexity: O(nlogn + mlogm + n + m)
// space complexity: O(n + m)
// with n = A.length
// and  m = B.length

import java.util.Arrays;

public class P2 {
    public static void main(String argvs[]) {
        int[] A = { 1, 3, 9 };
        int[] B = { 2, 9, 4 };

        int[] C = sortedMerge(A, B);

        for (int i = 0; i < C.length; i++) {
            System.out.printf(C[i] + ", ");
        }
        System.out.printf("\n");
    }

    private static int[] sortedMerge(int a[], int b[]) {
        int[] aux = new int[a.length + b.length];
        int i = 0;
        int j = 0;

        Arrays.sort(a);
        Arrays.sort(b);

        for (int k = 0; k < aux.length; k++) {
            if (i >= a.length) { aux[k] = b[j++]; }
            else if (j >= b.length) { aux[k] = a[i++]; }
            else if (a[i] > b[j]) { aux[k] = b[j++]; }
            else { aux[k] = a[i++]; }
        }
        return aux;
    }
}
