# Dot Product of 2 Vectors using OpenMPI | Multiprocessing | Parallel Computing

Computing the vector-vector multiplication on p processors of PARAM 10000 using block-striped partitioning for uniform data distribution. <p>
Assuming that the vectors are of size n and p is number of processors used and n is a multiple of p.

>Algebraically, the dot product is the sum of the products of the corresponding entries of the two sequences of numbers.
<br>
A sample input file for the vector A is given below <p>
n=8 <p>
[ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 ] <p><br>

A sample input file for the vector B is given below <p>
n=8 <p>
[ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 ]
<p><br>
Output <p>
[ 1.0 + 4.0 + 9.0 + 16.0 + 25.0 + 36.0 + 49.0 + 64.0 ] = 204.0
