//Dot product of two vectors

#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc , char* argv[])
{
    int rank , size;
    double a[100] , b[100];
    double mysum , allsum;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    if( rank == 0 )
        printf("Starting omp_dotprod with %d tasks",size);

    for(int i = 0; i < 100; i++ )
	{
        a[i] = 1.0;
        b[i] = a[i];
    }
    
    mysum = 0.0;
    
	for(int j = 0; j < 100; j++ )
        mysum += a[j] * b[j];

    printf("Task %d partial sum is %f",rank,mysum);
    MPI_Reduce(&mysum,&allsum,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);

    if(rank == 0)
        printf("Completed process : global sum is %f",allsum);
    
    MPI_Finalize();
    
}
