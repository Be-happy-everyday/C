#include <mpi.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#ifndef MPI5

#define MIN(a, b) ((a)<(b)?(a):(b))

int main(int argc, char* argv[]) {
    int count;              /* Local prime count */
    double elapsed_time;    /* Parallel execution time */
    long long first;              /* Index of first multiple */
    int global_count;       /* Global prime count */
    char* marked;           /* Portion of 2,...,'n' */
    int id;                 /* Process ID number */
    long long index;              /* Index of current prime */
    long long low_index;          /* Lowest index on this proc */
    long long low_value;          /* Lowest value on this proc */
    long long high_index;         /* Highest index on this proc */
    long long high_value;         /* Highest value on this proc */
    long long n;                  /* Sieving from 2, ..., 'n' */
    int p;                  /* Number of processes */
    long long proc0_size;         /* Size of proc 0's subarray */
    long long prime;              /* Current prime */
    long long size;               /* Elements in 'marked' */
    char* sub_marked;       /* sub_mark array */
    long long sub_low_index;      /* Lowest index on sub_array */
    long long sub_low_value;      /* Lowest array on sub_array */
    long long sub_high_index;     /* Highest index on sub_array */
    long long sub_high_value;     /* Highest index on sub_array */

    // ��ʼ��
    // MPI��������ʱ���Զ�����������ͨ������
    // MPI_COMM_WORLD:��������������MPI����
    // MPI_COMM_SELF���е������̶��Թ��ɣ��������Լ�
    MPI_Init(&argc, &argv);

    // MPI_COMM_RANK �õ������̵Ľ��̺ţ����̺�ȡֵ��ΧΪ 0, ��, np-1
    MPI_Comm_rank(MPI_COMM_WORLD, &id);

    // MPI_COMM_SIZE �õ����вμ�����Ľ��̵ĸ���
    MPI_Comm_size(MPI_COMM_WORLD, &p);

    // MPI_Barrier��MPI�е�һ�������ӿ�
    // ��ʾ��ֹ����ֱ��communicator�����н�����ɵ���
    MPI_Barrier(MPI_COMM_WORLD);

    // MPI_WTIME����һ���ø�������ʾ������
    // ����ʾ�ӹ�ȥĳһʱ�̵�����ʱ����������ʱ��

    elapsed_time = -MPI_Wtime();

    // ��������Ϊ2���ļ����Լ������ģn
    if (argc != 3) {
        if (!id) printf("Command line: %s <m> \n", argv[0]);
        // ����MPIϵͳ
        MPI_Finalize();
        exit(1);
    }

    // ��ʾ�� <= n������
    n = atoll(argv[1]);


    // Bail out if all the primes used for sieving are not all held by process 0
    proc0_size = (n - 1) / p;

    // �����̫�����
    if ((2 + proc0_size) < (long long)sqrt((double)n)) {
        if (!id) printf("Too many processes \n");
        MPI_Finalize();
        exit(1);
    }

    /*
     * ����ǰsqrt(n)�ڵ�����
     * С����
     */
    int sub_n = (int)sqrt((double)n);
    int sub_N = (sub_n - 1) / 2;

    sub_low_index = 0 * (sub_N / p) + MIN(0, sub_N % p); // ���̵ĵ�һ����������
    sub_high_index = 1 * (sub_N / p) + MIN(1, sub_N % p) - 1; // ���̵����һ����������
    sub_low_value = sub_low_index * 2 + 3; //���̵ĵ�һ����
    sub_high_value = (sub_high_index + 1) * 2 + 1;//���̵����һ����

    sub_marked = (char*)malloc(sub_n);
    if (sub_marked == NULL) {
        printf("Cannot allocate enough memory \n");
        MPI_Finalize();
        exit(1);
    }

    // �ȼٶ����е�������������
    for (int i = 0; i < sub_n; i++) sub_marked[i] = 0;

    // ������ʼ��Ϊ0
    index = 0;

    prime = 3;
    do {
        // ��С���鿪ʼ��ֻ�����е�һ������
        first = (prime * prime - sub_low_value) / 2;
        // �ӵ�һ��������ʼ����Ǹ������ı���Ϊ������
        for (int i = first; i < sub_n; i += prime) {
            sub_marked[i] = 1;

        }
        while (sub_marked[++index]);
        prime = index * 2 + 3; // ��ʼ��ƫ��
    } while (prime * prime <= sub_n);


    /*
     * ������
     */
    long long N = (n - 1) / 2;
    low_index = id * (N / p) + MIN(id, N % p); // ���̵ĵ�һ����������
    high_index = (id + 1) * (N / p) + MIN(id + 1, N % p) - 1; // ���̵����һ����������
    low_value = low_index * 2 + 3; //���̵ĵ�һ����
    high_value = (high_index + 1) * 2 + 1;//���̵����һ����
    size = (high_value - low_value) / 2 + 1;    //���̴���������С

    long long CACHE_size = atoi(argv[2]);         //��ȡcache��С

    int CACHE_int = CACHE_size / 8;         //����ɷ����int����

    int Block_size = CACHE_int / p;         //����ֿ��С
    int Block_num = size / Block_size;      //����ֿ�����
    int Block_remain = size % Block_size;   //�����޷������Ĳ���

    long long Block_id = 0;
    long long Block_N = Block_size - 1;
    long long Block_low_index = Block_id * Block_N + MIN(Block_id, Block_remain) + low_index;
    long long Block_high_index = (Block_id + 1) * Block_N + MIN(Block_id + 1, Block_remain) - 1 + low_index;
    long long Block_low_value = Block_low_index * 2 + 3;
    long long Block_high_value = (Block_high_index + 1) * 2 + 1;
    int Block_count;

    // allocate this process 's share of the array
    marked = (char*)malloc(Block_size);
    if (marked == NULL) {
        printf("Cannot allocate enough memory \n");
        MPI_Finalize();
        exit(1);
    }


    // �ܼ���
    count = 0;

    while (Block_id <= Block_num) {

        // ������ʼ��Ϊ0
        index = 0;

        // ��3��ʼ��Ѱ��firstΪ��һ������������λ��
        prime = 3;

        // �����
        Block_count = 0;

        // �ȼٶ����е�������������
        for (int i = 0; i < Block_size; i++) marked[i] = 0;

        // �ڿ���������
        do {
            /*ȷ���ý����������ĵ�һ���������±� */
            // ���������n*n>low_value��n*(n-i)���������
            // ��n*nΪ�ý����еĵ�һ������
            // ���±�Ϊn*n-low_value���������������С�������Գ���2
            if (prime * prime > Block_low_value) {
                first = (prime * prime - Block_low_value) / 2;
            }
            else {
                // ����Сֵlow_valueΪ�������ı���
                // ���һ������Ϊlow_value�������±�Ϊ0
                if (!(Block_low_value % prime)) first = 0;
                // ����Сֵlow_value���Ǹ������ı���
                // ����������Ϊż������ô��һ��������������Ϊ��������ȥ�������2
                else if (Block_low_value % prime % 2 == 0) first = prime - ((Block_low_value % prime) / 2);
                // ����Сֵlow_value���Ǹ������ı���
                // ��ô��һ���������±�Ϊ��������ȥ������ֵ���������������С�������Գ���2
                else first = (prime - (Block_low_value % prime)) / 2;
            }

            // �ӵ�һ��������ʼ����Ǹ������ı���Ϊ������
            for (int i = first; i < Block_size; i += prime) {
                marked[i] = 1;
            }

            // �����ҵ���һ������λ��
            while (sub_marked[++index]);

            prime = index * 2 + 3; // ��ʼ��ƫ��

        } while (prime * prime <= Block_high_value);

        // ͳ�ƿ��ڼ���
        for (int i = 0; i < Block_size; i++) {
            if (marked[i] == 0) {
                Block_count++;
            }
        }

        // �����������
        count += Block_count;


        // ������һ����
        Block_id++;
        Block_low_index = Block_id * Block_N + MIN(Block_id, Block_remain) + low_index;
        Block_high_index = (Block_id + 1) * Block_N + MIN(Block_id + 1, Block_remain) - 1 + low_index;
        Block_low_value = Block_low_index * 2 + 3;
        if (Block_id == Block_num) {
            Block_high_value = high_value;
            Block_high_index = high_index;
            Block_size = (Block_high_value - Block_low_value) / 2 + 1;
        }
        else {
            Block_high_value = (Block_high_index + 1) * 2 + 1;
        }

    }

    MPI_Reduce(&count, &global_count, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // stop the timer
    elapsed_time += MPI_Wtime();
    MPI_Finalize();
    // print the results
    if (!id) {
        printf("%d primes are less than or equal to %lld \n", global_count + 1, n);
        printf("SIEVE (%d) %10.6f\n", p, elapsed_time);
    }
    return 0;
}

#endif