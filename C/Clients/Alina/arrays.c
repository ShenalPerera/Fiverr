#include <stdio.h>
#include <math.h>

float lift_a_car(const int stick_length, const int human_weight, const int car_weight);
float unit_price(const float pack_price, const int rolls_count, const int pieces_count);
int bank_notes(const int price);
int euler(const int n);
int find_missing_number(const int n, const int arr[]);
unsigned long sum_squared(const int line);
int array_min(const int input_array[], const int array_size);
int array_max(const int input_array[], const int array_size);
int factorize_count(const int n);


int main(){
    // printf("%.4f\n", lift_a_car(2, 80, 1400));
    // printf("%.4f\n", lift_a_car(4, 90, 1650));

    // printf("%.4f\n", unit_price(4.79, 16, 150));
    // printf("%.4f\n", unit_price(5.63, 20, 200));

    // printf("%d\n", bank_notes(540));
    // printf("%d\n", bank_notes(5));

    // printf("%d\n", euler(6));
    // printf("%d\n", euler(12));

    // int input_array1[] = {3,0,1};
    // printf("%d\n", find_missing_number(3,input_array1));

    // printf("%lu\n", sum_squared(1));
    // printf("%lu\n", sum_squared(4));
    // printf("%lu\n", sum_squared(33));


    // int input_array[] = {1,2,3,4,5};
    // printf("%d\n", array_min(input_array, 5));
    // printf("%d\n", array_max(input_array, 5));
    // printf("%d\n", array_max(NULL, 5));

    // printf("%d\n", factorize_count(12));
  
    return 0;
}

float lift_a_car(const int stick_length, const int human_weight, const int car_weight){
    return roundf((stick_length * human_weight / (float)(human_weight + car_weight))* 100)/100;
}

float unit_price(const float pack_price, const int rolls_count, const int pieces_count){
    int total_squares = rolls_count * pieces_count;

    return roundf(((pack_price/total_squares) * 100)* 100) / 100;
}

int bank_notes(const int price){
    const int bank_notes_arr[] = {200,100,50,20,10};
    int notes_count = 0;
    int remiaing_price = price;

    if (price < 10 || price % 10 != 0){
        return -1;
    }
    

    for (int i = 0; i < 5 && remiaing_price >0 ; i++){
        int num_notes = remiaing_price / bank_notes_arr[i];
        notes_count += num_notes;
        remiaing_price %= bank_notes_arr[i];
    }

    return notes_count;
    
}

int euler(const int n){
    
    int result = n;  
    int number = n;

    for (int p = 2; p * p <= number; p++) {
        if (number % p == 0) {
            while (number % p == 0) {
                number /= p;
            }
            result -= result / p;
        }
    }

    if (number > 1) {
        result -= result / number;
    }

    return result;
}

 int find_missing_number(const int n, const int arr[]){
    int expected_total_count = (n * (n + 1)) / 2;

    int actual_total_sum = 0;
    for(int i =0; i < n; i++){
        actual_total_sum += arr[i];
    }

    return expected_total_count - actual_total_sum;
 } 

 unsigned long sum_squared(const int line) {
    unsigned long sum = 0;
    unsigned long coefficient = 1;

    for (int k = 0; k <= line; k++) {
        sum += coefficient * coefficient;
        coefficient = coefficient * (line - k) / (k + 1);
    }

    return sum;
}

int array_min(const int input_array[], const int array_size){
    if (input_array == NULL) return -1;

    int min = input_array[0];

    for(int i = 1; i < array_size; i++){
        if (min > input_array[i]){
            min = input_array[i];
        }
    }

    return min;
}

int array_max(const int input_array[], const int array_size){
     if (input_array == NULL) return -1;

    int max = input_array[0];

    for(int i = 1; i < array_size; i++){
        if (max < input_array[i]){
            max = input_array[i];
        }
    }

    return max;
}


int factorize_count(const int n) {
    int count = 0;
    int number = n;

    int isCounted = 0;

    for (int i = 2; i <= n; i++) {
        isCounted = 0;
        while (number % i == 0 && number > 1) {
            if(isCounted == 0){
                count++;
                isCounted = 1;
            }
            
            number /= i;
        }
    }

    return count;
}