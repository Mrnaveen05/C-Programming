#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
int op;
int bal;
int reg(){
    char name[100];
    char mob[10];
    char pass[30];
    char dob[20];
    char add[50];
    char mail[20];
    printf("*************************************\n");
    printf("REGISTRATION PROCESS FOR BANKING:\n");
    printf("*************************************\n");
    printf("Enter your name:\n");
    scanf("%s",&name);
    printf("Enter your mobile number:\n");
    scanf("%s",&mob);
    printf("Enter your Password:\n");
    scanf("%s",&pass);
    printf("Enter your Date of Birth:\n(DD/MM/YYYY)\n");
    scanf("%s",&dob);
    printf("Enter your Address:\n");
    scanf("%s",&add);
    printf("Enter your Email Id:\n");
    scanf("%s",&mail);
    printf("Enter your Initial Bal:\n");
    scanf("%d",&bal);

    char username[50];
    printf("Enter the name to create a folder:\n");
    scanf("%s",&username);
    char *folderName = username; // Replace with your desired folder name
    mkdir(folderName);

    char filename[200];
    sprintf(filename, "C:\\Users\\Naveenuuu\\Documents\\C\Scriptu\\%s",username);
    char *newDirectory;
    newDirectory=filename;
    chdir(newDirectory);

//For storing the mobile no in file
FILE *fm;
fm=fopen("mobno.txt","w");
fprintf(fm,"%s",mob);
fclose(fm);

FILE *fp;
fp=fopen("pass.txt","w");
fprintf(fp,"%s",pass);
fclose(fp);

FILE *fb;
fb=fopen("balance.txt","w");
fprintf(fb,"%d",bal);
fclose(fb);

FILE *fa;
fa=fopen("allfiles.txt","w");
fprintf(fa,"%s\n %s\n %s\n %s\n",name,dob,add,mail);
fclose(fa);
    }
int credit(){
    int cb;
printf("Enter The amount to be credited..:\n");
scanf("%d",&cb);//1000

if(cb<0){
    printf("Enter the Proper amount:\n");
    credit();
}else{
    bal+=cb;
    printf("Now Your Current balance is..: %d\n",bal);
}
char sbal[100];
sprintf(sbal,"%d",cb);

//for history purpose
FILE *fh;
fh=fopen("history.txt","a");
fprintf(fh,"%s\n",sbal);
fclose(fh);

show();

}

int debit(){
    int db;
printf("Enter the amount to be debited..:\n");
scanf("%d",&db);
if(bal>db){
    bal-=db;
    printf("Now Your balance is..:%d\n",bal);
}else{
printf("Insufficient Balance\nEnter the proper amnt\n");
debit();
}
show();
}
int enq(){
    char upw[10];
    printf("Enter the password:\n");
    scanf("%s",&upw);

    char pw[20];

   FILE *fx;
   fx=fopen("pass.txt","r");
   fscanf(fx,"%s",pw);
   fclose(fx);

    if((strcmp(upw,pw))==0){
    printf("%d is Your Balance\n",bal);
    show();
}else{
    printf("Please Enter the correct password:\n");
    enq();
}
}
int transfer(){
    char fname[20];char toname[20];int amnt;
printf("Enter the account name from transfer amount:\n");
scanf("%s",&fname);
printf("Enter the account name to be transfer amount:\n");
scanf("%s",&toname);
printf("Enter the amount to be transfered:\n");
scanf("%d",&amnt);

    char filename[200];
    sprintf(filename, "C:\\Users\\Naveenuuu\\Documents\\C\\Scriptu\\%s",fname);
    char *newDirectory;
    newDirectory=filename;
    chdir(newDirectory);

    //to read the balance from_file
    char buff[200];
    FILE* fs;
    fs=fopen("balance.txt","r");
    fscanf(fs,"%s",buff);
    printf("%s is %s\n",fname,buff);
    fclose(fs);

    //from string to integer:
    int f_bal=atoi(buff);
    printf("The integer is %d\n",f_bal);

if(f_bal>amnt){
        f_bal-=amnt;
        char push[100];
        sprintf(push,"%d",f_bal);

        FILE* fi;
        fi=fopen("balance.txt","w");
        fprintf(fi,push);
        fclose(fi);

    char filenamee[200];
    sprintf(filenamee, "C:\\Users\\Naveenuuu\\Documents\\C\\Scriptu\\%s",toname);
    char *nd;
    nd=filenamee;
    chdir(nd);

    //read bal to_file
    char data[200];
    FILE* fx;
    fx=fopen("balance.txt","r");
    fscanf(fx,"%s",data);
    printf("%s balance is %s\n",toname,data);
    fclose(fx);

    int t_bal=atoi(data);

    int n_bal=t_bal+amnt;

    char bull[100];
    sprintf(bull,"%d",n_bal);

    FILE* fa;
    fa=fopen("balance.txt","w");
    fprintf(fa,bull);
    fclose(fa);

    show();
}
else{
    printf("Insufficient Balance\n");
    show();
}
}
int login(){
        char mob2[70];
        char pass2[10];
        printf("Mobile number:\n");
        scanf("%s",&mob2);
        printf("Password: \n");
        scanf("%s",&pass2);
        char mob1[60];
        char pass1[20];
   FILE *fm;
   fm=fopen("mobno.txt","r");
   fscanf(fm,"%s",mob1);
   printf("%s\n",mob1);
   fclose(fm);

   FILE *fp;
   fp=fopen("pass.txt","r");
   fscanf(fp,"%s",pass1);
   printf("%s\n",pass1);
   fclose(fp);

   if(((strcmp(mob1,mob2))&&(strcmp(pass1,pass2)))==0){

    show();

   }
   else{
    printf("\nIncorrect mobile number or password!\n");
   }
 }
 int history()
 {
    FILE *fr;
    fr=fopen("history.txt","r");
    char abc[200];
    while(fscanf(fr,"%s",abc)!=EOF){
        printf("%s\n",abc);
    }
    fclose(fr);
    show();
 }
 int show(){
     int t;
     printf("Do you want to continue the process..?\n 1.Yes\n 2.No\n");
     scanf("%d",&t);
if(t==1){
      printf("\n Choose Your OPtion:\n 1.Credit\n 2.Debit\n 3.Balance Enquiry\n 4.Exit\n 5.Fund Transfer\n 6.History\n");
      int abc;
      scanf("%d",&abc);
      switch(abc){
    case 1:
        credit();
        break;
    case 2:
        debit();
        break;
    case 3:
        enq();
        break;
    case 4:
        printf("Thanking YOu..!\n");
        break;
    case 5:
        transfer();
        break;
    case 6:
        history();
        break;
    }
    }
else{
    printf("OK., Nice to meet you..!");
    }
}

int main(){
reg();
printf("Do you want to continue for the login page?\n 1.Yes\n 2.No\n");
        scanf("%d",&op);
        if(op==1){
             login();
        }
        else{
                printf("ThankYou!");
        }
}

