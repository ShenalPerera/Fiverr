package ie.atu.sw;

import java.util.Arrays;

public class CipherManager {
    private String keyword;
    private final String alphabet = "ADFGVX";
    private final char[][] polybiusSquare = {
            {'P', 'H', '0', 'Q', 'G', '6'},
            {'4', 'M', 'E', 'A', '1', 'Y'},
            {'L', '2', 'N', 'O', 'F', 'D'},
            {'X', 'K', 'R', '3', 'C', 'V'},
            {'S', '5', 'Z', 'W', '7', 'B'},
            {'J', '9', 'U', 'T', 'I', '8'}
    };


    public CipherManager() {
        this.keyword = "JAVA";
    }

    public CipherManager(String keyword) {
        this.keyword = keyword.toUpperCase();
    }

    public String encryptText(String plainText) {
        plainText = plainText.toUpperCase().replaceAll("[^A-Z0-9]", "");
        if (plainText.isEmpty()) return "";
        StringBuilder encryptedText = new StringBuilder();

        char[][] matrix = createMatrixFromPlainText(plainText);

        performColumnarTransposition(matrix, true);


        for (int i = 0; i < matrix[0].length; i++) {
            for (char[] chars : matrix) {
                encryptedText.append(chars[i]);
            }
        }

        return encryptedText.toString().replaceAll("[^A-Z0-9]", "");
    }


    public String decryptText(String cipherText) {
        char[][] matrix = createMatrixFromCipherText(cipherText);
        performColumnarTransposition(matrix, false);

        return getWordFromPairsSequence(matrix);

    }


    public void setKeyword(String keyword) {
        this.keyword = keyword;
    }


    private String getPairsSequence(String plainText) {
        StringBuilder pairsSequence = new StringBuilder();

        for (char letter : plainText.toCharArray()) {
            for (int row = 0; row < polybiusSquare.length; row++) {
                for (int col = 0; col < polybiusSquare.length; col++) {
                    if (letter == polybiusSquare[row][col]) {
                        pairsSequence.append(alphabet.charAt(row));
                        pairsSequence.append(alphabet.charAt(col));
                    }
                }
            }
        }
        return pairsSequence.toString();
    }

    private String getWordFromPairsSequence(char[][] matrix) {
        StringBuilder tempWord = new StringBuilder();
        if (matrix == null) return "";

        for (char[] chars : matrix) {
            for (int col = 0; col < matrix[0].length; col++) {
                if (Character.isAlphabetic(chars[col]) || Character.isAlphabetic(chars[col])) {
                    tempWord.append(chars[col]);
                }
            }
        }

        StringBuilder word = new StringBuilder();
        for (int i = 0; i < tempWord.length(); i = i + 2) {
            word.append(polybiusSquare[alphabet.indexOf(tempWord.charAt(i))][alphabet.indexOf(tempWord.charAt(i + 1))]);
        }

        return word.toString();
    }

    private char[][] createMatrixFromCipherText(String cipherText){
        int numRows = (int) Math.ceil((double) (cipherText.length() / 2) * 2 / this.keyword.length());
        int numCols = keyword.length();
        if (!(cipherText.length() > 0)) return null;

        // Convert the string to a character array
        char[] characters = keyword.toCharArray();
        int [] emptySlots =  new int[keyword.length()];

        int matrixSize = numRows * numCols;
        int cipherTextSize = cipherText.length();

        int remainingCols = matrixSize - cipherTextSize;

        for (int i =keyword.length() -1 ; i >= 0; i--){
            if (remainingCols > 0){
                emptySlots[i] = 1;
                remainingCols--;
            }
            else {
                emptySlots[i] = 0;
            }
        }

        // Loop through the character array
        for (int i = 0; i < characters.length - 1; i++) {

            // Find the smallest letter after the current letter
            int smallestIndex = i;
            for (int j = i + 1; j < characters.length; j++) {
                if (characters[j] < characters[smallestIndex]) {
                    smallestIndex = j;
                }
            }

            // Swap the current letter and the smallest letter
            char temp = characters[i];
            characters[i] = characters[smallestIndex];
            characters[smallestIndex] = temp;

            int tempInt = emptySlots[i];
            emptySlots[i] = emptySlots[smallestIndex];
            emptySlots[smallestIndex] = tempInt;
        }

        char[][] matrix = new char[numRows][numCols];

        int currentIndex = 0;
        for (int col = 0; col < numCols; col++) {
            for (int row = 0; row < numRows; row++) {
                if (currentIndex < cipherText.length()) {

                    matrix[row][col] = cipherText.charAt(currentIndex);
                    currentIndex++;
                }
                if (row == numRows-1 && emptySlots[col] == 1){
                    matrix[row][col] = ' ';  // Fill any remaining cells with spaces
                    currentIndex--;
                }

            }
        }
        return matrix;
    }

    private char[][] createMatrixFromPlainText(String plainText) {
        String pairsSequence = getPairsSequence(plainText);

        int numRows = (int) Math.ceil((double) plainText.length() * 2 / this.keyword.length());
        int numCols = keyword.length();

        char[][] matrix = new char[numRows][numCols];

        int currentIndex = 0;
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                if (currentIndex < pairsSequence.length()) {

                    matrix[row][col] = pairsSequence.charAt(currentIndex);
                    currentIndex++;
                } else {
                    matrix[row][col] = ' ';  // Fill any remaining cells with spaces
                }
            }
        }
        return matrix;
    }

    private void performColumnarTransposition(char[][] matrix, boolean isEncryption) {

        // Convert the string to a character array
        char[] characters = keyword.toCharArray();
        char[] charactersDup = Arrays.copyOf(characters, characters.length);

        if (matrix == null) return;

        // Loop through the character array
        for (int i = 0; i < characters.length - 1; i++) {

            // Find the smallest letter after the current letter
            int smallestIndex = i;
            for (int j = i + 1; j < characters.length; j++) {
                if (characters[j] < characters[smallestIndex]) {
                    smallestIndex = j;
                }
            }

            // Swap the current letter and the smallest letter
            char temp = characters[i];
            characters[i] = characters[smallestIndex];
            characters[smallestIndex] = temp;

            if (isEncryption) {
                for (int row = 0; row < matrix.length; row++) {
                    char tempChr = matrix[row][i];
                    matrix[row][i] = matrix[row][smallestIndex];
                    matrix[row][smallestIndex] = tempChr;

                }
            }

        }
        if (!isEncryption) {
            char[][] newMatrix = new char[matrix.length][matrix[0].length];

            for (int i = 0; i < keyword.length(); i++) {
                for (int j = 0; j < keyword.length(); j++) {
                    if (charactersDup[i] == characters[j]) {
                        characters[j] = ' ';
                        for (int row = 0; row < matrix.length; row++) {
                            newMatrix[row][i] = matrix[row][j];
                        }
                        break;
                    }
                }
            }


            for (int row = 0; row < matrix.length; row++) {
                for (int col = 0; col < matrix[row].length; col++) {
                    matrix[row][col] = newMatrix[row][col];
                }
            }
        }


    }


}
