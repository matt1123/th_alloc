#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#define FILL_FREE 0xef

int main() {

 


// ******************
// *  Ex 1 tests    *
// *    malloc      *
// ******************

  printf("%s\n","\n========== EXERCISE 1 TESTS ==========");
  // Test 1: 
  // malloc multiple sizes of memory
  printf("%s\n","*** TEST 1: allocating multiple sizes of memory ***");

  void *mem1;
  void *mem2;
  void *mem3;
  void *mem4;

  mem1 = malloc(5);
  printf("%s","mem1: ");
  printf("%p\n", mem1);
  mem2 = malloc(35);
  printf("%s","mem2: ");
  printf("%p\n", mem2);
  mem3 = malloc(150);
  printf("%s","mem3: ");
  printf("%p\n", mem3);
  mem4 = malloc(2000);
  printf("%s","mem4: ");
  printf("%p\n", mem4);


  // Test 2: 
  // Fill multple blocks of same size
  printf("%s\n","\n*** TEST 2: allocating multiple blocks of same size in same superblock ***");
  mem1 = malloc(50);
  printf("%s","mem1: ");
  printf("%p\n", mem1);
  mem2 = malloc(50);
  printf("%s","mem2: ");
  printf("%p\n", mem2);
  mem3 = malloc(50);
  printf("%s","mem3: ");
  printf("%p\n", mem3);
  mem4 = malloc(50);
  printf("%s","mem4: ");
  printf("%p\n", mem4);

  // Test 3: 
  // Fill multiple superblocks
  printf("%s\n","\n*** TEST 3: filling multiple superblocks ***");
  
  int i;
 
  for(i=0; i<20; i++){
    printf("%i\n",i);
    printf("%s","mem1: ");
    mem1 = malloc(50);
    printf("%p\n", mem1);
    

    mem2 = malloc(120);
    printf("%s","mem2: ");
    printf("%p\n", mem2);

  }

  // Test 4: 
  // Allocate memory outside of bounds
  printf("%s\n","\n*** TEST 4: allocating memory outside of bounds ***");
  mem1 = malloc(10000000);
  printf("%s","mem1: ");
  printf("%p\n", mem1);
  mem2 = malloc(-500);
  printf("%s","mem2: ");
  printf("%p\n", mem2);

  // Test 5: 
  // Cast pointer, fill, and read allocated memory
  printf("%s\n","\n*** TEST 5: casting, filling, reading allocated memory ***");
  int *memFil1 = (int *)malloc(150);
  *memFil1 = 1;
  printf("%s", "memFil1 contents: ");
  printf("%x\n", *memFil1);
  int *memFil2 = (int *)malloc(100);
  *memFil2 = 2;
  printf("%s", "memFil2 contents: ");
  printf("%x\n", *memFil2);





// ******************
// *  Ex 2 tests    *
// *    free        *
// ******************
printf("%s\n","\n========== EXERCISE 2 TESTS ==========");
// Test 1:
// Free Allocated Memory
printf("%s\n","\n*** TEST 1: malloc, free, reallocate in same SB ***");
void *a1;
a1 = malloc(1000);
printf("%s","a1 before free: ");
printf("%p\n",a1);

free(a1);
printf("%s","a1 after free: ");
printf("%p\n",a1);


// Test 2:
// Allocate, free, and reallocate memory in same superblock
printf("%s\n","\n*** TEST 2: malloc, free, reallocate in same SB ***");

for(i=0;i<10;i++){
  a1 = malloc(50);
}
printf("%s", "allocated addr: ");
printf("%p\n",a1);
free(a1);

void *b1 = malloc(50);
printf("%s", "allocated addr after free: ");
printf("%p\n",b1);

void *c1 = malloc(50);
printf("%s", "allocated addr after free: ");
printf("%p\n",c1);

// Test 3:
// Allocate, free, and reallocate memory in multiple superblocks
printf("%s\n","\n*** TEST 3: malloc, free, reallocate in multiple SB ***");
void *mal6_1 = malloc(2000);
printf("%s","mal6_1: ");
printf("%p\n",mal6_1);

void *mal6_2 = malloc(2000);
printf("%s","mal6_2: ");
printf("%p\n",mal6_2);
free(mal6_1);

mal6_1 = malloc(2000);
printf("%s","mal6_1: ");
printf("%p\n",mal6_1);


// Test 4:
// Free memory that has already been freed
printf("%s\n","\n*** TEST 4: Free mem thats already been freed ***");
free(mal6_1);
printf("%s","mal6_1: ");
printf("%p,\n",mal6_1);
free(mal6_1);
printf("%s","mal6_1: ");
printf("%p,\n",mal6_1);


// Test 5:
// Allocate a lot of memory and free all of it
printf("%s\n","\n*** TEST 5: Allocate mucho memory and free all of it ***");
void *arr[100];
for(i=0;i<100;i++){
  arr[i] = malloc(100);
}
printf("%s","Pointer 15 before free: ");
printf("%p\n",arr[15]);

for(i=0;i<100;i++){
  free(arr[i]);
}
printf("%s","Pointer 15 after free:  ");
printf("%p\n",arr[15]);






// ******************
// *  Ex 3 tests    *
// *  poison vals   *
// ******************
printf("%s\n","\n========== EXERCISE 3 TESTS ==========");

// Test 1:
// Poisions on malloc()
  printf("%s","\n*** TEST 1: malloc poison ***\n ");
  int sz;
  sz = 120;
	void *x = malloc(sz);
  unsigned char *y = (unsigned char *)x;
  for(i=0; i<sz; i++){
  	printf("%x",y[i]);
  }
  printf("\n");


// Test 2:
// Poisons on free()
  printf("%s","\n*** TEST 2: free poison ***\n ");
  free(x);
  unsigned char *z = (unsigned char *)x;
  for(i=0; i<sz; i++){
  	printf("%x",z[i]);
  }
  printf("\n");






// // ******************
// // *  Ex 4 test     *
// // *  munmap page   *
// // ******************
printf("%s\n","\n========== EXERCISE 4 TESTS ==========");
// Test 1:
// fills and frees superblocks, but all pointers are kept
printf("%s\n","\n*** TEST 1: Attempt to read from memory that is not unmapped ***");

  int *a = (int *)malloc(50);
  printf("a: %p", a);
  *a = 1;
  printf("%s", ": ");
  printf("%x\n", *a);

  int *b = (int *)malloc(50);
  printf("b: %p", b);
  *b = 2;
  printf("%s", ": ");
  printf("%x\n", *b);

  int *c = (int *)malloc(50);
  printf("c: %p", c);
  *c = 3;
  printf("%s", ": ");
  printf("%x\n", *c);

  int *d = (int *)malloc(50);
  printf("d: %p", d);
  *d = 4;
  printf("%s", ": ");
  printf("%x\n", *d);

  int *e = (int *)malloc(50);
  printf("e: %p", e);
  *e = 5;
  printf("%s", ": ");
  printf("%x\n", *e);

  int *f = (int *)malloc(50);
  printf("f: %p", f);
  *f = 6;
  printf("%s", ": ");
  printf("%x\n", *f);

  int *g = (int *)malloc(50);
  printf("g: %p", g);
  *g = 7;
  printf("%s", ": ");
  printf("%x\n", *g);

  int *h = (int *)malloc(50);
  printf("h: %p", h);
  *h = 8;
  printf("%s", ": ");
  printf("%x\n", *h);

  int *j = (int *)malloc(50);
  printf("j: %p", j);
  *j = 9;
  printf("%s", ": ");
  printf("%x\n", *j);

  int *k = (int *)malloc(50);
  printf("k: %p", k);
  *k = 10;
  printf("%s", ": ");
  printf("%x\n", *k);

  int *l = (int *)malloc(50);
  printf("l: %p", l);
  *l = 11;
  printf("%s", ": ");
  printf("%x\n", *l);


  printf("%s\n","Freeing all: ");
  free(l);
  free(k);
  free(j);
  free(h);
  free(g);
  free(f);
  free(e);
  free(d);
  free(c);
  free(b);
  free(a);

  printf("%s\n","Contents of freed. Should NOT get segfault: ");
  printf("%s", "a: ");
  printf("%x\n",*a);

  printf("%s", "b: ");
  printf("%x\n",*b);

  printf("%s", "c: ");
  printf("%x\n",*c);

  printf("%s", "d: ");
  printf("%x\n",*d);

  printf("%s", "e: ");
  printf("%x\n",*e);

  printf("%s", "f: ");
  printf("%x\n",*f);

  printf("%s", "g: ");
  printf("%x\n",*g);

  printf("%s", "h: ");
  printf("%x\n",*h);

  printf("%s", "j: ");
  printf("%x\n",*j);

  printf("%s", "k: ");
  printf("%x\n",*k);

  printf("%s", "l: ");
  printf("%x\n",*l);

// Test 2: 
// fills and frees superblocks, but some pointer addresses are lost, 
// should result in segfault

  printf("%s\n","\n*** TEST 2: Attempt to read from memory that is unmapped ***");

	a = (int *)malloc(1000);
  printf("a: %p", a);
  *a = 1;
  printf("%s", ": ");
  printf("%x\n", *a);

  b = (int *)malloc(1000);
  printf("b: %p", b);
  *b = 2;
  printf("%s", ": ");
  printf("%x\n", *b);

 	c = (int *)malloc(1000);
 	printf("c: %p", c);
  *c = 3;
  printf("%s", ": ");
  printf("%x\n", *c);

  d = (int *)malloc(1000);
  printf("d: %p", d);
  *d = 4;
  printf("%s", ": ");
  printf("%x\n", *d);

  e = (int *)malloc(1000);
  printf("e: %p", e);
  *e = 5;
  printf("%s", ": ");
  printf("%x\n", *e);

  f = (int *)malloc(1000);
  printf("f: %p", f);
  *f = 6;
  printf("%s", ": ");
  printf("%x\n", *f);

  g = (int *)malloc(1000);
  printf("g: %p", g);
  *g = 7;
  printf("%s", ": ");
  printf("%x\n", *g);

  h = (int *)malloc(1000);
  printf("h: %p", h);
  *h = 8;
  printf("%s", ": ");
  printf("%x\n", *h);

  j = (int *)malloc(1000);
  printf("j: %p", j);
  *j = 9;
  printf("%s", ": ");
  printf("%x\n", *j);

  k = (int *)malloc(1000);
  printf("k: %p", k);
  *k = 10;
  printf("%s", ": ");
  printf("%x\n", *k);

  l = (int *)malloc(1000);
  printf("l: %p", l);
  *l = 11;
  printf("%s", ": ");
  printf("%x\n", *l);


  printf("%s\n","Freeing all: ");
  free(l);
  free(k);
  free(j);
  free(h);
  free(g);
  free(f);
  free(e);
  free(d);
  free(c);
  free(b);
  free(a);

  printf("%s\n","Contents of freed. Should get segfault after printing first 3: ");
  printf("%s", "a: ");
  printf("%x\n",*a);

  printf("%s", "b: ");
  printf("%x\n",*b);

  printf("%s", "c: ");
  printf("%x\n",*c);

  printf("%s", "d: ");
  printf("%x\n",*d);

  printf("%s", "e: ");
  printf("%x\n",*e);

  printf("%s", "f: ");
  printf("%x\n",*f);

  printf("%s", "g: ");
  printf("%x\n",*g);

  printf("%s", "h: ");
  printf("%x\n",*h);

  printf("%s", "j: ");
  printf("%x\n",*j);

  printf("%s", "k: ");
  printf("%x\n",*k);

  printf("%s", "l: ");
  printf("%x\n",*l);









 	return (errno);
}