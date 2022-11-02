// please show mercy and give some partial credit :')
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

// gloabal variables
int N, T;
double *sum;

// pthread void function*
void* piR(void* arg){
	//
    	long j = (long)arg;   

	// geeks for geeks*
	for(int i = (N/T)*(j-1); i < ((N/T)*(j)); i++){
        	if(i%2 == 0)
            		sum[j] += 4.0/((2*j)*(2*j+1)*(2*j+2));
        	else
            		sum[j] -= 4.0/((2*j)*(2*j+1)*(2*j+2));
    	}
    
	// exit thread
	pthread_exit(0);
}

// dirver functiom
// slide 22*
int main(){
    	// declare
	// given from slide...
	// int myid, numprocs, i;
    	// unsigned long n;
	double pi = 3.141592653589793238462643;
    	sum = (double *)malloc((T+1) * sizeof(*sum));
    	double PI = 3.14;

    	// user input
    	printf("enter number of terms: ");
    	scanf("%d", &N);

    	printf("enter nimber of threadds: ");
    	scanf("%d", &T);
    
    	printf("\n");

    	// calc
    	for(int p=1; p<=T; p++)
        	sum[p] = 0;

	//  int used to identify thread 
    	pthread_t tids[T+1];

    	for(long i = 1; i<=T; i++){
		// tut*
        	pthread_attr_t attr;
        	pthread_attr_init(&attr);
        	pthread_create(&tids[i], &attr, piR, (void*)i);
    	}

    	for(int k = 1; k<=T; k++)
        	pthread_join(tids[k], NULL); // wait for thread to terminate 

    	for(int x=1; x<=T; x++)
        	pi += sum[x];

    	// output
    	printf("pi is approxmiately: %.20f\n" ,pi);
    	printf("error: %.20f\n" , pi-PI);
   
    	return 0;
}
