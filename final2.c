#include<stdio.h>
int n=3,m=5;
int u=0;
int i,j;
int time[3][5]={3,8,7,5,2,3,4,2,1,5,5,8,10,7,6};   //input matrix

int ptime[3][5]={3,8,7,5,2,3,4,2,1,5,5,8,10,7,6};

int active[10][10];
int final[10];
//int p[20][20]= {7,5,3,8,2,11,8,12,5,1};
int tmax; // maximum time among all jobs
int schedule[10][10];
void display();


void FindSchedule(){
	int i,j,k=0,c=0;
	int out=1;
	for (i=0;i<n;i++){
		for(j=0;j<2*m;j++){
			if (out){    // Display TIME IN
				schedule[i][j] = c;
				c += ptime[i][final[k]];
				k++;
				out = 0;
			}
			else{         // Display TIME IN
				schedule[i][j] = c;
					if (i>0){     
					if(schedule[i][j]<schedule[i-1][j+2]){   //If previous machine is Busy
						c = schedule[i-1][j+2];
						schedule[i][j+1] = c;
					}
				}
				out = 1;
			}
		}
		k=0,c=schedule[i][1],out=1;
	}		
}

void PrintSchedule(){
	int i,j,out=1,k=0;
	
	printf("****** Total Elapsed Time for the job sequence ******\n\n");
	for (i=0;i<n;i++){
		printf("MACHINE %d\tTime In\tTime Out\n",i+1);
		for(j=0;j<2*m;j++){
			if (out){
				printf("Sequence %d :-> \t%d  \t",final[k]+1,schedule[i][j]);
				k++;
				out = 0;
			}
			else{
				printf("%d \t\n",schedule[i][j]);
				out = 1;
			}
			
		}
		k=0;
		printf("\n\n");
	}
		printf("Total Makespan Time: %d UNITS\n\n",schedule[i-1][j-1]);	
}
//find the job with comination of setep 1 and step 2
int step3()
{   
	int seq;
    int i,j;
    int a=tmax;
    for(i=0; i<n; i++)
    {
      for(j=0;j<m;j++)
      {
         if(active[i][j]==2)  //to check 2 in array
         {
		 if(time[i][j]<a) // ek se jada 2 ho to
            {
		//	k--;
			seq=j;
					    a=time[i][j];
            printf("\n");
            printf("%d   SEQ ",seq);
            printf("\n");
		//	k++;
            }
	     }
	  }
	}final[u]=seq;
            u++;

    for(i=0;i<n;i++)
    {
		time[i][seq]=9999;
    }

 for(i=0;i<m;i++)
    {
		if(time[0][i]==9999)
			{
continue;
			}
        else
			{
		display();
			}
    }
	
return 0;
}

//find maximum value of time
void max()
{
tmax = time[0][0];
 int c,d;
   for( c = 0 ; c < n ; c++ )
   {
      for( d = 0 ; d < m ; d++ )
      {
         if ( time[c][d] > tmax )
           {
		   	tmax = time[c][d];
			} 
	 }
   }
   printf("\t%d Tmax     ", tmax);
step3();
}

//check machines for each job
void step2()
{   int i,j;
    for(i=0; i<m; i++)
        {
            int location=0;
            int minimum = time[0][i];
            for(j=0;j<n;j++)
            {
                if ( time[j][i] < minimum )
                {
                    minimum = time[j][i];
                    location = j;
                }
            }
            active[location][i]= active[location][i]+1;
        }
    max();
}

//check jobs for each machine
void step1()
{   int i,j;
    for(i=0; i<n; i++)
        {
            int location=0;
            int minimum = time[i][0];
            for(j=0;j<m;j++)
            {
                if ( time[i][j] < minimum )
                {
                    minimum = time[i][j];
                    location = j;
                }
            }
            active[i][location]=1;
        }
    step2();
}

//display arrays
void display()
{
   int i,j;
    printf("TIME elements:\n");
    for(i=0; i<n; i++)
    {
      for(j=0;j<m;j++)
      {
         printf("%d ", time[i][j]);
         if(j==(m-1))
         {
            printf("\n");
         }
      }
    }
    printf("Active elements:\n");
    for(i=0; i<n; i++)
    {
      for(j=0;j<m;j++)
      {
         printf("%d ", active[i][j]);
         if(j==(m-1))
         {
            printf("\n");
         }
      }
    }
    
    for(i=0; i<n; i++)
    {
      for(j=0;j<m;j++)
      {
         active[i][j]=0;
      }
    }
    step1();
}

//get processing time values
void get_time()
{
    int i, j;
    for(i=0; i<n; i++)
    {
      for(j=0;j<m;j++)
      {
         //printf("Enter time for machine[%d] and Job[%d]:", i+1, j+1);
         //scanf("%d", &time[i][j]);
         
         active[i][j]=0;
      }
    }
    
}
void DisplaySequence(){  
for(i=0;i<m;i++) {
	printf("%d -> ", final[i]+1);

}
	printf("End\n");
}
int main()
{   int i,j;/*
         printf("Enter number of Machines:");
         scanf("%d", &n);
         printf("Enter number of Jobs:");
         scanf("%d", &m);*/
    get_time();
    display();
    DisplaySequence();

printf("\n\n\n");
FindSchedule();
PrintSchedule();
    return 0;
    
}

