import javax.sound.sampled.*;
import java.io.File;
import java.io.IOException;
import java.util.HashMap;
import java.util.Scanner;

public  class Instrument {

    /*
        These two hashmaps store the File object that read from the given folders.Each character(Key) represent the unique
        value.
        eg:
        C - File object of C.au file
    */

    private final HashMap<Character,File> pianoFileHashMap;
    private final HashMap<Character,File> guitarFileHashMap;


    // This method is to display the instrument of given choice
    public void display(char instrument){
        /*
        In here ANSI escape characters are using to color the console.
         */
        String BLACK = "\033[40m \033[0m";                          // Black space
        String WHITE = "\033[47m \033[0m";                          // White space
        String BLACK_LINE = "\033[47m\u001b[30m|\033[0m\033[0m";    // Black vertical line with white background
        String BROWN = "\u001b[48;5;130m";                          // Brown horizontal line
        String RESET = "\033[0m";                                   // Reset the immediate opened ansi character

        String WHITE_LINE_BH = "\033[47m";                          // White horizontal line

        String BLACK_LINE_H = BROWN+"\u001b[30m_"+RESET+RESET;      // Black horizontal line with Brown background
        String BLACK_LINE_V = BROWN+"\u001b[37;1M|\033[0m" +RESET;  // White vertical line with Brown background

        // These are relevant characters and there backgrounds
        /*
            Each an every letter are print in black color ith relevant background color
         */
        String A =  "\u001b[48;5;228m\u001b[30m A \033[0m\033[0m";
        String B =  "\033[42m\u001b[30m B \033[0m\033[0m";
        String C =  "\033[44m\u001b[30m C \033[0m\033[0m";
        String D =  "\033[45m\u001b[30m D \033[0m\033[0m";
        String E =  "\u001b[48;5;196m\u001b[30m E \033[0m\033[0m";
        String F =  "\u001b[48;5;202m\u001b[30m F \033[0m\033[0m";
        String G =  "\u001b[48;5;226m\u001b[30m G \033[0m\033[0m";

        // Handle the piano
        if (instrument == 'p'){
            for (int i =0; i < 4; i++){
                for (int j = 0; j < 95; j++){
                    System.out.print(BLACK);
                }
                System.out.println();
            }

            // Build the structure using string and replace with colors and letters
            for (int i = 0; i <4; i++ ){
                System.out.println(BLACK+BLACK+"     *****  *****     |     *****  *****  *****     |     *****  *****     |     *****     ".replace(" ",WHITE).replace("|",BLACK_LINE).replace("*",BLACK)+BLACK+BLACK);
            }
                System.out.println(BLACK+BLACK+"     _____  _____     |     _____  _____  _____     |     _____  _____     |     _____     ".replace("|",BLACK_LINE).replace(" ",WHITE).replace("_",BLACK)+BLACK+BLACK);
                System.out.println(BLACK+BLACK+"       |      |       |       |      |      |       |       |      |       |       |       ".replace("|",BLACK_LINE).replace(" ",WHITE)+BLACK+BLACK);
                System.out.println(BLACK+BLACK+WHITE_LINE_BH+("__"+C+"__|_"+D+"__|__"+E+"__|__"+F+"__|__"+G+"_|__"+A+"_|__"+B+"__|__"+C+"__|______|_______|_______|_______").replace("|",BLACK_LINE).replace("_",WHITE) +RESET +BLACK+BLACK);
                System.out.println(BLACK+BLACK+"_______|______|_______|_______|______|______|_______|_______|______|_______|_______|_______".replace("|",BLACK_LINE).replace("_",WHITE)+BLACK+BLACK);
                System.out.println("\033[40m                                                                                               \033[0m");


        }
        // Handle for guitar
        else if (instrument == 'g'){
            String Border = BROWN + "____|_________|_________|_________|_________|_________|_________|_________|______|".replace("_", BLACK_LINE_H).replace("|", BLACK_LINE_V) + RESET;
            System.out.println(Border);

            System.out.println(BROWN+"____|_________|_________|_________|_________|_________|_________|_________|______|".replace("_"," ") + RESET);
            System.out.println(Border);

            System.out.println(BROWN+ "____|_________|_________|_________|_________|_________|_________|_________|______|".replace("_"," ") + RESET);
            System.out.println(BROWN+("____|_________|_________|_________|_________|_________|_________|___"+A+"___|______|").replace("_",BLACK_LINE_H).replace("|",BLACK_LINE_V) +RESET);

            System.out.println(BROWN+ "____|_________|_________|_________|_________|_________|_________|_________|______|".replace("_"," ") + RESET);
            System.out.println(BROWN+("____|_________|_________|_________|_________|_________|_________|___"+E+"___|______|").replace("_",BLACK_LINE_H).replace("|",BLACK_LINE_V) +RESET);

            System.out.println(BROWN+"____|_________|_________|_________|_________|_________|_________|_________|______|".replace("_"," ") + RESET);
            System.out.println(BROWN+("____|_________|_________|_________|___"+D +"___|_________|___"+C+"___|___"+B+"___|______|").replace("_",BLACK_LINE_H).replace("|",BLACK_LINE_V) +RESET);

            System.out.println(BROWN+"____|_________|_________|_________|_________|_________|_________|_________|______|".replace("_"," ") + RESET);
            System.out.println(BROWN+("____|_________|_________|_________|_________|_________|___"+G+"___|_________|_"+F+"__|").replace("_",BLACK_LINE_H).replace("|",BLACK_LINE_V) +RESET);


        }
    }

    // Constructor
    public Instrument() throws LineUnavailableException {
        pianoFileHashMap = new HashMap<>();
        guitarFileHashMap= new HashMap<>();

        char[] notes = {'A','B','C','D','E','F','G'};

        // Read and store piano and guitar notes
        for (char note : notes) {
            pianoFileHashMap.put(note, new File("piano/" + note + ".au"));
            guitarFileHashMap.put(note,new File("guitar/" + note + ".au"));
        }
    }
    //Method to play the sound
    public void play(char instrument, char[] notes) throws LineUnavailableException, IOException, InterruptedException, UnsupportedAudioFileException {

        // Loop through each and every notes that user given
        for (char note : notes) {
            // Create a clip (This clip read audio file as stream)
            Clip clip = AudioSystem.getClip();

            // Object to keep the stream
            AudioInputStream audioInputStream = null;

            // According to the given instrument it chooses the hashmap
            // Then it creates a new audio input stream data from the loaded files with relevant note
            if (instrument == 'p'){
                audioInputStream = AudioSystem.getAudioInputStream(pianoFileHashMap.get(note));
            }
            else if (instrument == 'g'){
                audioInputStream = AudioSystem.getAudioInputStream(guitarFileHashMap.get(note));
            }
            // Created clip opens that input stream that was read
            clip.open(audioInputStream);

            // Then start the clip
            clip.start();

            // Hold the1 second and play the music
            Thread.sleep(1000);
            // Stop the clip created clip. Then it will loop for every notes that was given by user
            clip.stop();
        }


    }

    // Print the menu and get the user input as characters and return that character
    public static char menu(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("---------------------");
        System.out.println("Choose the instrument");
        System.out.println("p : Piano");
        System.out.println("g : Guitar");
        System.out.println("q : quit");
        System.out.print("Enter your choice : ");
        return Character.toLowerCase(scanner.next().charAt(0));
    }

    // Method to check user given notes are in the notes array. If it is in their return true otherwise false
    private static boolean isValid(char note){
        char[] notes = {'A','B','C','D','E','F','G'};
        boolean found = false;
        for (char c : notes) {
            if (c == note) {
                found = true;
                break;
            }
        }
        return found;
    }

    // Method to get the notes from the user
    public static void getUserNotes(char[] userNotes){

        Scanner scanner = new Scanner(System.in);

        char note;
        int round = 0;
        // Loop until ten times
        while (round < 10){

            System.out.print("Enter the note " + (round + 1) + ": ");
            // get the note
            note = Character.toUpperCase(scanner.next().charAt(0));
            // Validate the note
            if (isValid(note)){
                userNotes[round] = note;
                round++;
            }
            else{
                System.out.println("Invalid Input!");
            }
        }
    }


    public static void main(String[] args) throws UnsupportedAudioFileException, IOException, LineUnavailableException, InterruptedException {
        // Array to hold user given notes. This array is modified by the getUserNotes method
        char[] userNotes = new char[10];

        // Loop until user wish to exit from the program
        do {
            // Print the menu and get the user's choice
            char choice = menu();

            // Quite from the loop if it is q/Q
            if (choice == 'q') break;

            // If the given character is not valid loop again until give valid input
            if (!(choice == 'p' || choice == 'g')){
                System.out.println("Invalid input!");
                continue;
            }

            // If everything is okay create the instrument object
            Instrument instrument = new Instrument();

            // Display the instrument for given choice
            instrument.display(choice);

            // Get user input for the 10 notes and store in the userNotes array
            getUserNotes(userNotes);

            // Play the given notes
            instrument.play(choice,userNotes);

        }while (true);
    }

}
