class main {
    public static void main(String[] args) {
        String txt = "AABRAACADABRAACAADABRA";
        String pat = "AACAA";

        BM bm = new BM(pat);
        System.out.printf("Index of %s in %s is: %d\n", pat, txt, bm.search(txt));
    }
}
