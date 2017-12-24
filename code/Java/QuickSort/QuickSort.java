class QuickSort {
    public static CustomType[] sort(CustomType[] arr) {
        StdRandom.shuffle(arr);
        return sort(arr, 0, arr.length - 1);
    }

    public static CustomType[] sort(CustomType[] arr, int lo, int hi) {
        if (lo >= hi) return arr;

        int j = partition(arr, lo, hi);
        sort(arr, lo, j - 1);
        sort(arr, j + 1, hi);

        return arr;
    }

    private static int partition(CustomType[] arr, int lo, int hi) {
        int i = lo;
        int j = hi + 1;

        while (true) {
            System.out.printf("%d %d\n", i, j);
            while (arr[++i].compareTo(arr[lo]) <= 0) {
                if (i == hi) break;
            }

            while (arr[--j].compareTo(arr[lo]) >= 0) {
                if (j == lo) break;
            }

            if (i >= j) break;
            swap(arr, i, j);
        }
        swap(arr, lo, j);

        return j;
    }

    private static void swap(CustomType[] arr, int i, int j) {
        CustomType tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}
