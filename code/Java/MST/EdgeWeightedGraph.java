public class EdgeWeightedGraph {
    private int V;
    private int E;
    private Bag<Edge>[] adj;
    public EdgeWeightedGraph(int V) {
        this.V = V;
        this.E = 0;
        adj = (Bag<Edge>[])new Bag[V];
        for (int v = 0; v < V; v++) {
            adj[v] = new Bag<Edge>();
        }
    }
    public EdgeWeightedGraph(In in) {
        this(in.readInt());
        int _E = in.readInt();
        for (int i = 0; i < _E; i++) {
            int v = in.readInt();
            int w = in.readInt();
            double weight = in.readDouble();
            Edge e = new Edge(v, w, weight);
            addEdge(e);
        }
    }
    int V() {
        return this.V;
    }
    int E() {
        return this.E;
    }
    void addEdge(Edge e) {
        int v = e.either();
        int w = e.other(v);
        adj[v].add(e);
        adj[w].add(e);
        E++;
    }
    public Iterable<Edge> adj(int v) {
        return adj[v];
    }
    public Iterable<Edge> edges() {
        Bag<Edge> bag = new Bag<Edge>();
        for (int i = 0; i < V; i++) {
            for (Edge e : adj(i)) {
                bag.add(e);
            }
        }
        return bag;
    }

    public void printGraph() {
        // String str = "";
        StdOut.printf("V = %d\n", V);
        StdOut.printf("E = %d\n", E);
        for (int i = 0; i < V; i++) {
            StdOut.printf("%d: ", i);
            for (Edge e : adj(i)) {
                StdOut.printf("%s ", e.toString());
            }
            StdOut.printf("\n");
        }
    }
}
