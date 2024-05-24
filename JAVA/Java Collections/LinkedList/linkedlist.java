import java.util.*;

class Main {
    public static void main (String args[]){
         LinkedList<Integer> a = new LinkedList <Integer>();
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        for(int i=0;i<size;i++){
            a.add(sc.nextInt());
        }
        System.out.println(a);
           a.addFirst(sc.nextInt());
            System.out.println(a);
           a.addLast(sc.nextInt());
          System.out.println(a);
           a.removeFirst();
            System.out.println(a);
           a.removeLast();
         System.out.println(a);
          a.remove(sc.nextInt());
          System.out.println(a);
            a.add(sc.nextInt(),sc.nextInt());
              System.out.println(a);
    }
}