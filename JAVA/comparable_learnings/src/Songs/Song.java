package Songs;

public class Song implements Comparable<Song>{
    private final String title;
    private final String artist;
    private final Integer year;

    public String getTitle() {
        return title;
    }

    public String getArtist() {
        return artist;
    }

    public Integer getYear() {
        return year;
    }

    @Override
    public String toString() {
        return "Song{" +
                "title='" + title + '\'' +
                ", artist='" + artist + '\'' +
                ", year=" + year +
                '}';
    }

    public Song(String title, Integer year, String artist) {
        this.title = title;
        this.year = year;
        this.artist = artist;
    }

    @Override
    public int compareTo(Song o) {
        return this.title.compareTo(o.title);
    }
}
