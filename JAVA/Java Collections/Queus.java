import java.util.*;
public class Queus {
    public static void main(String[] args) {
        Queue <Integer> q = new PriorityQueue<>();
        q.add(10);
        q.add(20);
        q.add(50);
        q.add(40);
        System.out.println(q);
        System.err.println(q.peek());
        System.err.println(q.poll());
          System.out.println(q);
          System.out.println(q.remove());
          System.out.println(q);
    }
}
