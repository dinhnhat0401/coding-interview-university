public class DirectedEdge {
    private final int v;
    private final int w;
    private final double weight;

    public DirectedEdge(int v, int w, double weight) {
        this.v = v;
        this.w = w;
        this.weight = weight;
    }
    // weight of this edge
    double weight() {
        return weight;
    }
    // vertext this edge points from
    int from() {
        return v;
    }
    // vertex this edge points to
    int to() {
        return w;
    }
    // string representation
    public String toString() {
        return String.format("%d->%d %.2f", v, w, weight);
    }
}
