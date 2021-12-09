package SampleFilesForIOwithFiles;
import java.io.PrintWriter;
import java.io.FileOutputStream;
import java.io.IOException;

public class TextFileWriteSample {
  public static void main(String[] args) throws IOException {
     // Try to open file
     FileOutputStream fileStream = new FileOutputStream("files/myoutfile.txt");
     // OVERWRITES EXISTING CONTENT IN FILE!!!
     PrintWriter outFS = new PrintWriter(fileStream);

     // Arriving here implies that the file can now be written
     // to, otherwise an exception would have been thrown.
     outFS.println("Hello");
     outFS.println("1 2 3");
     System.out.println("Open files/myoutfile.txt to see the result.");
     // Done with file, so try to close
     // Note that close() may throw an IOException on failure
     outFS.close();
  }
}

// Contents of
// myoutfile.txt:
// Hello
// 1 2 3
