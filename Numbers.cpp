#include <stdio.h>
#include <stdlib.h>

int main() {
   int i, amt_num = 0, amt_pair = 0, amt_odd, num_read;
   float sum_total = 0, num_avg, biggest_num, smaller_num, pair_avg, sum_pair = 0;
   float porcent_odd;
   char status = 'Y';
   
   while ((status != 'N') && (status != 'n')){
       system("cls");
       printf("Inform a number: ");
       scanf("%d",&num_read);
       
       sum_total += num_read;
       amt_num++;
       
       if (amt_num == 1){
           biggest_num = num_read;
           smaller_num = num_read;
       }
       else {
           if (num_read > biggest_num){
                biggest_num = num_read;           
           }
           
           if (num_read < smaller_num){
               smaller_num = num_read;
           }
       }
       
       if (num_read % 2 == 0){
           amt_pair++;
           sum_pair += num_read;
       }
       
       printf("\nContinue? [Y/N]: ");
       scanf("%s",&status);
   }
   
   num_avg = sum_total/amt_num;
   pair_avg = sum_pair/amt_pair;
   amt_odd = amt_num - amt_pair;
   porcent_odd = amt_odd * 100 / amt_num;
   
   printf("\n\nSum of all numbers informed: %.2f\n", sum_total);
   printf("Quantity of numbers informed: %d\n", amt_num);
   printf("Numbers' value average: %.2f\n", num_avg);
   printf("Biggest number: %.2f\n", biggest_num);
   printf("Smaller number: %.2f\n", smaller_num);
   
   printf("\nPair numbers quantity: %d\n", amt_pair);
   printf("Pair numbers value average: %.2f\n", pair_avg);
   printf("\nOdd numbers porcent: %.2f\n", porcent_odd);
   printf("\nOdd numbers quantity: %d\n", amt_odd);
}


