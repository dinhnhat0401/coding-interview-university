class main {
    public static void main(String[] args) {
        String txt = "AABRAACADABRAACAADABRA";
        String pat = "AACAA";

        KMP kmp = new KMP(pat);
        System.out.printf("Index of %s in %s is: %d\n", pat, txt, kmp.search(txt));
    }
}
