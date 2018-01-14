class main {
    public static void main(String[] args) {
        String txt = "ABCCADABRAC";
        String pat = "ABRA";

        System.out.printf("Index of %s in %s is: %d\n", pat, txt, BF.search(txt, pat));
    }
}
