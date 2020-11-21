/*
*  
* Adarsh Baghel
* 
*/

#include <mpi.h>
#include <bits/stdc++.h>
using namespace std;

double *createMatrix(int n,int m){
    double *matrix;
    matrix = new double[n*m];

    for (int h=0; h<n*m; h++)
        matrix[h] = h+1;
    
    return matrix;
}


int main(int argc, char *argv[])
{
	int pid, nProc;
	double mytime, maxtime, mintime, avgtime;
	
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &nProc);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);
    
    double dotProduct;
    int n;
    double *a,*b;

    if(pid==0){
    	cin>>n;
        if(true){
           a = createMatrix(n,n);
           b = createMatrix(n,n);
        }
        else{
    	a = new double [n];
    	b = new double [n];
    	for(int i=0; i<n; i++)
    		cin>>a[i];
    	for(int i=0; i<n; i++)
    		cin>>b[i];
        }
    }

    MPI_Bcast(&n, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    mytime = MPI_Wtime(); /*get time just before work section */
    //#####################################
    
    double va[n/nProc]; 
    double vb[n/nProc];
    double sum=0;

	MPI_Scatter(a, n/nProc, MPI_DOUBLE, va, n/nProc, MPI_DOUBLE, 0, MPI_COMM_WORLD);
	MPI_Scatter(b, n/nProc, MPI_DOUBLE, vb, n/nProc, MPI_DOUBLE, 0, MPI_COMM_WORLD);

	for(int i=0; i<n/nProc; i++){
		sum+=va[i]*vb[i];
	}

	MPI_Reduce(&sum, &dotProduct, 1, MPI_DOUBLE, MPI_SUM, 0,MPI_COMM_WORLD);

    

	//#####################################
    mytime = MPI_Wtime() - mytime; /*get time just after work section*/
    if (pid == 0) {
        printf("Dot Product: %lf\n", dotProduct);
    }

    MPI_Reduce(&mytime, &maxtime, 1, MPI_DOUBLE,MPI_MAX, 0, MPI_COMM_WORLD);
	MPI_Reduce(&mytime, &mintime, 1, MPI_DOUBLE, MPI_MIN, 0,MPI_COMM_WORLD);
	MPI_Reduce(&mytime, &avgtime, 1, MPI_DOUBLE, MPI_SUM, 0,MPI_COMM_WORLD);
	MPI_Barrier(MPI_COMM_WORLD);
	
    if (pid == 0){
  		avgtime /= nProc;
		printf("Min: %lf Max: %lf Avg: %lf\n", mintime, maxtime, avgtime);
    }

    MPI_Finalize();
	return 0;
}