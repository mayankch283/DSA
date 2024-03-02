#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Day{
  int date;
  char * name;
  char * activity;
};

struct Day * calendar[7];

void create(){
  for(int i=0; i<7; i++){
    calendar[i] = (struct Day *)malloc(sizeof(struct Day));
    calendar[i]->name = (char *)malloc(20*sizeof(char)) ;
    calendar[i]->activity = (char *)malloc(50*sizeof(char));

    printf("Enter day name: ");
    scanf("%s", calendar[i]->name);
    printf("Enter date: ");
    scanf("%d", &calendar[i]->date);
    printf("Enter activity: ");
    scanf(" %s",calendar[i]->activity);
    printf("\n");
  }  
}

void display(){
  for (int i = 0; i < 7; i++) {
   printf("Day %d\n", i + 1);
   printf("Day name: %s\n", calendar[i]->name);
   printf("Date: %d\n", calendar[i]->date);
   printf("Activity: %s\n", calendar[i]->activity);
   printf("\n");
 }
}

int main(){
  printf("\nCreating calendar");
  create();
  printf("\nDisplaying calendar");
  display();

  //free up memory
  for(int i=0; i<7; i++){
    free(calendar[i]->name);
    free(calendar[i]->activity);
    free(calendar[i]);
  }
  
  return 0;
}
