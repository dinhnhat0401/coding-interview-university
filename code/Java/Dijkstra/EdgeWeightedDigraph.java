public class EdgeWeightedDigraph {
    private final int V;
    private int E;
    private Bag<DirectedEdge>[] adj;
    // empty V-vertex digraph
    public EdgeWeightedDigraph(int V) {
        this.V = V;
        this.E = 0;
        adj = (Bag<DirectedEdge>[]) new Bag[V];
        for (int v = 0; v < V; v++) {
            adj[v] = new Bag<DirectedEdge>();
        }
    }
    // construct from in
    public EdgeWeightedDigraph(In in) {
        this(in.readInt());
        int _E = in.readInt();
        for (int i = 0; i < _E; i++) {
            int v = in.readInt();
            int w = in.readInt();
            double weight = in.readDouble();
            DirectedEdge e = new DirectedEdge(v, w, weight);
            addEdge(e);
        }
    }
    // number of vertices
    int V() {
        return V;
    }
    // number of edges
    int E() {
        return E;
    }
    // add e to this digraph
    void addEdge(DirectedEdge e) {
        adj[e.from()].add(e);
        E++;
    }
    // edges pointing from v
    Iterable<DirectedEdge> adj(int v) {
        return adj[v];
    }
    // all edges in this digraph
    Iterable<DirectedEdge> edges() {
        Bag<DirectedEdge> bag = new Bag<DirectedEdge>();
        for (int v = 0; v < V; v++) {
            for (DirectedEdge e : adj[v]) {
                bag.add(e);
            }
        }
        return bag;
    }
    // // string representation
    // public String toString() {
    public void printGraph() {
        // String str = "";
        StdOut.printf("V = %d\n", V);
        StdOut.printf("E = %d\n", E);
        for (int i = 0; i < V; i++) {
            StdOut.printf("%d: ", i);
            for (DirectedEdge e : adj(i)) {
                StdOut.printf("%s ", e.toString());
            }
            StdOut.printf("\n");
        }
    }
}
