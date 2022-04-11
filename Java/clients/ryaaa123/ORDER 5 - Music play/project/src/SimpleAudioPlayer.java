import java.io.*;
import java.sql.Time;
import java.util.HashMap;

import javax.sound.sampled.*;

public class SimpleAudioPlayer
{

    public static void main(String[] args) throws UnsupportedAudioFileException, IOException, LineUnavailableException, InterruptedException {
//        File file = new File("sample 4.au");
//        FileInputStream fileInputStream = new FileInputStream(file);
//        BufferedInputStream bufferedInputStream = new BufferedInputStream(fileInputStream);

        final AudioFileFormat.Type [] types = AudioSystem.getAudioFileTypes();
        for (final AudioFileFormat.Type t : types) {
            System.out.println("Returning Type : " + t);
        } // End of the for //
        AudioInputStream audioInputStream1 = AudioSystem.getAudioInputStream(new File("guitar/A.au"));
        AudioInputStream audioInputStream2 = AudioSystem.getAudioInputStream(new File("guitar/B.au"));
        Clip clip1 = AudioSystem.getClip();


        HashMap<Character,AudioInputStream> notes = new HashMap<>();

        notes.put('C',audioInputStream1);
        notes.put('A',audioInputStream2);

        clip1.open(notes.get('C'));

        clip1.start();

        Thread.sleep(1000);
        clip1.close();
        clip1.open(notes.get('A'));
        clip1.start();
        Thread.sleep(1000);
    }
}
