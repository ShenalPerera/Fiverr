import java.io.*;

import javax.sound.sampled.*;

public class SimpleAudioPlayer
{

    public static void main(String[] args) throws UnsupportedAudioFileException, IOException, LineUnavailableException, InterruptedException {
        File file = new File("sample 4.au");
        FileInputStream fileInputStream = new FileInputStream(file);
        BufferedInputStream bufferedInputStream = new BufferedInputStream(fileInputStream);

        final AudioFileFormat.Type [] types = AudioSystem.getAudioFileTypes();
        for (final AudioFileFormat.Type t : types) {
            System.out.println("Returning Type : " + t);
        } // End of the for //
        AudioInputStream audioInputStream = AudioSystem.getAudioInputStream(new File("C-on_p.au"));

        Clip clip = AudioSystem.getClip();
        clip.open(audioInputStream);

        clip.start();
        Thread.sleep(60*1000);
    }
}
