g++ random_generator.cpp -o generator

./generator 2 2 4 4 0 1 > sample1.inp
./generator 3 3 3 3 0 2 > sample2.inp
./generator 4 4 6 6 0 3 > sample3.inp
./generator 2 2 2 2 0 4 > small_y1.inp
./generator 6 6 2 2 0 5 > small_y2.inp
./generator 4 4 4 4 0 6 > small_y3.inp
./generator 5 5 5 5 0 7 > small_n1.inp
./generator 4 4 3 3 0 8 > small_n2.inp
./generator 1 1 3 3 0 9 > small_n3.inp
./generator 1 20 1 20 1 10 > med1.inp
./generator 1 20 1 20 1 11 > med2.inp
./generator 1 20 1 20 1 12 > med3.inp
./generator 1 20 1 20 0 13 > med4.inp
./generator 1 20 1 20 0 14 > med5.inp
./generator 1 1000 1 1000 1 15 > large1.inp
./generator 1 1000 1 1000 1 16 > large2.inp
./generator 1 1000 1 1000 1 17 > large3.inp
./generator 1 1000 1 1000 0 18 > large4.inp
./generator 1 1000 1 1000 0 19 > large5.inp
./generator 2 2 1 1000 0 20 > neq2_1.inp
./generator 2 2 1 1000 0 21 > neq2_2.inp
./generator 2 2 1 1000 0 22 > neq2_3.inp
./generator 2 2 1 1000 0 23 > neq2_4.inp
./generator 2 2 1 1000 0 24 > neq2_5.inp
./generator 6 6 6 6 0 25 > neqm_1.inp
./generator 20 20 20 20 0 26 > neqm_2.inp
./generator 1000 1000 1000 1000 0 27 > neqm_3.inp
./generator 999 999 999 999 0 28 > neqm_4.inp
./generator 784 784 784 784 0 29 > neqm_5.inp



rm generator
