package ie.atu.sw;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class FileHandler {
    private String inputDirectory;
    private String outputDirectory;

    public FileHandler(String inputDirectory, String outputDirectory) {
        this.inputDirectory = inputDirectory;
        this.outputDirectory = outputDirectory;
    }

    public FileHandler() {
        this.inputDirectory = "";
        this.outputDirectory = "";
    }

    public String getOutputDirectory() {
        return outputDirectory;
    }

    public void setOutputDirectory(String outputDirectory) {
        String fullPath = createAbsolutePath(outputDirectory);
        Path pathToCheck = Paths.get(fullPath);

        if (Files.exists(pathToCheck) && Files.isDirectory(pathToCheck)) {
            this.outputDirectory = outputDirectory;
        } else {
            System.out.println(ConsoleColour.RED_BOLD_BRIGHT);
            System.out.println("The path is invalid or it's not a directory.");
            System.out.println(ConsoleColour.RESET);
        }
    }

    public String getInputDirectory() {
        return inputDirectory;
    }

    public void setInputDirectory(String inputDirectory) {
        String fullPath = createAbsolutePath(inputDirectory);
        Path pathToCheck = Paths.get(fullPath);

        if (Files.exists(pathToCheck) && Files.isDirectory(pathToCheck)) {
            this.inputDirectory = inputDirectory;
        } else {
            System.out.println(ConsoleColour.RED_BOLD_BRIGHT);
            System.out.println("The path is invalid or it's not a directory.");
            System.out.println(ConsoleColour.RESET);
        }
    }

    public File[] getAllFilesInsideInputDirectory() {
        File directory = new File(this.inputDirectory);
        if (directory.isDirectory()) {
            return directory.listFiles();
        }
        return null;
    }

    public void writeTheProcessedFile(String words, String filename) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename))) {

            String line = String.join(" ", words); // Join elements with spaces
            writer.write(line);
            writer.newLine(); // Move to the next line

        } catch (IOException e) {
            System.out.println("Error writing to file: " + e.getMessage());
        }
    }

    private String createAbsolutePath(String relativePath) {
        String currDirectory = System.getProperty("user.dir");
        return currDirectory + File.separator + relativePath;
    }
}
