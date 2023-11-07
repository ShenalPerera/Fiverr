package ie.atu.sw;

import java.io.*;

public class Runner {

    public static void main(String[] args) {
        Menu menu = new Menu();
        FileHandler fileHandler = new FileHandler();
        CipherManager cipherManager = new CipherManager();

        boolean isExit = false;

        do {
            int userInput = menu.getUserInput();

            switch (userInput) {
                case 1 -> {
                    String inputDirectory = menu.getStringFromUser("Enter Inout Directory");
                    fileHandler.setInputDirectory(inputDirectory);
                }
                case 2 -> {
                    String outputDirectory = menu.getStringFromUser("Enter Output Directory");
                    fileHandler.setOutputDirectory(outputDirectory);
                }
                case 3 -> {
                    String key = menu.getStringFromUser("Enter the cipher key");
                    cipherManager.setKeyword(key);
                }
                case 4 -> processFile(fileHandler, cipherManager, true);
                case 5 -> processFile(fileHandler, cipherManager, false);
                case 7 -> isExit = true;
            }

        } while (!isExit);


    }


    private static void processFile(FileHandler fileHandler, CipherManager cipherManager, boolean isEncryption){
        File[] inputFiles = fileHandler.getAllFilesInsideInputDirectory();

        if (inputFiles != null){
            for (File file : inputFiles) {
                if (file.isFile() && file.getName().endsWith(".txt")) {
                    System.out.println("Reading file: " + file.getName());
                    File outputFile = new File(fileHandler.getOutputDirectory(), file.getName());
                    try  {
                        BufferedReader reader = new BufferedReader(new FileReader(file));
                        BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile));

                        String line;
                        while ((line = reader.readLine()) != null) {
                            String [] words = Parser.parseTheLine(line);
                            for (int i = 0; i < words.length; i++){
                                if (isEncryption){
                                    words[i] = cipherManager.encryptText(words[i]);
                                }
                                else{
                                    words[i] = cipherManager.decryptText(words[i]);
                                }
                            }

                            String resultantWord = String.join(" ", words);
                            writer.write(resultantWord);
                            writer.newLine();
                        }
                        writer.close();
                        reader.close();
                    } catch (IOException e) {
                        System.out.println("Error reading file: " + e.getMessage());
                    }


                    System.out.println("-----------------------------");
                }
            }
        }
    }

}
