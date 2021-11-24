package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        GFG hashTable = new GFG();
        Scanner scanner = new Scanner(System.in);

        int option;

        while (true){
            System.out.println("*. Enter a value [100 - 999] : \n*. Any other number to exit  :");
            option = scanner.nextInt();
            if (!hashTable.checkRange(option)){
                break;
            }
            hashTable.hashing(option);
        }
        hashTable.printArray();

    }

}
