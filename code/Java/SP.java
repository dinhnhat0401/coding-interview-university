import java.util.Queue;
import java.util.Stack;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.lang.Double;

public class SP {
    private double[] distTo;
    private EdgeWeightedDigraph G;
    private int s; // source
    private DirectedEdge[] edgeTo; // last vertex on known path to this vertex
    private boolean[][] marked;
    public SP(EdgeWeightedDigraph G, int s) {
        this.G = G;
        this.s = s;

        distTo = new double[G.V()];
        edgeTo = new DirectedEdge[G.E()];
        marked = new boolean[G.V()][G.V()];

        for (int i = 0; i < G.V(); i++) {
            distTo[i] = Double.POSITIVE_INFINITY;
            edgeTo[i] = null;
        }
        distTo[s] = 0;
        for (int i = 0; i < G.V(); i++) {
            for (int j = 0; j < G.V(); j++) {
                marked[i][j] = false;
            }
        }
        Queue<Integer> q = new PriorityQueue<Integer>(G.E());
        q.add(s);
        while (q.peek() != null) {
            int v = q.poll();
            Iterable<DirectedEdge> adj = this.G.adj(v);
            for (DirectedEdge e : adj) {
                if (!marked[e.from()][e.to()]) {
                    marked[e.from()][e.to()] = true;
                    q.add(e.to());
                    relax(e);
                }
            }
        }
    }

    private void relax(DirectedEdge e) {
        StdOut.printf("relaxing %s\n", e.toString());
        int v = e.from();
        int w = e.to();
        if (distTo[w] > distTo[v] + e.weight()) {
            distTo[w] = distTo[v] + e.weight();
            edgeTo[w] = e;

            Iterable<DirectedEdge> adj = this.G.adj(w);
            for (DirectedEdge e1 : adj) {
                relax(e1);
            }
        }
    }

    // distance from s to v, ∞ if no path
    double distTo(int v) {
        return distTo[v];
    }
    // are there any path form s to v ?
    boolean hasPathTo(int v) {
        return distTo[v] < Double.POSITIVE_INFINITY;
    }

    // path from s to v, null if none
    Iterable<DirectedEdge> pathTo(int v) {
        if (!hasPathTo(v)) return null;
        Stack<DirectedEdge> path = new Stack<DirectedEdge>();
        for (DirectedEdge e = edgeTo[v]; e != null; e = edgeTo[e.from()])
            path.push(e);
        return path;
    }
}
