import java.util.Random;

class main {
    public static void main(String[] argvs) {
        int size = 1000000;
        Random r = new Random();
        char[] resources = "abcdefghijklmopqrstuvxyz".toCharArray();
        CustomType[] arr = new CustomType[size];
        for (int i = 0; i < size; i++) {
            arr[i] = new CustomType(resources[r.nextInt(resources.length)]);
        }
        // System.out.println("Before sort:\n");
        // printArr(arr);
        long startTime = System.nanoTime();
        arr = QuickSort.sort(arr);
        long endTime = System.nanoTime();
        long duration = (endTime - startTime);
        System.out.println("duration " + duration/1000000);
        // System.out.print("After sort:\n");
        // printArr(arr);
    }

    private static void printArr(CustomType[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.printf("%c ", arr[i].getC());
        }
        System.out.println("\n");
    }
}
