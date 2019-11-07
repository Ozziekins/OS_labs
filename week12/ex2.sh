gcc ex2.c -o ex2_c
cat /proc/cpuinfo | ./ex2_c ex2.txt
rm ex2_c