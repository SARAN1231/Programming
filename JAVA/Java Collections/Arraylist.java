import java.util.*;

public class Arraylist {
    public static void main(String[] args) {
        List<Integer> list = new ArrayList<Integer>(5); // Create a new arraylist object of type Integer
         for(int i=1;i<=5;i++) {
            list.add(i);  // Add elements to the arraylist using add() method
         }
         System.out.println(list);
         list.remove(3);
         System.out.println( list); //After removing element at index 3: 

         for(int i=0;i<list.size();i++) {
            System.out.print(list.get(i) + " ");
         }
    }
}