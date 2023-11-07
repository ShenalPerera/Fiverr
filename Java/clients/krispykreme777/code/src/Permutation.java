import java.io.*;

public class Permutation {

    static void permute_characters(int n, char[] arr, int len, int L, BufferedWriter writer) throws IOException {
        for (int i = 0; i < L; i++)
        {


            writer.write(arr[n % len]);
            n /= len;
        }
        writer.write("\n");
    }

    static void write_to_file(char[] arr, int len, int L, BufferedWriter writer) throws IOException {

        for (int i = 0; i < (int)Math.pow(len, L); i++)
        {
            permute_characters(i, arr, len, L,writer);
        }
    }

    public static void main(String[] args) throws IOException {
        char[] alphabet = "abcdefghijklmnopqrstuvwxyz".toCharArray();
        char[] alphanum = "abcdefghijklmnopqrstuvwxyz123456789".toCharArray();
        int len = alphabet.length;




        for (int i = 5; i<11; i++){
            File file = new File(i+".txt");
            FileOutputStream fileOutputStream = new FileOutputStream(file);
            BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(fileOutputStream));

            // function call
            write_to_file(alphabet, len, i,bufferedWriter);
            bufferedWriter.close();
        }

        len = alphanum.length;

        for (int i = 5; i<9; i++){
            File file = new File("#"+i+".txt");
            FileOutputStream fileOutputStream = new FileOutputStream(file);
            BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(fileOutputStream));

            // function call
            write_to_file(alphanum, len, i,bufferedWriter);
            bufferedWriter.close();
        }

    }
}
