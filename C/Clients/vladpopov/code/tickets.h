#ifndef CODE_TICKETS_H
#define CODE_TICKETS_H
int getDayAndTickets(const int* daysNtickets,int day){
    if (daysNtickets[day-1] == 0) return 0;
    else return 1;
}

int* findMaxMinArr(const int* daysNtickets,int size,int start, int end){
    static int minNmax[4] ;
    for (int i = start-1; i < end; ++i) {
        if(i == start-1){
            minNmax[0] = daysNtickets[start-1];
            minNmax[3] = i + 1;
            minNmax[2] = daysNtickets[start-1];
            minNmax[1] = i + 1;
            continue;
        }
        if(minNmax[2] < daysNtickets[i]){
            minNmax[2] = daysNtickets[i];
            minNmax[3] = i + 1;
        }
        if(minNmax[0] > daysNtickets[i]){
            minNmax[0] = daysNtickets[i];
            minNmax[1] = i + 1;
        }



    }

    return  minNmax;
}

void doTickets(){
    // {{day,tickets}}
    int daysNTickets[7] = {0,0,0,0,0,0,0};
    int startDate;
    int endDate;

    printf("Enter start day of festival between 1 and 7\n");
    scanf("%d",&startDate);

    while (startDate > 7 || startDate < 1){
        printf("Invalid input!\n");
        printf("Enter start day of festival between 1 and 7\n");
        scanf("%d",&startDate);
    }

    printf("Enter end day of festival between %d and 7\n",startDate);
    scanf("%d",&endDate);

    while (endDate > 7 || endDate < startDate){
        printf("Invalid input!\n");
        printf("Enter start day of festival between %d and 7\n",startDate);
        scanf("%d",&endDate);
    }

    int userChoice;
    int ticketCount;
    while(1) {
        printf("enter day (%d to %d) enter 0 to stop\n",startDate,endDate);
        scanf("%d",&userChoice);

        if(userChoice < startDate || userChoice > endDate){
            if (userChoice == 0) break;
            else{

                printf("Invalid input try again!\n");
                continue;
            }

        }
        printf("enter tickets count\n");
        scanf("%d",&ticketCount);
        if(ticketCount < 0){
            printf("Invalid input try again!\n");
            continue;
        }

        daysNTickets[userChoice-1] += ticketCount;
    }

    int * minMax = findMaxMinArr(daysNTickets, 7, startDate, endDate);
    int flag = 0;
    printf("The day with max tickets is %d tickets: %d\n",minMax[3],minMax[2]);

    for (int i = startDate-1; i < endDate; ++i) {
        if(getDayAndTickets(daysNTickets,i+1) != 1){
            printf("The day with min tickets is %d tickets: %d\n",i+1,0);
            flag =1;
        }

    }
    if(flag == 0){
        printf("The day with min tickets is %d tickets: %d\n",minMax[1],minMax[0]);
    }

}
#endif //CODE_TICKETS_H
