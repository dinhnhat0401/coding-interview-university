import java.util.List;
import java.util.ArrayList;;

public class LazyPrimMST {
    private EdgeWeightedGraph G;
    private List<Edge> edges;
    private boolean[] marked;
    private MinPQ<Edge> pq;

    public LazyPrimMST(EdgeWeightedGraph G) {
        this.G = G;
        pq = new MinPQ<Edge>(G.E());
        this.edges = new ArrayList<Edge>();
        marked = new boolean[G.V()];
        for (int i = 0; i < G.V(); i++) {
            marked[i] = false;
        }
        visit(0);
        while (!pq.isEmpty()) {
            Edge e = pq.delMin();
            if (marked[e.either()] && marked[e.other(e.either())]) continue;
            this.edges.add(e);
            visit(e.either());
            visit(e.other(e.either()));
        }
    }

    void visit(int v) {
        if (this.marked[v]) {
            return;
        }
        this.marked[v] = true;
        for (Edge newEdge : this.G.adj(v)) {
            if (!this.marked[newEdge.other(v)]) {
                pq.insert(newEdge);
            }
        }
    }

    Iterable<Edge> edges() {
        return this.edges;
    }
    double weight() {
        double weight = 0;
        for (Edge e : this.edges) {
            weight += e.weight();
        }
        return weight;
    }
}
