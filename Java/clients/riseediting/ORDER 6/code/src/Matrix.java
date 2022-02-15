import java.io.*;
import java.util.Scanner;

public class Matrix {
    private double[][] numbers;

    private int rows;
    private int columns;

    public Matrix(){
        this.numbers = new double[0][0];
    }

    public static Matrix loadFromFile(String filename){
        int row,col;
        try{
            File myFile = new File(filename);
            Scanner fileScanner = new Scanner(myFile);


            row = fileScanner.nextInt();
            col = fileScanner.nextInt();

            Matrix matrix =  new Matrix();

            matrix.setRowCount(row);
            matrix.setColCount(col);

            for (int i = 0; i< row; i++){
                for (int j= 0; j< col; j++){
                    matrix.setEntry(i,j,fileScanner.nextDouble());
                }
            }
            return matrix;

        }
        catch (FileNotFoundException e){
            System.out.println("Unable to open file");
        }
        return null;
    }

    public void saveToFile(String filename){
        try {
            PrintWriter myWriter = new PrintWriter(filename);
            myWriter.printf("%d\n%d\n",rows,columns);

            for (int i = 0; i< rows; i++){
                for(int j = 0; j< columns; j++){
                    myWriter.printf("%s ",numbers[i][j]);
                }
                myWriter.printf("\n");
            }
            myWriter.close();
        } catch (Exception e) {
            System.out.println("An error occurred.");
        }
    }

    public int getRowCount(){
        return this.rows;
    }

    public int getColCount() {
        return columns;
    }

    public double getEntry(int row,int col){
        if (row < this.rows && col < this.columns){
            return this.numbers[row][col];
        }
        else{
            return Double.NaN;
        }
    }

    public void setRowCount(int size){
        if (size > 100){
            this.rows = 100;
        }
        else if(size < 0){
            this.rows = 0;
        }
        else{
            this.rows = size;
        }
        this.numbers = new double[rows][columns];
    }

    public void setColCount(int size){
        if (size > 100){
            this.columns= 100;
        }
        else if(size < 0){
            this.columns = 0;
        }
        else{
            this.columns= size;
        }
        this.numbers = new double[rows][columns];
    }

    public boolean setEntry(int row, int col,double value){
        if (row < 100 && row >=0 && col < 100 && col >= 0){
            this.numbers[row][col] = value;
            return true;
        }
        return false;
    }

    public void display(){
        for (int i = 0; i < this.rows; i++){
            System.out.print(" | ");
            for (int j= 0; j< this.columns; j++){
                System.out.printf("%6.2f ",this.numbers[i][j]);
            }
            System.out.println("| ");
        }
    }

    public  double getNorm(){
        double sum = 0.0;
        for (int i= 0; i< rows; i++){
            for (int j=0; j< columns; j++){
                sum = sum + Math.pow(this.numbers[i][j],2);

            }
        }
        return Math.sqrt(sum);
    }

    public  Matrix transpose(){
        Matrix matrix =  new Matrix();

        matrix.setRowCount(this.columns);
        matrix.setColCount(this.rows);

        for (int i =0; i<rows; i++){
            for (int j = 0; j < columns; j++){
                matrix.setEntry(j,i,numbers[i][j]);
            }
        }
        return matrix;
    }


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Prompt the user for a filename
        System.out.print("Enter the file to load: ");

        // Get the filename
        String filename = scanner.nextLine();
        // Create the object from Matrix class
        Matrix matrix = Matrix.loadFromFile(filename);

        // Display the matrix
        matrix.display();

        // Calculate the Norm of the matrix
        double norm = matrix.getNorm();
        // Display the norm
        System.out.printf("The Frobenius Norm is %f\n",norm);

        // Prompt the user for a row number and column number
        int row,col;

        System.out.print("Enter the row:");
        row = scanner.nextInt();

        System.out.print("Enter the col:");
        col = scanner.nextInt();

        double value;
        System.out.print("Enter the value:");
        value = scanner.nextDouble();

        // Change the entry of the matrix
        matrix.setEntry(row,col,value);

        // transpose of the matrix
        Matrix transpose = matrix.transpose();

        // Save the transposed matrix
        transpose.saveToFile("A1.txt");

        // Display the un-transposed matrix
        matrix.display();
    }

}
