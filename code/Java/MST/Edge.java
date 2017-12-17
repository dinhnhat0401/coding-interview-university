public class Edge implements Comparable<Edge> {
    private int v;
    private int w;
    private double weight;
    public Edge(int v, int w, double weight) {
        this.v = v;
        this.w = w;
        this.weight = weight;
    }
    double weight() {
        return this.weight;
    }
    int either() {
        return v;
    }
    int other(int vertex) {
        if (vertex == v) return w;
        else if (vertex == w) return v;
        else throw new RuntimeException("Inconsistent edge");
    }
    public int compareTo(Edge that) {
        if (this.weight() < that.weight()) return -1;
        else if (this.weight() > that.weight()) return 1;
        else return 0;
    }
    public String toString() {
        return String.format("%d-%d %.2f", v, w, weight);
    }
}
