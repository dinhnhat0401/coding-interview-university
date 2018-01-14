class BF {
    public static final int NOT_FOUND = -1;
    public static int search(String txt, String pat) {
        int N = txt.length();
        int M = pat.length();

        for (int i = 0; i <= N - M; i++) {
            int j = 0;
            for (j = 0; j < M; j++) {
                if (txt.charAt(i + j) != pat.charAt(j)) break;
            }
            if (j == M) return i;
        }
        return NOT_FOUND;
    }
}
