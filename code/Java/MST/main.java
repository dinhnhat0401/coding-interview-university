public class main {
    public static void main(String[] args) {
        In in = new In(args[0]);
        EdgeWeightedGraph G;
        G = new EdgeWeightedGraph(in);
        G.printGraph();

        // LazyPrimMST mst = new LazyPrimMST(G);
        // for (Edge e : mst.edges())
        //     StdOut.println(e);
        // StdOut.println(mst.weight());

        PrimMST mst = new PrimMST(G);
        for (Edge e : mst.edges())
            StdOut.println(e);
        StdOut.println(mst.weight());
    }
}
