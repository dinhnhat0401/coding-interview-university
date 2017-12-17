import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

class PrimMST {
    private EdgeWeightedGraph G;
    private IndexMinPQ<Double> pq;
    private boolean[] marked;
    private Edge[] edgeTo;
    // private List<Edge> edges;

    public PrimMST(EdgeWeightedGraph G) {
        this.G = G;
        // edges = new ArrayList<Edge>();
        marked = new boolean[G.V()];
        edgeTo = new Edge[G.V()];
        pq = new IndexMinPQ<Double>(G.E());
        for (int i = 0; i < G.V(); i++) {
            marked[i] = false;
        }
        pq.insert(0, 0.0);
        while (!pq.isEmpty()) {
            int v = pq.delMin();
            marked[v] = true;
            for (Edge e : G.adj(v)) {
                if (marked[v] && marked[e.other(v)]) continue;
                if (!pq.contains(e.other(v))) {
                    pq.insert(e.other(v), e.weight());
                    edgeTo[e.other(v)] = e;
                } else if (e.weight() < pq.keyOf(e.other(v))) {
                    pq.changeKey(e.other(v), e.weight());
                    edgeTo[e.other(v)] = e;
                }
            }
        }
    }

    Iterable<Edge> edges() {
        return Arrays.asList(this.edgeTo);
    }

    double weight() {
        double weight = 0;
        Iterable<Edge> edges = edges();
        for (Edge e : edges) {
            if (e != null) {
                weight += e.weight();
            }
        }
        return weight;
    }
}
