
import java.util.*;
public class Linkedlist {
    public static void main(String args[]) {
        LinkedList<String> list = new LinkedList<String>();
        list.add("A");
        list.add("B");
        list.addLast("E");
        list.addFirst("C");
        list.add(2, "F");
        System.out.println(list);

        list.remove("A");
        list.remove(3);
        list.removeFirst();
        list.removeLast();
        System.out.println(list);
    }
}
