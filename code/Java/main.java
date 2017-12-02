public class main {
    public static void main(String[] args) {
        EdgeWeightedDigraph G;
        G = new EdgeWeightedDigraph(new In(args[0]));
        int s = Integer.parseInt(args[1]);
        G.printGraph();
        // StdOut.printf("%s", G.toString());
        SP sp = new SP(G, s);
        for (int t = 0; t < G.V(); t++) {
            StdOut.printf(s + " to " + t);
            StdOut.printf(" (%4.2f) : ", sp.distTo(t));
            if (sp.hasPathTo(t)) for (DirectedEdge e : sp.pathTo(t)) StdOut.print(e + " ");
            StdOut.println();
        }

        DijkstraSP dijk = new DijkstraSP(G, s);
        for (int t = 0; t < G.V(); t++) {
            StdOut.printf(s + " to " + t);
            StdOut.printf(" (%4.2f) : ", dijk.distTo(t));
            if (dijk.hasPathTo(t)) for (DirectedEdge e : dijk.pathTo(t)) StdOut.print(e + " ");
            StdOut.println();
        }
    }
}
