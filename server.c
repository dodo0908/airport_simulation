#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"server.h"

n* LANDorTAKEOFF(n* list,int n ,int o)
{
    struct node *temp,*prev;
    temp=list;
    int x,y,z,q;
    if(list!=0)
    {
        if(list->num>9999 && list->num<100000)
        {
            check(list,&q); // checks arrivals
            if(q==1) // arrivals on runway 1
            {
                while(temp!=NULL)
                {
                    if(list->num%2==0)
                    {
                        delay(5);
                        printf(" Runway 1 is busy \n %c%d plane has arrived \n",list->name,list->num);
                        temp=list;
                        list=temp->next;
                        free(temp);
                        n--;
                        break;
                    }
                    temp=temp->next;
                }
            }
            else printf("Runway 1 is Idle \n");
            temp=list;
            prev=list;
            check(list,&q);   // checks departures
            if(q==1)            //  departures on runway 2
            {
                while(temp!=NULL)
                {
                    if(list->num%2!=0)              // departure flight avialable in the front of the queue queue
                    {
                        delay(5);
                        printf(" Runway 2 is busy \n %c%d is taking off \n",temp->name,temp->num);
                        list=temp->next;
                        free(temp);
                        o--;
                        break;
                    }
                    else
                    {
                        if(list->num%2!=0)          // departure flight avialable in the middle of the queue queue
                        {
                            delay(5);
                            printf(" Runway 2 is busy \n %c%d is taking off \n",temp->name,temp->num);
                            prev->next=temp->next;
                            free(temp);
                            o--;
                            break;
                        }
                    }
                    prev=prev->next;
                    temp=temp->next;
                }
            }
            else printf("Runway 2 is Idle \n");
        }
        else  printf(" All Runways are idle \n");

        temp=list;

        if(list->num>9999 && list->num<100000) // arrival or departure depending on the queue on runway 3
        {
            if(list->num%2==0)              // arrival flight avialable in the queue
            {
                 while(temp!=NULL)
                {
                    if(list->num%2==0)
                    {
                        delay(5);
                        printf(" Runway 3 is busy \n %c%d plane has arrived \n",list->name,list->num);
                        temp=list;
                        list=temp->next;
                        free(temp);
                        n--;
                        break;
                    }
                    temp=temp->next;
                }
            }
            else                        // departure flight avialable in the queue
            {
                temp=list;
                prev=list;
                while(temp!=NULL)
                {
                    if(list->name==68)      // departure flight avialable in the front of the queue queue
                    {
                        delay(5);
                        printf(" Runway 3 is busy \n %c%d is taking off \n",temp->name,temp->num);
                        list=temp->next;
                        free(temp);
                        o--;
                        break;
                    }
                    else
                    {
                        if(temp->name==68)      // // departure flight avialable in the middle of the queue
                        {
                            delay(5);
                            printf(" Runway 3 is busy \n %c%d is taking off \n",temp->name,temp->num);
                            prev->next=temp->next;
                            free(temp);
                            o--;
                            break;
                        }
                    }
                    prev=prev->next;
                    temp=temp->next;
                }
            }
        }
        else
        {
            temp=list;
            printf(" Runway 3 is IDLE\n");
            list=temp->next;
            free(temp);

        }
    }
    else printf(" No Queue \n");
    temp=list;

    if(list!=NULL)
    {
        printf("list of Planes that were not given any call \n");
        print(list);
    }
    return list;
}

void check(n* list,int *y)  // checks any arrial or departure is present
{
    n* temp;
    *y=0;
    temp=list;
    if(list!=NULL)
    {
        while(temp!=NULL) // iterates through out the queue and counts no. of arrivals and departures
        {
            if(temp->num>9999 && temp->num<100000 && temp->num%2==0)
            {
               *y=1;
                break;
            }
            else if(temp->num>9999 && temp->num<100000 && temp->num%2!=0)
            {
                *y=1;
                break;
            }
            else
            {
                temp=temp->next;
            }
        }
    }
    else *y=0;
}


n* queue(n* list,int x,int y) // queue is made up
{
    n *new, *temp;
    temp=list;

    new = (n *) malloc (sizeof (n));
    new->num = x;
    new->name=y;
    if(x>9999 && x<100000 && x%2==0)   // if the flight is arrival type
    {

        new->next = NULL;
        if (list == NULL)
            list = new;
        else
        {
            new->next = list;
            list = new;
        }
    }
    else if(x>9999 && x<100000 && x%2!=0)  // // if the flight is a departure type
    {
        new->next = NULL;
        if (list == NULL)
        list = new;
        else
        {
            while (temp->next != NULL)
	        temp = temp->next;
            temp->next = new;
        }
    }
    else            // if there no flight i.e. if the runway is idle
    {

        new->next = NULL;
        if (list == NULL)
        list = new;
        else
        {
            temp = list;
            while (temp->next != NULL)
	        temp = temp->next;
            temp->next = new;
        }
    }
    return list;
}



void delay(int number_of_seconds)    // gives some time delay
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}


n *frontdel (n *list) // front deletion takes place
{
  n* temp;
  if (list == NULL)
    {
      printf (" empty \n");
    }
  else
    {
      temp = list;
      list = temp->next;
      free (temp);
    }
return list;
}

n* print(struct node *list)
{
    int i=0;
    n* temp;
    temp = list;
    if(list!=NULL)
    {
        while (temp != NULL )
        {
            if(temp->num>9999) printf ("%d. %c%d \n", ++i, temp->name,temp->num);
            temp = temp->next;
        }
    }
}
