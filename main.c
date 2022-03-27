#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"server.h"
int main()
{
    n *list,*temp;
    int x,z=0,g,l,m,n=0,o=0,p=0,Alower=65,Aupper=90,Nlower=1,Nupper=100000;
    list=NULL;
    printf("\n Input data : \n How many number planes should the simulation run :  ");
    scanf("%d",&m);
    srand (time (0));
	for(g=m;g>0;g--)
	{
			l= (rand () % (Nupper - Nlower + 1)) + Nlower;   // the random number here gives the numerical part of the flight serial number
			x= (rand () % (Aupper - Alower + 1)) + Alower;  // the random number here gives the alphabetical part of the flight serial number
			if(l>9999 && l<100000)
				{
				    if(l%2==0)
				    {
                        list=queue(list,l,x);
                        n++;
				    }
				    else
				    {
				        list=queue(list,l,x);
				        o++;
				    }
        		}
        	else
        	{
				    list=queue(list,l,x);
				    p++;
        	}
    }
    printf (" The flights in queue : \n");
    print(list);
    for(g=m-2;g>0;g--)
    list=LANDorTAKEOFF(list,n,o);
    printf(" \n total arrivals : %d \n total depratures : %d \n total number of idles : %d \n",n,o,p);
}
