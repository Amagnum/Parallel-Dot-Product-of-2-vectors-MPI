# Dot Product of 2 Vectors using MPI C++ | Multiprocessing | Parallel Computing

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

### Results:
![alt approach](https://github.com/Amagnum/Dot-Product-of-2-vectors-MPI/blob/main/img/Dot%20Product%20of%202%20Vectors.png)

### Compile & run the code:
```
$ mpic++ main.cpp -o exc
$ mpirun -np 4 exc
```

## REFERENCES
1. Chandresh Kumar Maurya, Assisant professor, IIT Indore [link](https://chandu8542.github.io/)
2. Advanced Message Passing in MPI, Using MPI Datatypes with Opaque C++ Types, Paul Preney [pdf link](https://www.sharcnet.ca/help/images/f/fa/MPI_Datatypes_with_Opaque_Types_seminar_2014.pdf)
