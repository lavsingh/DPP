unsigned int cutoff = 1;
 
int intcmp(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}
 
void myswap(void *e1, void *e2, int size) {
    void* sp = (void*) malloc(size);
    memcpy(sp, e1, size);
    memcpy(e1, e2, size);
    memcpy(e2, sp, size);
    free(sp);
}
 
void insersionSort(void* base, size_t n, size_t size, int (*cmp)(const void*, const void*)) {
   int i, j;
   void *tmp = (void*)malloc(size);
   for (i = 1; i < n; ++i) {
       memcpy(tmp, base + i*size, size);
       for (j = i-1; j >= 0 && cmp(tmp, base+j*size) < 0; --j) {
           memcpy(base+(j+1)*size, base+j*size, size);
       }
       memcpy(base+(j+1)*size, tmp, size);
   } 
}
 
void myqsort4(void* base, size_t n, size_t size, int (*cmp)(const void*, const void*)) {
    int i, j;
    int ipos;
    if (n <= cutoff) {return;}
    ipos = rand()%n;
    myswap(base, base+ipos*size, size);
   // printf("sort %d elements\n", n);
    i = 0; j = n;
    while (1) {
        do {
            ++i;
        } while(cmp(base + size*i, base) < 0 && i < n);
        do {
            --j;
        } while(cmp(base + size*j, base) > 0);   //no need to check j >= 0 because it will fail test when it reaches base
        if (i > j) break;
        myswap(base + size*i, base + size*j, size);
        //printf("%d:%d\n", *(int*)(base+size*i), *(int*)(base+size*j));
    }
    //swap the base element with the j element
    if (j != 0) {
        myswap(base, base+size*j, size);
    }
    if (j > 0) {
        myqsort4(base, j, size, cmp);
    }
    myqsort4(base + size*(j+1), n - 1 - j, size, cmp);
}
 
int main(int argc, char **argv) {
    int* testArray;
    int i;
    int n = atoi(argv[1]);
    cutoff = atoi(argv[2]);
    struct timeval stTime, edTime;
    testArray = (int*) malloc(n*sizeof(int));
    srand(time(NULL));
    for (i = 0; i < n; ++i) {
        testArray[i] = rand()%1000; 
    }
    /*printf("before sort:\n");
    for (i = 0; i < n; ++i) {
        printf("%d ", testArray[i]);
    }
    printf("\n");*/
 
    gettimeofday(&stTime, NULL);
    myqsort4(testArray, n, sizeof(int), &intcmp);
 
    /*printf("after sort 1:\n");
    for (i = 0; i < n; ++i) {
        printf("%d ", testArray[i]);
    }
    printf("\n");*/
 
    insersionSort(testArray, n, sizeof(int), &intcmp);
    gettimeofday(&edTime, NULL);
    printf("%d: %u:%u\n", n, (unsigned int)(edTime.tv_sec - stTime.tv_sec), (unsigned int)(edTime.tv_usec - stTime.tv_usec));
 
    /*printf("after sort:\n");
    for (i = 0; i < n; ++i) {
        printf("%d ", testArray[i]);
    }
    printf("\n");*/
 
    free(testArray);
    return 0;
}
