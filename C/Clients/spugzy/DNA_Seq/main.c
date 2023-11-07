#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>


#define MAX_LIFESPAN_MIN 8
#define MAX_LIFESPAN_MAX 50

typedef enum BASE_TYPE_ {
    A, C, T, G
} BASE_TYPE;

typedef struct base_ {
    BASE_TYPE baseType;
} base;

typedef struct sequence_node_ {
    base *DNABase;
    struct sequence_node_ *next;
    struct sequence_node_ *previous;
} sequence_node;

// Define the struct for a DNA sequence
typedef struct DNA_sequence_ {
    sequence_node *head;
    sequence_node *tail;
    int currentAge;
    int size;
    int maxLifespan;
    double growthProbability;
    double deletionProbability;
    double mutationProbability;
} DNA_sequence;


// Creates a new base struct with the specified type.
base *create_base(BASE_TYPE baseType);

// Function to create a new DNA sequence
DNA_sequence *
createSequence(int maxLifespan, double growthProbability, double deletionProbability, double mutationProbability);

// Function to add a new base to the sequence
void addBase(DNA_sequence *sequence, BASE_TYPE type);

void insertBase(DNA_sequence *sequence, BASE_TYPE type, int position);

void deleteBase(DNA_sequence *sequence, int position);

int searchPattern(sequence_node * startNode, const BASE_TYPE *pattern, int patternSize, int startPosition);

// Function to print the DNA sequence
void printSequence(DNA_sequence *sequence);

int isEventOccurs(double probability);

BASE_TYPE getRandomBase();

int generate_random_number(int min_value, int max_value);

sequence_node* getNodeAtIndex(DNA_sequence* sequence, int index);

void applySpecialPatternsProperties(DNA_sequence* sequence, BASE_TYPE* pattern, int patternSize);

void lifeCycleLoop(DNA_sequence *sequence);


int main() {
    // Initialize random seed for probability calculations
    srand(time(NULL));


    char wantNewSeq = 'y';

    do {
        if (tolower(wantNewSeq) == 'y'){
            int maxLifespan = generate_random_number(MAX_LIFESPAN_MIN, MAX_LIFESPAN_MAX);

            // Create a DNA sequence
            DNA_sequence *sequence = createSequence(maxLifespan, 0.25, 0.25, 0);

            for (int i = 0; i < 20; ++i) {
                addBase(sequence,getRandomBase());
            }

            lifeCycleLoop(sequence);
        }

        printf("Do you want to start with a new sequence (Y/N) : ");
        scanf(" %c", &wantNewSeq);
        if (tolower(wantNewSeq) == 'y') continue;
        else if (tolower(wantNewSeq) == 'n') break;

    } while (1);


    return 0;
}



// Creates a new base struct with the specified type.
base *create_base(BASE_TYPE baseType) {
    base *DNAbase = (base *) malloc(sizeof(base));
    DNAbase->baseType = baseType;
    return DNAbase;
}

DNA_sequence *
createSequence(int maxLifespan, double growthProbability, double deletionProbability, double mutationProbability) {
    DNA_sequence *newSequence = (DNA_sequence *) malloc(sizeof(DNA_sequence));
    if (newSequence != NULL) {
        newSequence->head = NULL;
        newSequence->tail = NULL;
        newSequence->currentAge = 0;
        newSequence->size = 0;
        newSequence->maxLifespan = maxLifespan;
        newSequence->growthProbability = growthProbability;
        newSequence->deletionProbability = deletionProbability;
        newSequence->mutationProbability = mutationProbability;
    }
    return newSequence;
}

// Function to add a new base to the sequence
void addBase(DNA_sequence *sequence, BASE_TYPE type) {
    base *newBase = create_base(type);
    if (newBase == NULL) {
        return; // Handle memory allocation error
    }

    sequence_node *newNode = (sequence_node *) malloc(sizeof(sequence_node));
    if (newNode != NULL) {
        newNode->DNABase = newBase;
        newNode->previous = sequence->tail;
        newNode->next = NULL;

        if (sequence->head == NULL) {
            sequence->head = newNode;
        } else {
            sequence->tail->next = newNode;
        }

        sequence->tail = newNode;
    }
    sequence->size = sequence->size + 1;
}

void insertBase(DNA_sequence *sequence, BASE_TYPE type, int position) {
    if (position < 0 || position > sequence->size) {
        printf("Invalid position for insertion\n");
        return;
    }

    sequence_node *newNode = (sequence_node *) malloc(sizeof(sequence_node));
    if (newNode != NULL) {
        base *newBase = create_base(type);
        if (newBase == NULL) {
            free(newNode);
            return; // Handle memory allocation error
        }

        newNode->DNABase = newBase;

        // Insert at the beginning
        if (position == 0) {
            newNode->previous = NULL;
            newNode->next = sequence->head;
            if (sequence->head != NULL) {
                sequence->head->previous = newNode;
            }
            sequence->head = newNode;
        }
            // Insert at the end
        else if (position == sequence->size) {
            newNode->previous = sequence->tail;
            newNode->next = NULL;
            sequence->tail->next = newNode;
            sequence->tail = newNode;
        }
            // Insert in the middle
        else {
            sequence_node *current = sequence->head;
            for (int i = 0; i < position - 1; ++i) {
                current = current->next;
            }
            newNode->previous = current;
            newNode->next = current->next;
            current->next->previous = newNode;
            current->next = newNode;
        }

        ++sequence->size;
    }
}

void deleteBase(DNA_sequence *sequence, int position) {
    if (position < 0 || position >= sequence->size) {
        printf("Invalid position for deletion\n");
        return;
    }

    sequence_node *nodeToDelete;

    if (position == 0) {
        nodeToDelete = sequence->head;
        sequence->head = sequence->head->next;
        if (sequence->head != NULL) {
            sequence->head->previous = NULL;
        }
    } else if (position == sequence->size - 1) {
        nodeToDelete = sequence->tail;
        sequence->tail = sequence->tail->previous;
        if (sequence->tail != NULL) {
            sequence->tail->next = NULL;
        }
    } else {
        sequence_node *current = sequence->head;
        for (int i = 0; i < position; ++i) {
            current = current->next;
        }
        nodeToDelete = current;
        current->previous->next = current->next;
        current->next->previous = current->previous;
    }

    free(nodeToDelete->DNABase);
    free(nodeToDelete);

    --sequence->size;
}

int searchPattern(sequence_node * startNode, const BASE_TYPE *pattern, int patternSize, int startPosition) {
    sequence_node *current = startNode;
    int position = 0;

    while (current != NULL) {
        int matched = 1;
        sequence_node *temp = current;

        for (int i = 0; i < patternSize; ++i) {
            if (temp == NULL || temp->DNABase->baseType != pattern[i]) {
                matched = 0;
                break;
            }
            temp = temp->next;
        }

        if (matched) {
            return position + startPosition;
        }

        ++position;
        current = current->next;
    }

    return -1; // Pattern not found
}

// Function to print the DNA sequence
void printSequence(DNA_sequence *sequence) {
    sequence_node *current = sequence->head;
    while (current != NULL) {
        switch (current->DNABase->baseType) {
            case A:
                printf("A");
                break;
            case C:
                printf("C");
                break;
            case G:
                printf("G");
                break;
            case T:
                printf("T");
                break;
            default:
                printf("N");
        }
        current = current->next;
    }
    printf("\n");
}

int isEventOccurs(double probability) {
    return (rand() % 100) < (probability * 100);
}

BASE_TYPE getRandomBase() {
    int randomNumber = rand() % 4; // Generate a random number between 0 and 3
    switch (randomNumber) {
        case 0:
            return A;
        case 1:
            return C;
        case 2:
            return G;
        case 3:
            return T;
        default:
            return A; // Default case (not really necessary in this context)
    }
}

int generate_random_number(int min_value, int max_value) {
    if (max_value < min_value) {
        return 0;
    }

    if (max_value == min_value) {
        return max_value;
    }

    /* Generates a random number between the specified minimum and maximum values. */
    int random_number = rand() % (max_value - min_value + 1) + min_value;
    return random_number;
}

sequence_node* getNodeAtIndex(DNA_sequence* sequence, int index) {
    if (index < 0 || index >= sequence->size) {
        return NULL; // Invalid index
    }

    sequence_node* current = sequence->head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    return current;
}

void applySpecialPatternsProperties(DNA_sequence* sequence, BASE_TYPE* pattern, int patternSize) {
    int position = searchPattern(sequence->head, pattern, patternSize,0);

    if (position != -1){
        if (pattern[0] == A) {
            while (position != -1){
                sequence->maxLifespan += 1;
                sequence_node * current = getNodeAtIndex(sequence,position +3);

                int  i ;
                for (i = position + 3; i < sequence->size; ++i) {
                    if (current == NULL || current->DNABase->baseType != A) break;
                    sequence->maxLifespan++;
                    current = current->next;
                }
                position = searchPattern(current,pattern,3,i);
            }
        }
        else if (pattern[0] == C) {
            while (position != -1){
                sequence->maxLifespan -= 1;
                sequence_node * current = getNodeAtIndex(sequence,position +3);
                int  i;
                for (i = position + 3; i < sequence->size; ++i) {
                    if (current == NULL || current->DNABase->baseType != C) break;
                    sequence->maxLifespan--;
                    current = current->next;
                }
                position = searchPattern(current,pattern,3,i);
            }

        }
        else if (pattern[0] == G) {
            int halfSize = (sequence->size % 2 == 0) ? sequence->size/2 : (sequence->size +1) /2;
            int index = 1;
            while (halfSize != sequence->size){
                deleteBase(sequence,index);
                index++;
            }

        }
        else if (pattern[0] == T) {
            sequence_node* current = sequence->tail;
            while (current != NULL) {
                addBase(sequence, current->DNABase->baseType);
                current = current->previous;
            }
        }
    }



}

void lifeCycleLoop(DNA_sequence *sequence) {
    int position;

    BASE_TYPE patternA[] = {A,A,A};
    BASE_TYPE patternC[] = {C,C,C};
    BASE_TYPE patternG[] = {G,G,G};
    BASE_TYPE patternT[] = {T,T,T};


    while (sequence->currentAge < sequence->maxLifespan && sequence->size != 0) {
        printSequence(sequence);
        if (isEventOccurs(sequence->growthProbability)) {

            position = generate_random_number(0, sequence->size);
            insertBase(sequence, getRandomBase(), position);
        }

        if (isEventOccurs(sequence->deletionProbability)) {
            position = generate_random_number(0, sequence->size-1);
            deleteBase(sequence, position);

        }

        if (isEventOccurs(sequence->mutationProbability)) {
            position = generate_random_number(0, sequence->size-1);
            BASE_TYPE newBaseType = getRandomBase();

            sequence_node *current = sequence->head;

            for (int i = 0; i < position; ++i) {
                current = current->next;
            }

            if (current != NULL) {
                current->DNABase->baseType = newBaseType;
            }


        }

        if (sequence->currentAge == 5) sequence->mutationProbability = 0.1;
        if (sequence->currentAge > 5) sequence->mutationProbability += 0.01;

        applySpecialPatternsProperties(sequence,patternA,3);
        applySpecialPatternsProperties(sequence,patternC,3);
        applySpecialPatternsProperties(sequence,patternG,3);
        applySpecialPatternsProperties(sequence,patternT,3);

        ++sequence->currentAge; //each iteration represents an increase in the DNA sequence’s current age
    }

    if (sequence->size <= 0) printf("Sequence Died\n");
    else printf("Sequence has reached maximum lifespan\n");

}