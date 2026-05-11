//Movie Ticket Booking System
#include<stdio.h>
#include<stdlib.h>

#define M 3
#define S 2
#define R 5
#define C 5

int seats[M][S][R][C]={0};
int BOOKCounter=100;

struct movie{
    int MovieID;
    char MovieName[30];
    char MovieLanguage[20];
    int MovieDuration;
    float MovieRating;
    char MovieCertificate[10];
    char Morningshow[10];
    char Eveningshow[10];
};
struct Booking{
    int BookingID;
    int MID;
    int row,col;
    int Ticketcode;
};
void menu(){
    printf("\tTICKET BOOKING SYSTEM\n");
    printf("1.Book Ticket\n");
    printf("2.Cancel Ticket\n");
    printf("3.Exit..\n");
    printf("Enter your choice:");

}
void displayMovies(struct movie m[],int size){
    for(int i=0;i<size;i++){
        printf("ID:%d Name:%s Rating:%.1f Language:%s MorningShow:%s EveningShow:%s\n",m[i].MovieID,m[i].MovieName,m[i].MovieRating,m[i].MovieLanguage,m[i].Morningshow,m[i].Eveningshow);

    }
}
void draw(int mIndex,int sIndex){
    printf("\tSEATS\n");
    for(int i=0;i<R;i++){
        printf("%c ",'A'+i);
        for(int j=0;j<C;j++){
            if(seats[mIndex][sIndex][i][j]==0){
                printf("[%d] ",j+1);
            }
            else{
                printf("[X] ");
            }
        }
        printf("\n");
    }
}
void BookTicket(int mIndex,int sIndex){
    int n;
    draw(mIndex,sIndex);
    printf("\nHow many seats:");
    scanf("%d",&n);
    int column[n];
    char row[n];

    for(int i=0;i<n;i++){
        printf("Enter seat:");
        scanf(" %c%d",&row[i],&column[i]);
    
        if(row[i]>='a' && row[i]<='z'){
            row[i]=row[i]-32;
    }
    }
    for(int i=0;i<n;i++){
        int r=row[i]-'A';
    
        int col=column[i]-1;
    
    if(r<0 || r>R || col<0 || col>C){
        printf("INVALID SEAT: %c%d",row[i],column[i]);
        continue;
    }
    if(seats[mIndex][sIndex][r][col]==1){
        printf("ALREADY BOOKED!!: %c%d",row[i],column[i]);
        continue;

    }

    seats[mIndex][sIndex][r][col]=1;
}
    printf("\tTICKET BOOKED SUCCESSFULLY\n");
    printf("SEATS BOOKED:");
    for(int i=0;i<n;i++){
        printf(" %c%d ",row[i],column[i]);
    }
    draw(mIndex,sIndex);
    

}
void cancelTicket(int mIndex,int sIndex){
    int column;
    char row;

    printf("Enter seat to be cancelled:");
    scanf(" %c%d",&row,&column);

    int rowc=row-'A';
    column=column-1;

    if(rowc<0||rowc>R||column<0||column>C){
        printf("INVALID\n");
    }

    if(seats[mIndex][sIndex][rowc][column]==0){
        printf("Already seat free");
        return;
    }

    seats[mIndex][sIndex][rowc][column]=0;

    printf("Seat cancelled");
}
int main(){
    struct movie m[3]={{1,"Avengers Endgame","English",180,9.3,"UA","10:10 AM","6:15 PM"},{2,"DUNE 3","English",165,9.1,"UA","9:00 AM","3:00 PM"},{3,"Jana Nayagan","Tamil",150,9.5,"UA","11:30 AM","4:30 PM"}};

    int choice;
    int mChoice;
    int sChoice;
    
    while(1){
        menu();
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            displayMovies(m,3);

            printf("Select movie id:");
            scanf("%d",&mChoice);

            printf("Select show:");
            printf("\nShow 1:%s\n",m[mChoice-1].Morningshow);
            printf("Show 2:%s\n",m[mChoice-1].Eveningshow);
            scanf("%d",&sChoice);

            BookTicket(mChoice-1,sChoice-1);

            break;
        case 2:
            printf("Select movie id:");
            scanf("%d",&mChoice);

            printf("Select show:");
            printf("Show 1:%s\n",m[mChoice-1].Morningshow);
            printf("Show 2:%s\n",m[mChoice-1].Eveningshow);
            scanf("%d",&sChoice);

            cancelTicket(mChoice-1,sChoice-1);

            break;
        case 3:
            printf("Exiting...\n");
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}