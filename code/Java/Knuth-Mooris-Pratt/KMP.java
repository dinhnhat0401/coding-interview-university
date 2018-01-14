class KMP {
    public static final int NOT_FOUND = -1;
    // dfa = diterministic finite-state automaton
    private int dfa[][];
    private int R = 256;
    int M;
    public KMP(String pat) {
        M = pat.length();
        dfa = new int[R][M];
        int x = 0;
        dfa[pat.charAt(0)][0] = 1;
        for (int j = 1; j < M; j++) {
            for (int c = 0; c < R; c++) {
                dfa[c][j] = dfa[c][x];
            }
            dfa[pat.charAt(j)][j] = j + 1;
            x = dfa[pat.charAt(j)][x];
        }
    }

    public int search(String txt) {
        int N = txt.length();
        int state = 0;
        for (int i = 0; i < N; i++) {
            state = dfa[txt.charAt(i)][state];
            if (state == M) return i - M + 1;
        }
        return NOT_FOUND;
    }
}
