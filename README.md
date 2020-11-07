# Dot Product of 2 Vectors using OpenMPI | Multiprocessing | Parallel Computing

MPI code for computing the dot product of vectors on p processors using block-striped partitioning for uniform data distribution. <p>
Assuming that the vectors are of size n and p is number of processors used and n is a multiple of p.

>Algebraically, the dot product is the sum of the products of the corresponding entries of the two sequences of numbers.

Let **vector A** be
>[ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 ] 

Let **vector B** be
>[ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 ]

**Output:**
>[ 1.0 + 4.0 + 9.0 + 16.0 + 25.0 + 36.0 + 49.0 + 64.0 ] = 204.0

<h4> Partition Approach </h4>

![alt approach](https://github.com/Amagnum/Dot-Product-of-2-vectors-MPI/blob/main/img/approach.png?raw=true)

<hr>

Compile & run the code:
```
$ mpic++ main.cpp -o exc
$ mpirun -np 4 exc
```
