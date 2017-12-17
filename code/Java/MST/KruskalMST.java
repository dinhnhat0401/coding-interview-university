import java.util.Queue;
import java.util.ArrayDeque;

public class KruskalMST {
    private Queue<Edge> mst;
    public KruskalMST(EdgeWeightedGraph G) {
        mst = new ArrayDeque<Edge>();
        MinPQ<Edge> pq = new MinPQ<Edge>();
        UF uf = new UF(G.E());
        for (int i = 0; i < G.V(); i++) {
            for (Edge e : G.adj(i)) {
                pq.insert(e);
            }
        }
        while (!pq.isEmpty() && mst.size() < G.V() - 1) {
            Edge e = pq.delMin();
            int v = e.either();
            int w = e.other(v);
            if (uf.connected(v, w)) continue;
            uf.union(v, w);
            mst.add(e);
        }
    }

    public Iterable<Edge> edges() {
        return mst;
    }

    public double weight() {
        double weight = 0;
        for (Edge e : edges()) {
            weight += e.weight();
        }
        return weight;
    }
}
