// CODE BY SANIDHYA DASH - CSE316 - OS PROJECT
#include<stdio.h>
int main()
{
	char ch;
	int n,i,j,ptr,c,z,sum=0,avgtime;
	int arrivaltime[10],bursttime[10],waitingtime[10],priority[10],pn[10],tatime[10];
	

	
	printf("Enter the the no. of processes : ");
	scanf("%03d",&n);


	
	for (i=0;i<n;i++)
	{
		
		printf("\n\nprocess [%03d] \n",i+1);
		printf("Enter arrival time : ");
		scanf("%03d ",&arrivaltime[i]);
		
        
        printf("Enter Burst time : ");
        fflush(stdin);
		scanf("%03d ",&bursttime[i]);
		printf("Enter Priority : ");
		fflush(stdin);
		scanf("%03d ",&priority[i]);
		pn[i]=i+1;
		

	}
	
	for (i=0;i<n;i++)
	{
		ptr=i;
		
		for (j=i+1;j<n;j++)
		{
			if(priority[j]<priority[ptr])
			{
				ptr=j;
			}
		}
		
		c=priority[i];
		priority[i]=priority[ptr];
		priority[ptr]=c;
		
		c=bursttime[i];
		bursttime[i]=bursttime[ptr];
		bursttime[ptr]=c;
		
		c=pn[i];
		pn[i]=pn[ptr];
		pn[ptr]=c;
		
	}
	    waitingtime[0]=0;  
	      for(i=1;i<n;i++)
	      {
	      	waitingtime[i]=0;
	      	for(j=0;j<i;j++)
	      	{
	      		waitingtime[i] = waitingtime[i]+bursttime[j];
			}
            
			z = z+waitingtime[i];
			
		  }
	
	
	avgtime=z/n;
	fflush(stdin);
    	printf("|  PROCESS   |  ARRAIVAL TIME  |  BURST TIME  |  WAITING TIME  |  PRIORITY  |  TURN AROUND TIME  | \n");
	
	for (i=0;i<n;i++)
	{
		tatime[i]=bursttime[i]+waitingtime[i];
		printf("|    %03d     |        %03d      |      %03d     |    %03d     |     %03d    |         %03d        | \n",pn[i],arrivaltime[i],bursttime[i],waitingtime,pn[i],tatime[i]);
		sum= sum+tatime[i];
		
	}


	
	int avgtatime= sum/n;
	
	printf("\n|  AVERAGE WAIT TIME        : %03d  |",avgtime);
	printf("\n|  AVERAGE TURNAROUND TIME  : %03d  |",avgtatime);


}

