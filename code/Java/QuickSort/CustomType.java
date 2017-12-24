import java.io.*;
import java.util.*;

class CustomType implements Comparable<CustomType> {
    private char c;

    public CustomType(char c) {
        this.c = c;
    }

    public int compareTo(CustomType t) {
        return (int)this.c - (int)t.c;
    }

    public int getC() {
        return c;
    }
}
