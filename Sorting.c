//Matteo Vicari
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE1 30
#define SIZE2 150
#define SIZE3 500
#define SIZE4 2000
#define SIZE5 10000


void IniziaRandom(int a[], int s)
{
    int i;
    for(i=0; i<=s; i++)
        a[i]=(rand()%9990)+10;
}

void IniziaRandom2(int a[], int s)
{
    int i;
    for(i=0; i<=s; i++)
        a[i]=(rand()%99)+1;
}

void Scambio(int a[], int s)
{
    int num1, num2, tmp;
    for(int j=0; j<5; j++){
        num1=rand()%s;
        num2=rand()%s;
        if(num1!=num2){
            tmp=a[num1];
            a[num1]=a[num2];
            a[num2]=tmp;
        }
        else
            j--;
    }
}

void StampaVettore(int a[], int s)
{
    int i;
    for(i=0; i<=s; i++)
        printf("%10d", a[i]);
}

void copiaVettore(int a[], int b[], int s)
{
    int i, k;
    k=0;
    for(i=0; i<=s; i++)
    {
        b[k]=a[i];
        k++;
    }
}

int bubbleSort(int a[], int s)
{
    int i,j,scambi, tmp, nc1;
    nc1=0;
    scambi=1;
    for(i=s-1; (i>0 && scambi==1); i--)
        {
            scambi=0;
            for (j=0; j<i ; j++){
                nc1++;
                if (a[j]>a[j+1])
                {
                    scambi=1;
                    tmp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=tmp;
                }}
        }
        return nc1;
}

int SelectionSort(int a[], int s)
{
    int i, j, min, tmp, nc2;
    nc2=0;
    for (i=0;i<s-1;i++)
        {
            int min=i;
            for (j=i+1;j<s;j++){
                nc2++;
                if (a[j]<a[min])
                    min=j;}
                tmp=a[min];
                a[min]=a[i];
                a[i]=tmp;
        }
    return nc2;
}

int InsertionSort(int a[], int s)
{
    int i, j, key, nc3;
    nc3=0;
    for (i=1; i<s; i++)
        {
            key=a[i];
            for (j=i-1; (j>=0 && a[j]>key); j--){
                nc3++;
                a[j+1]=a[j];}
            a[j+1]=key;
        }
    return nc3;
}

int maxVett(int v[], int h, int k)
{
    int max=h;
    for(int i=h+1; i<k; i++)
    {
        if(v[i]>v[max])
            max=i;
    }
    return max;
}

int InsertionSort2(int v[], int s)
{
    int max, tmp;
    for(int i=0; i<s; i++)
    {
        max=maxVett(v, i, s);
        tmp=v[i];
        v[i]=v[max];
        v[max]=tmp;
    }
}

int merge(int a[], int start, int center, int end, int size, int *m)
{
	int i, j, k;
	int app[size];

	i = start;
	j = center+1;
	k = 0;

	while ((i<=center) && (j<=end)) {
		if (a[i] <= a[j]) {
			app[k++] = a[i++];}
		else {
			app[k++] = a[j++];}
        (*m)++;
	}

	while (i<=center)
		app[k++] = a[i++];

	while (j<=end)
		app[k++] = a[j++];

	for (k=start; k<=end; k++)
		a[k] = app[k-start];
}

void iterativemergesort(int a[],int size, int *m)
{
	int sizetomerge=size-1;
	size--;
	int i;
	int n=2;

	while (n<sizetomerge*2) {
		for (i=0; (i+n-1)<=sizetomerge; i+=n) {
			merge(a,i,(i+i+n-1)/2,i+(n-1),sizetomerge, m);
		}

		i--;
		if ((sizetomerge+1)%n!=0) {
			if (size>sizetomerge)
				merge (a,sizetomerge -((sizetomerge)%n),sizetomerge,size,size, m);
			sizetomerge=sizetomerge-((sizetomerge+1)%n);}
		n=n*2;
	}

	if (size>sizetomerge)
		merge (a,0,size-(size-sizetomerge),size,size, m);
}

void quicksort(int a[],int primo,int ultimo, int* q)
{
   int i, j, pivot, temp;
   if(primo<ultimo){
      pivot=primo;
      i=primo;
      j=ultimo;

      while(i<j){
         while(a[i]<=a[pivot]&&i<ultimo)
            {i++;
             (*q)++;
            }
         while(a[j]>a[pivot])
            {j--;
             (*q)++;
            }
         if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
         }
      }

      temp=a[pivot];
      a[pivot]=a[j];
      a[j]=temp;
      quicksort(a,primo,j-1, q);
      quicksort(a,j+1,ultimo, q);
   }
}

void stampaTempo(clock_t mill)
{
    int sec,min;
    if (mill> 999){
        printf("\n\n\n .. o meglio...\n");
        sec=  mill/1000;
        if (sec < 59)
        printf("\n Tempo impiegato: %d secondi", sec);
        else{
            min=   sec/60;
            printf("\n Tempo impiegato: %d minuti", min);
        }
    }

printf("\n\n\n");

}

void Tab(int s, int bconf, int sconf, int iconf, int mconf, int qconf, int btime, int stime, int itime, int mtime, int qtime)
{
    printf("|%10d|%10d|%10d|%10d|%10d|%10d|%10d|%10d|%10d|%10d|%10d|\n", s, bconf, sconf, iconf, mconf, qconf, btime, stime, itime, mtime, qtime);
}

void process(int v[], int vc[], int s, int *m, int *q)
{
   int bconf, sconf, iconf, mconf, qconf;
   int btime, stime, itime, mtime, qtime;

   clock_t start,  fine;

   copiaVettore(v,vc,s);
   start = clock();
   bconf = bubbleSort(vc,s);
   fine = clock();
   btime = (fine - start)*1000/CLOCKS_PER_SEC;

   copiaVettore(v,vc,s);
   start = clock();
   sconf = SelectionSort(vc,s);
   fine = clock();
   stime = (fine - start)*1000/CLOCKS_PER_SEC;

   copiaVettore(v,vc,s);
   start = clock();
   iconf = InsertionSort(vc,s);
   fine = clock();
   itime = (fine - start)*1000/CLOCKS_PER_SEC;

   copiaVettore(v, vc, s);
   mconf = 0;
   start = clock();
   iterativemergesort(vc, s, &mconf);
   fine = clock();
   mtime = (fine - start)*1000/CLOCKS_PER_SEC;

   copiaVettore(v, vc, s);
   qconf = 0;
   start = clock();
   quicksort(vc, 0, s-1, &qconf);
   fine = clock();
   qtime = (fine - start)*1000/CLOCKS_PER_SEC;

   Tab(s, bconf, sconf, iconf, mconf, qconf, btime, stime, itime, mtime, qtime);
}

int main()
{
   int vett1[SIZE1], vett1c[SIZE1];
   int vett2[SIZE2], vett2c[SIZE2];
   int vett3[SIZE3], vett3c[SIZE3];
   int vett4[SIZE4], vett4c[SIZE4];
   int vett5[SIZE5], vett5c[SIZE5];

   int bconf, sconf, iconf, mconf, qconf;
   int btime, stime, itime, mtime, qtime;
   int *m, *q;

   clock_t start,  fine;

   IniziaRandom(vett1,SIZE1);
   IniziaRandom(vett2,SIZE2);
   IniziaRandom(vett3,SIZE3);
   IniziaRandom(vett4,SIZE4);
   IniziaRandom(vett5,SIZE5);

   printf("                                           TABELLA vettori da 1 a 10000\n--------------------------------------------------------------------------------------------------------------------------\n");
   printf("|    size  |   bconf  |   sconf  |   iconf  |   mconf  |   qconf  |   btime  |   stime  |   itime  |   mtime  |   qtime  |\n");
   printf("--------------------------------------------------------------------------------------------------------------------------\n");

   process(vett1, vett1c, SIZE1, m, q);
   process(vett2, vett2c, SIZE2, m, q);
   process(vett3, vett3c, SIZE3, m, q);
   process(vett4, vett4c, SIZE4, m, q);
   process(vett5, vett5c, SIZE5, m, q);


   printf("--------------------------------------------------------------------------------------------------------------------------\n\n");


   IniziaRandom2(vett1,SIZE1);
   IniziaRandom2(vett2,SIZE2);
   IniziaRandom2(vett3,SIZE3);
   IniziaRandom2(vett4,SIZE4);
   IniziaRandom2(vett5,SIZE5);


   printf("                                          TABELLA vettori da 1 a 100\n--------------------------------------------------------------------------------------------------------------------------\n");
   printf("|    size  |   bconf  |   sconf  |   iconf  |   mconf  |   qconf  |   btime  |   stime  |   itime  |   mtime  |   qtime  |\n");
   printf("--------------------------------------------------------------------------------------------------------------------------\n");

   process(vett1, vett1c, SIZE1, m, q);
   process(vett2, vett2c, SIZE2, m, q);
   process(vett3, vett3c, SIZE3, m, q);
   process(vett4, vett4c, SIZE4, m, q);
   process(vett5, vett5c, SIZE5, m, q);

   printf("--------------------------------------------------------------------------------------------------------------------------\n\n");


   IniziaRandom(vett1,SIZE1);
   InsertionSort(vett1, SIZE1);
   IniziaRandom(vett2,SIZE2);
   InsertionSort(vett2, SIZE2);
   IniziaRandom(vett3,SIZE3);
   InsertionSort(vett3, SIZE3);
   IniziaRandom(vett4,SIZE4);
   InsertionSort(vett4, SIZE4);
   IniziaRandom(vett5,SIZE5);
   InsertionSort(vett5, SIZE5);



      printf("                                    TABELLA vettori da 1 a 10000 preordinati\n--------------------------------------------------------------------------------------------------------------------------\n");
   printf("|    size  |   bconf  |   sconf  |   iconf  |   mconf  |   qconf  |   btime  |   stime  |   itime  |   mtime  |   qtime  |\n");
   printf("--------------------------------------------------------------------------------------------------------------------------\n");

   process(vett1, vett1c, SIZE1, m, q);
   process(vett2, vett2c, SIZE2, m, q);
   process(vett3, vett3c, SIZE3, m, q);
   process(vett4, vett4c, SIZE4, m, q);
   process(vett5, vett5c, SIZE5, m, q);


   printf("--------------------------------------------------------------------------------------------------------------------------\n\n");

   IniziaRandom(vett1,SIZE1);
   InsertionSort2(vett1, SIZE1);
   IniziaRandom(vett2,SIZE2);
   InsertionSort2(vett2, SIZE2);
   IniziaRandom(vett3,SIZE3);
   InsertionSort2(vett3, SIZE3);
   IniziaRandom(vett4,SIZE4);
   InsertionSort2(vett4, SIZE4);
   IniziaRandom(vett5,SIZE5);
   InsertionSort2(vett5, SIZE5);


   printf("                              TABELLA vettori da 1 a 10000 preordinati decrescente\n--------------------------------------------------------------------------------------------------------------------------\n");
   printf("|    size  |   bconf  |   sconf  |   iconf  |   mconf  |   qconf  |   btime  |   stime  |   itime  |   mtime  |   qtime  |\n");
   printf("--------------------------------------------------------------------------------------------------------------------------\n");

   process(vett1, vett1c, SIZE1, m, q);
   process(vett2, vett2c, SIZE2, m, q);
   process(vett3, vett3c, SIZE3, m, q);
   process(vett4, vett4c, SIZE4, m, q);
   process(vett5, vett5c, SIZE5, m, q);

   printf("--------------------------------------------------------------------------------------------------------------------------\n\n");

   IniziaRandom(vett1,SIZE1);
   InsertionSort(vett1, SIZE1);
   Scambio(vett1, SIZE1);
   IniziaRandom(vett2,SIZE2);
   InsertionSort(vett2, SIZE2);
   Scambio(vett2, SIZE2);
   IniziaRandom(vett3,SIZE3);
   InsertionSort(vett3, SIZE3);
   Scambio(vett3, SIZE3);
   IniziaRandom(vett4,SIZE4);
   InsertionSort(vett4, SIZE4);
   Scambio(vett4, SIZE4);
   IniziaRandom(vett5,SIZE5);
   InsertionSort(vett5, SIZE5);
   Scambio(vett5, SIZE5);

      printf("                              TABELLA vettori da 1 a 10000 preordinati e scambiati\n--------------------------------------------------------------------------------------------------------------------------\n");
   printf("|    size  |   bconf  |   sconf  |   iconf  |   mconf  |   qconf  |   btime  |   stime  |   itime  |   mtime  |   qtime  |\n");
   printf("--------------------------------------------------------------------------------------------------------------------------\n");

   process(vett1, vett1c, SIZE1, m, q);
   process(vett2, vett2c, SIZE2, m, q);
   process(vett3, vett3c, SIZE3, m, q);
   process(vett4, vett4c, SIZE4, m, q);
   process(vett5, vett5c, SIZE5, m, q);

   printf("--------------------------------------------------------------------------------------------------------------------------\n\n");

return(0);
}

