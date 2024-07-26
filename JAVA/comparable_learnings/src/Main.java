import java.util.ArrayList;
import java.util.Collections;

import Utils.MyUtils;
import Songs.Song;
import mycomparator.ArtistComparator;
import mycomparator.YearComparator;

public class Main {
    public static void main(String[] args) {

        Song song1 = new Song("saran",2005,"hdfjhg");
        Song song2 = new Song("kelvin",2002,"fs");
        Song song3 = new Song("albert",2023,"sfdfg");
        ArrayList <Song> ans = new ArrayList<>();
       ans.add(song1);
       ans.add(song2);
       ans.add(song3);

        MyUtils.iterateList(ans);

        System.out.println("General Sorting");
        Collections.sort(ans);
        MyUtils.iterateList(ans);
//
//        System.out.println("Year Sorting");
//        Collections.sort(ans,new YearComparator());
//        MyUtils.iterateList(ans);

//        System.out.println("Artist Sorting");
//        Collections.sort(ans,new ArtistComparator());
//        MyUtils.iterateList(ans);

    }
}