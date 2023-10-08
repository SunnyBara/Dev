#include <unistd.h>
#include <stdio.h>
int initialisation(int tour1[], int tour2[], int tour3[], int n)
{
    int i = 0;
    while (i<n)
    {
	tour1[i]=n-i;
	tour2[i]=0;
	tour3[i]=0;
	i++;
    }
    return(0);
}
int selection(int tour[] ,int n)
{
    int i = 0; 
    while (tour[i+1] != 0 && i+1 < n)
    {
	i++;
    }
    return(i);
}
int transition(int tourdepart[], int depart, int tourarrive[], int arrive)
{
    tourarrive[arrive]=tourdepart[depart];
    tourdepart[depart]=0;
    return(0);
}
int mouvement3(int tour1[], int tour2[],int n)
{
    int t1=selection(tour1,n);
    int t2=selection(tour2,n);
    if (tour1[t1] != 0 && tour2[t2] == 0)
    {
	transition(tour1, t1, tour2, t2);
	write(STDOUT_FILENO,"1 => 2\n",7);
    }
    else if (tour1[t1] != 0 && tour1[t1] < tour2[t2])
    {
	transition(tour1, t1, tour2, t2+1);
	write(STDOUT_FILENO,"1 => 2\n",7);
    }
    else if (tour2[t2] != 0 && tour1[t1] == 0)
    {
	transition(tour2, t2, tour1, t1);
	write(STDOUT_FILENO,"2 => 1\n",7);
    }
    else if (tour2[t2] != 0 && tour2[t2] < tour1[t1])
    {
	transition(tour2, t2, tour1, t1+1);
	write(STDOUT_FILENO,"2 => 1\n",7);
    }
    return(0);   
}

int mouvement4(int tour1[], int tour3[],int n)
{
    int t1=selection(tour1,n);
    int t3=selection(tour3,n);    
    if (tour1[t1] != 0 && tour3[t3] == 0)
    {
	transition(tour1, t1, tour3, t3);
	write(STDOUT_FILENO,"1 => 3\n",7);
    }
    else if (tour1[t1] != 0 && tour1[t1] < tour3[t3])
    {
	transition(tour1, t1, tour3, t3+1);
	write(STDOUT_FILENO,"1 => 3\n",7);
    }
    else if (tour3[t3] != 0 && tour1[t1] == 0)
    {
	transition(tour3, t3, tour1, t1);
	write(STDOUT_FILENO,"3 => 1\n",7);
    }
    else if (tour3[t3] != 0 && tour3[t3] < tour1[t1])
    {
	transition(tour3, t3, tour1, t1+1);
	write(STDOUT_FILENO,"3 => 1\n",7);
    }
    return(0);
}
int mouvement5(int tour2[], int tour3[], int n)
{
    int t2=selection(tour2,n);
    int t3=selection(tour3,n); 
    if (tour2[t2] != 0 && tour3[t3] == 0)
    {
	transition(tour2, t2, tour3, t3);
	write(STDOUT_FILENO,"2 => 3\n",7);
    }
    else if (tour2[t2] != 0 && tour2[t2] < tour3[t3])
    {
	transition(tour2, t2, tour3, t3+1);
	write(STDOUT_FILENO,"2 => 3\n",7);
    }

    else if (tour3[t3] != 0 && tour2[t2] == 0)
    {
	transition(tour3, t3, tour2, t2);
	write(STDOUT_FILENO,"3 => 2\n",7);
    }
    else if (tour3[t3] != 0 && tour3[t3] < tour2[t2])
    {
	transition(tour3, t3, tour2, t2+1);
	write(STDOUT_FILENO,"3 => 2\n",7);
    }
}
void hanoi(int n)
{
    int tour1 [n];
    int tour2 [n];
    int tour3[n];
    int i = 0;
    initialisation(tour1, tour2, tour3, n);
    if (n%2 == 0)
    {
	while (tour3[n-1] != 1 && i < 16)
	{
	    mouvement3(tour1,tour2,n);
	    mouvement4(tour1,tour3,n);
	    mouvement5(tour2,tour3,n);
	}
    }
    else if (n%2 == 1)
    {
	while (tour3[n-1] != 1)
	{
	    mouvement4(tour1,tour3,n);
	    mouvement3(tour1,tour2,n);
	    mouvement5(tour2,tour3,n);
	}
    }
    return;
}

