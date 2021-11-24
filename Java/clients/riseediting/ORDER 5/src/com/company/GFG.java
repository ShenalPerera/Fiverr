package com.company;

import java.util.Arrays;

class GFG {

    double loadFactor = 0.5;
    int size = 11;
    int [] hash_table;

    GFG(){
        this.hash_table = new int[size];

        for (int i=0; i<size; i++){
            hash_table[i] = -1;
        }
    }

    public  void printArray() {


        for (int j : this.hash_table) {
            if (j != -1){
                System.out.print(j + " ");
            }
            else{
                System.out.print("_ ");
            }

        }
        System.out.println();
    }

    public boolean checkRange(int key){
        return key >= 100 && key <= 999;
    }

    public  void hashing( int key) {

        if (calculateLoadFactor() >= loadFactor){
            int newSize = getNextPrimeNumber(size * 2);

            int [] newHashTable = new int[size];

            System.arraycopy(hash_table, 0, newHashTable, 0, size);

            int oldSize = size;
            size = newSize;

            hash_table = new int[newSize];

            for (int i =0; i< newSize;i++){
                hash_table[i] = -1;
            }
            for (int i =0; i<oldSize;i++){
                if (newHashTable[i] != -1)
                    hashing(newHashTable[i]);
            }

        }

        int hv = key % size;

        if (hash_table[hv] == -1 && checkRange(key)){
            hash_table[hv] = key;
        }

        else {
            for (int j = 0; j < size; j++) {
                int t = (hv + j * j) % size;
                if (hash_table[t] == -1 && checkRange(key)) {
                    hash_table[t] = key;
                    break;
                }
            }
        }

    }

    public double calculateLoadFactor(){
        int count = 0;
        for (int i =0; i<size; i++){
            if (hash_table[i] != -1){
                count++;
            }
        }
        return count/(double)size;
    }

    public boolean isPrime(int n){
        if (n <= 1) return false;
        if (n <= 3) return true;

        if ( n % 2 ==0 || n % 3 == 0) return false;

        for (int i =5; i* i <=n; i = i+ 6){
            if ( n % i ==0 || n % (i+2) == 0) return false;
        }
        return true;
    }

    public int getNextPrimeNumber(int n){
        boolean found = false;
        if (n <= 1) return 2;

        int prime = n;

        while (!found){
            prime++;
            if (isPrime(prime)){
                found = true;
            }
        }
        return prime;
    }

}