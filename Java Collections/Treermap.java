import java.util.*;

public class Treermap {
    public static void main(String[] args) {
        TreeMap<Integer, String> tree = new TreeMap<>();
        tree.put(3, "A");
        tree.put(2, "B");
        tree.put(1, "C");
        System.out.println(tree);
    }
}
