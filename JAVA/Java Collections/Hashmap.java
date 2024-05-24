import java.util.*;



public class Hashmap {
    public static void main(String args[]) {
        HashMap< String,Integer > map = new HashMap<>();  // Create a hashmap object called
        map.put("a",10);
        map.put("b",20);
        map.put("c",30);
        System.out.println( map); 
        if(map.containsKey("a")) {
            int value=map.get("a");   
            System.out.println(value);
        }
        for(String item : map.keySet()){
            System.out.print(item+" "+map.get(item) + " ");
        }

        for(Map.Entry<String,Integer> entry : map.entrySet()) {
            System.out.println(entry.getKey()+":"+entry.getValue());
        }
    }
}
