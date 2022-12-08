#include <conio.h>
#include <stdio.h>
#include<time.h>
int menu();
void two_wheeler();
void three_wheeler();
void four_wheeler();
void heavy_wheeler();
void show_details();
void consumer_details();
void personal_detail();
void amount_earned();
void show_emptyspace();
void del();
void generate_receipt();
void buy_membership();
int notwo=0,nothree=0,nofour=0,noheavy=0;
int amount=0,count=0;
struct con{
char name[100];
int mb;
char type[100];}c;
FILE *fp;
int main() {
    printf("*****WELCOME TO PARKING SYSTEM****** \n");
    printf("*******Menu********\n");
    while(1){
    switch(menu()){
        case 1:
        two_wheeler();
        break;
        case 2:
        three_wheeler();
        break;
        case 3:
        four_wheeler();
        break;
        case 4:
        heavy_wheeler();
        break;
        case 5:
        consumer_details();
        break;
        case 6:
        del();
        break;
        case 8:
        buy_membership();
        break;
        default:
        printf("invalid choice");
        
    }
    printf("press any key to continue further......");
    getch();}
    

    return 0;
}
//void generate_receipt(){
//    show_details();
//    time_t t = time(NULL);
//    printf("\n Current date and time is : %s", ctime(&t));
//}
int menu(){
    printf("enter 1 to park two wheller \n");
    printf("enter 2 to park three wheller\n");
    printf("enter 3 to park four wheller\n");
    printf("enter 4 to park heavy wheller\n");
    printf("enter 5:show consumer who have parked vehcile\n");
    printf("enter 6:delete data\n");
    printf("enter 7:show availabe spaces in parking lot\n");
    printf("enter 8:buy membership of a month\n");
    int ch;
    printf("\nenter choice\n");
    scanf("%d",&ch);
    return(ch);
    
}

void personal_detail(){
  fp = fopen("consumer.txt","w");
  printf("Enter Your Name--->"); 
  fflush(stdin);
  scanf("%s",c.name);
    printf("enter mobile no----> ");
    fflush(stdin);
    scanf("%d",&c.mb);
    printf("enter vehicle type(two,three,four,heavy)----->");
    fflush(stdin);
    scanf("%s",c.type);
    printf("PERSONAL DETAILS ENTERED SUCCEFULLY!!!!!!");
    fwrite(&c,sizeof(c),1,fp);
    fclose(fp);
    
}
void consumer_details(){
    personal_detail();
    printf("****COSTUMER INFORMATION**\n\n");
    
    printf("%-20s %-20s %-20s \n\n ","NAME","MOBILE NUMBER","TYPE OF VEHICLE");
    fp=fopen("consumer.txt","r");
    while(fread(&c,sizeof(c),1,fp)==1){
        printf("%-20s %-20d %-20s \n\n",c.name,c.mb,c.type);
        
    }
    fclose(fp);
}
void show_detail(){
    printf("no of two wheller is %d",notwo);
    printf("no of three wheller is %d",nothree);
    printf("no of four wheller is %d",nofour);
    printf("no of heavy wheller is %d",noheavy);
    printf("total no of vehicle is %d",count);
}
void amount_earned(){
    printf("total amount earned %d",amount);
    
}
void del(){
    notwo=0,nothree=0,nofour=0,noheavy=0;
    amount=0,count=0;
    
}
void two_wheeler(){
    personal_detail();
    notwo++;
    printf(" the amount 50 rs per hour \n");
    int timed;
    printf("enter the no of hour to park vehicle \n");
    scanf("%d",&timed);
    amount=amount+(50*timed);
    count++;
    printf("amount to be paid %d",amount);
    printf("\namount entered succefully,vehicle is now being parked\n");
}
void three_wheeler(){
    personal_detail();
    nothree++;
    printf(" the amount 100 rs per hour \n");
    int timed;
    printf("enter the no of hour to park vehicle \n");
    scanf("%d",&timed);
    amount=amount+(100*timed);
    count++;
    printf("amount entered succefully,vehicle is now being parked");
}

void four_wheeler(){
    personal_detail();
    nofour++;
    printf("the amount 150 rs per hour \n");
    int timed;
    printf("enter the no of hour to park vehicle \n");
    scanf("%d",&timed);
    amount=amount+(150*timed);
    count++;
    printf("amount entered succefully,vehicle is now being parked");
}

void heavy_wheeler(){
    personal_detail();
    noheavy++;
    printf("the amount 500 rs per hour \n");
    int timed;
    printf("enter the no of hour to park vehicle \n");
    scanf("%d",&timed);
    amount=amount+(500*timed);
    count++;
    printf("\namount entered succefully,vehicle is now being parked\n");
}
void buy_membership(){
    personal_detail();
    printf("membership cost of two wheeler will be 5000 per month\n");
    printf("membership cost of three wheeler will be 7000 per month\n");
    printf("membership cost of four wheeler will be 10000 per month\n");
    printf("membership cost of heavy wheeler will be 20000 per month\n");
    printf("enter choice of vehicle to buy membership for?\n");
    printf("enter 1 to park two wheller \n");
    printf("enter 2 to park three wheller\n");
    printf("enter 3 to park four wheller\n");
    printf("enter 4 to park heavy wheller\n");
    int cho;
    scanf("%d",&cho);
    if(cho==1){
        printf("pay 5000 per month\n");
        printf("enter amount");
        scanf("%d",&amount);
        if(amount<5000 || amount >5000){
            printf("read the amount carefully");
        }
        else{
            printf("amount paid succefully");
        }
        
    }
if(cho==2){
        printf("pay 7000 per month\n");
        printf("enter amount");
        scanf("%d",&amount);
        if(amount<7000 || amount >7000){
            printf("read the amount carefully");
        }
        else{
            printf("amount paid succefully");
        }
        
    }
if(cho==3){
        printf("pay 10000 per month\n");
        printf("enter amount");
        scanf("%d",&amount);
        if(amount<10000 || amount >10000){
            printf("read the amount carefully");
        }
        else{
            printf("amount paid succefully");
        }
        
    }
if(cho==4){
        printf("pay 7000 per month\n");
        printf("enter amount");
        scanf("%d",&amount);
        if(amount<15000 || amount >15000){
            printf("read the amount carefully");
        }
        else{
            printf("amount paid succefully");
        }
        
    }

    
}