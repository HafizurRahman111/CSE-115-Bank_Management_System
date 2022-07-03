#include <stdio.h>

#include <stdlib.h>

#include <string.h>


struct person {
   char name[50];
   int age;
   int acc_num;
   char acc_type[10];
   float balance;

};

struct person s[50];

FILE * m, * n;
FILE * temp;

void start() {

   printf("\n\n \t\t   Project : Bank Management System  \n\n");
   printf("\n\n\t\t\t   Name    : MD. HAFIZUR RAHMAN   ");
   printf("\n  \t\t\t   ID NO   :                       ");
   printf("\n  \t\t\t   Section :                       ");
   printf("\n\n  \t\t\t   Course  : CSE-115               ");
   printf("\n  \t\t\t   Date    : 13/08/2015\n\n           ");

}

int printMenu() {

   int choice;

   printf("\n ----|*********************************************************|-----");
   printf("\n     |          1. Add Account                                 |  ");
   printf("\n     |          2. Find Total Balance                          |  ");
   printf("\n     |          3. Average Balance                             |  ");
   printf("\n     |          4. Max Balance                                 |  ");
   printf("\n     |          5. Min Balance                                 |  ");
   printf("\n     |          6. Maximum Age                                 |  ");
   printf("\n     |          7. Minimum Age                                 |  ");
   printf("\n     |          8. Search an account by account number         |  ");
   printf("\n     |          9. See all calculation of accounts             |  ");
   printf("\n     |          10. Copy Stored File                           |  ");
   printf("\n     |          11. Exit                                       |  ");
   printf("\n ----|*********************************************************|-----");

   printf("\n\n Enter your choice :\t");
   scanf("%d", & choice);

   return choice;

}

void addAccount1() {
   int i, n;

   printf("\n\n\t\t We are in Option - 1 ( Add Account )\n");

   m = fopen("masterfile.txt", "w");

   fflush(stdin);

   printf("\n\tEnter the number(How many accounts you want to add ) :\t");
   scanf("%d", & n);

   fflush(stdin);

   printf("\n\tEnter your inputs:\n");

   for (i = 1; i <= n; i++) {

      printf("\n\nPerson %d \n\n\tName :\t", i);
      scanf("%s", s[i].name);
      fflush(stdin);

      printf("\tAge  :\t");
      scanf("%d", & s[i].age);
      fflush(stdin);

      printf("\n\tAccount no   : ");
      scanf("%d", & s[i].acc_num);
      fflush(stdin);

      printf("\n\tAccount Type : ");
      scanf("%s", s[i].acc_type);
      fflush(stdin);

      printf("\n\tBalance      : ");
      scanf("%f", & s[i].balance);
      fflush(stdin);

   }

   fprintf(m, "%d\n", n);

   for (i = 1; i <= n; i++)

   {

      fprintf(m, "%d Name : %s Age : %d Account no : %d Account Type : %s Balance : %.2f\n", i, s[i].name, s[i].age, s[i].acc_num, s[i].acc_type, s[i].balance);

   }

   fclose(m);

   printf("\n\n\t\tAccount added successfully\n\n\n\t\t\t*** THANK YOU ***\n\n\n");

   return;

}

void total_balance2() {
   int i, n;

   float sum;

   printf("\n\n\t\t We are in Option - 2 ( Find Total Balance )\n");

   m = fopen("masterfile.txt", "r");

   if (m == NULL) {
      printf(" FILE Error. ");
      return -1;
   }

   fscanf(m, "%d", & n);

   printf("\n Total Account =  %d\n", n);

   sum = 0;

   for (i = 1; i <= n; i++) {

      fscanf(m, "%s %d %d %s %.2f", s[i].name, & s[i].age, & s[i].acc_num, s[i].acc_type, & s[i].balance);

      sum = sum + s[i].balance;

   }

   printf("\n Total Balance of all accounts =  %.2f\n\n\n", sum);

   rewind(m);

   fclose(m);

}

void average_balance3() {
   int i, n;

   float sum, avrg;

   printf("\n\n\t\t We are in option - 3 ( Average of Balances )\n");

   m = fopen("masterfile.txt", "r");

   if (m == NULL) {
      printf(" FILE Error. ");
      return -1;
   }

   fscanf(m, "%d", & n);

   printf("\n Total Account =  %d\n", n);

   sum = 0;

   for (i = 1; i <= n; i++) {

      fscanf(m, "%s %d %d %s %.2f", s[i].name, & s[i].age, & s[i].acc_num, s[i].acc_type, & s[i].balance);

      sum = sum + s[i].balance;

   }

   avrg = (sum * 1.0) / n;

   printf("\n Average of balances =  %.2f\n\n\n", avrg);

   rewind(m);

   fclose(m);

}

void max_balance4() {
   int i, n;

   float balance_mx, max_balance = -1;

   printf("\n\n\t\t We are in option - 4 ( Find Maximum Balance )\n");

   m = fopen("masterfile.txt", "r");

   if (m == NULL) {
      printf(" FILE Error. ");
      return -1;
   }

   fscanf(m, "%d", & n);

   printf("\n Total Account =  %d\n", n);

   for (i = 1; i <= n; i++) {
      fscanf(m, "%s %d %d %s %.2f", s[i].name, & s[i].age, & s[i].acc_num, s[i].acc_type, & s[i].balance);

      if (s[i].balance > max_balance) {
         max_balance = s[i].balance;

         balance_mx = s[i].balance;

      }

   }

   printf("\n The Maximum Balance   =  %.2f\n\n\n", balance_mx);

   fclose(m);

}

void min_balance5() {
   int i, n;

   float min_balance;

   printf("\n\n\t\t We are in option - 5 ( Find Minimum Balance )\n");

   m = fopen("masterfile.txt", "r");

   if (m == NULL) {
      printf(" FILE Error. ");
      return -1;
   }

   fscanf(m, "%d", & n);
   fflush(stdin);

   for (i = 1; i <= n; i++) {
      fscanf(m, "%s %d %d %s %.2f", s[i].name, & s[i].age, & s[i].acc_num, s[i].acc_type, & s[i].balance);

      if (s[i].balance < min_balance) {
         min_balance = s[i].balance;

      }

   }

   printf("\n The Minimum Balance   =  %.2f\n\n\n", min_balance);

   fclose(m);

}

void max_age6()

{
   int i, j, n, maxAge = -1;

   float balance, sum;

   printf("\n\n\t\t We are in option - 6 ( Find Maximum Age )\n");

   m = fopen("masterfile.txt", "r");

   if (m == NULL) {
      printf(" FILE Error. ");
      return -1;
   }

   fscanf(m, "%d", & n);

   sum = 0;

   for (i = 1; i <= n; i++) {

      fscanf(m, "%s %d %d %s %.2f", s[i].name, & s[i].age, & s[i].acc_num, s[i].acc_type, & s[i].balance);

      sum = sum + s[i].balance;

   }

   rewind(m);

   fscanf(m, "%d", & n);

   for (i = 1; i <= n; i++) {

      fscanf(m, "%s %d %d %s %.2f", s[i].name, & s[i].age, & s[i].acc_num, s[i].acc_type, & s[i].balance);

      if (s[i].age > maxAge) {
         maxAge = s[i].age;

         balance = s[i].balance;

      }

   }

   printf("\n The Maximum Age = %d", maxAge);
   printf("\n\n Balance = %.2f", balance);

   fclose(m);

}

void min_age7()

{
   int i, j, n, minAge;

   float balance, sum;

   printf("\n\n\t\t We are in option - 7 ( Find Minimum Age )\n");

   m = fopen("masterfile.txt", "r");

   if (m == NULL) {
      printf(" FILE Error. ");
      return -1;
   }

   fscanf(m, "%d", & n);

   sum = 0;

   for (i = 1; i <= n; i++) {

      fscanf(m, "%s %d %d %s %.2f", s[i].name, & s[i].age, & s[i].acc_num, s[i].acc_type, & s[i].balance);

      sum = sum + s[i].balance;

   }

   rewind(m);

   fscanf(m, "%d", & n);

   for (i = 1; i <= n; i++) {

      fscanf(m, "%s %d %d %s %.2f", s[i].name, & s[i].age, & s[i].acc_num, s[i].acc_type, & s[i].balance);

      if (s[i].age < minAge) {
         minAge = s[i].age;

         balance = s[i].balance;

      }

   }

   printf("\n The Minimum Age = %d", minAge);
   printf("\n\n Balance = %.2f", balance);

   fclose(m);

}

void search_acc_no8() {
   int acc_n, i, ch;

   ch = 1;

   printf("\n\n\t\t We are in option - 8 ( Search an account by account number )\n");

   while (ch) {
      m = fopen("masterfile.txt", "r");

      printf(" \n ENTER ACCOUNT NUMBER - ");
      scanf("%d", & acc_n);
      i = 1;

      while (!feof(m)) {
         fscanf(m, "%s %d %d %s %.2f", s[i].name, & s[i].age, & s[i].acc_num, s[i].acc_type, & s[i].balance);

         if (acc_n == s[i].acc_num) {
            printf("\nAccount Number  Balance   Type\n ");

            printf("      %d         %.2f    %s\n\n", s[i].acc_num, s[i].balance, s[i].acc_type);

            break;

         } else
            i = i + 1;
      }
      printf("\n\npress 1 to See Accounts Info, 0 to return to main menu\n\n");

      scanf("%d", & ch);

      fclose(m);

   }

}

void all_calculation9() {

   int i, n, maxAge;

   float balance_mx, max_balance = -1, avrg, sum;

   m = fopen("masterfile.txt", "r");

   if (m == NULL) {
      printf(" FILE Error. ");
      return -1;
   }

   fscanf(m, "%d", & n);

   printf("\n Total Accounts = %d", n);

   sum = 0;

   for (i = 1; i <= n; i++) {
      fscanf(m, "%s %d %d %s %.2f", s[i].name, & s[i].age, & s[i].acc_num, s[i].acc_type, & s[i].balance);

      sum = sum + s[i].balance;

   }

   printf("\n Total Balance = %.2f", sum);

   avrg = (sum * 1.0) / n;

   printf("\n Average is = %.2f\n", avrg);

   rewind(m);

   fscanf(m, "%d", & n);

   for (i = 1; i <= n; i++) {
      fscanf(m, "%s %d %d %s %.2f", s[i].name, & s[i].age, & s[i].acc_num, s[i].acc_type, & s[i].balance);

      if (s[i].balance > max_balance) {
         max_balance = s[i].balance;
         balance_mx = s[i].balance;
      }

   }

   printf("\n The Maximum Balance = %.2f", balance_mx);

   for (i = 1; i <= n; i++) {

      fscanf(m, "%s %d %d %s %.2f", s[i].name, & s[i].age, & s[i].acc_num, s[i].acc_type, & s[i].balance);

      if (s[i].age > maxAge) {
         maxAge = s[i].age;

      }
   }

   printf("\n The Maximum Age = %d", maxAge);

   fclose(m);

}

void copy_file10() {

   char file2[20];

   char ch;

   m = fopen("masterfile.txt", "r");

   if (m == NULL) {
      printf("Cannot open %s", m);
      exit(0);

   }

   printf("\n\nEnter The New Copied File name : ");
   scanf("%s", file2);

   n = fopen(file2, "w");

   if (n == NULL) {
      printf("Cannot open %s", file2);
      exit(0);

   }
   while ((ch = getc(m)) != EOF)

      putc(ch, n);

   printf("\n\t\t COMPLETED\n\n");

   fclose(m);
   fclose(n);

}

int main() {
   int k;

   start();

   do {

      k = printMenu();

      switch (k) {
      case 1:
         addAccount1();
         break;

      case 2:
         total_balance2();
         break;

      case 3:
         average_balance3();
         break;

      case 4:
         max_balance4();
         break;

      case 5:
         min_balance5();
         break;

      case 6:
         max_age6();
         break;

      case 7:
         min_age7();
         break;

      case 8:
         search_acc_no8();
         break;

      case 9:
         all_calculation9();
         break;

      case 10:
         copy_file10();
         break;

      case 11:
         printf("\n\n\t\tThank you, Good bye .....\n\n\n");
         break;

      default:
         printf("Wrong choice, try again");
         break;

      }

   } while (k != 11);

   return 0;

}