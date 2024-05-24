import java.util.*;

public class Treeset {
    public static void main(String[] args) {
        TreeSet <String> set = new TreeSet<String>();
        set.add("B");
        set.add("A");
        set.add("c");
        set.add("c");
        System.out.println(set);
        System.out.println(set.contains("c"));
        set.remove("c");
        System.out.println(set);
        for ( String s : set) {
            System.out.print(s+" ");
        }
    }
}
