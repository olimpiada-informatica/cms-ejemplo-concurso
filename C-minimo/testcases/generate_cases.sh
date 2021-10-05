g++ generator_random.cpp -o rand
g++ generator_onemin.cpp -o onem
g++ generator_onemin_someswaps.cpp -o onems

./rand 2 7 1 > s1_rand1.inp
./onem 2 7 2 > s1_onem1.inp
./onems 2 7 1 3 > s1_onems1.inp
./rand 40 50 4 > s2_rand1.inp
./onem 40 50 5 > s2_onem1.inp
./onems 40 50 1 6 > s2_onems1.inp
./rand 100 100 7 > s3_rand1.inp
./onem 100 100 8 > s3_onem1.inp
./onem 100 100 9 > s3_onem2.inp
./onem 100 100 10 > s3_onem3.inp
./onem 100 100 30 > s3_onem4.inp
./onem 100 100 31 > s3_onem5.inp
./onem 100 100 32 > s3_onem6.inp
./onems 100 100 2 11 > s3_onems1.inp
./rand 100000 1000000 12 > s4_rand1.inp
./rand 100000 1000000 13 > s4_rand2.inp
./onem 100000 1000000 14 > s4_onem1.inp
./onem 100000 1000000 15 > s4_onem2.inp
./onem 100000 1000000 16 > s4_onem3.inp
./onem 1000000 1000000 17 > s4_onem4.inp
./onem 1000000 1000000 18 > s4_onem5.inp
./onems 100000 1000000 1 19 > s4_onems1.inp
./onems 100000 1000000 10 20 > s4_onems2.inp
./onems 100000 1000000 100 21 > s4_onems3.inp
./onems 100000 1000000 1000 22 > s4_onems4.inp
./onems 100000 1000000 10000 23 > s4_onems5.inp
