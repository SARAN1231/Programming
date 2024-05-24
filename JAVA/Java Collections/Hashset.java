import java.util.*;

public class Hashset {
    public static void main(String[] args) {
        HashSet <String> set = new HashSet<String>();
        set.add("A");
        set.add("B");
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
