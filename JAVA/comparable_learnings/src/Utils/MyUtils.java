package Utils;

import java.util.List;

public class MyUtils {

    // generic method which can accept all type of values (String Integer Double etc..)
    public static <T> void iterateList(List<T> list) {
        for (T t : list) {
            System.out.println(t);
        }
    }
}
