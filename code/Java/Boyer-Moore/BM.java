class BM {
    public static final int NOT_FOUND = -1;
    private int[] right;
    private int R = 256;
    private String pat;
    public BM(String pat) {
        this.pat = pat;
        int M = pat.length();
        right = new int[R];
        for (int i = 0; i < R; i++) right[i] = -1;
        for (int i = 0; i < M; i++) right[pat.charAt(i)] = i;
    }
    public int search(String txt) {
        int N = txt.length();
        int M = pat.length();
        int skip = 0;
        for (int i = 0; i <= N - M; i += skip) {
            skip = 0;
            for (int j = M - 1; j >= 0; j--) {
                if (pat.charAt(j) != txt.charAt(i + j)) {
                    skip = Math.max(1, j - right[txt.charAt(i + j)]);
                    break;
                }
            }
            if (skip == 0) return i;
        }
        return NOT_FOUND;
    }
}
