#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//prototipaçao das funçoes
long long int * alloca_vet(long long int size);
void booblesort(long long int *vet,long long int size); // pointer to lli vetctor && lli size return lli pointer to vector
void forprint(long long int *vet,long long int size);// pointer to lli vector && lli size
void insertionsort(long long int *vet, long long int size); // lli pointer to vector && lli size of vector
void quicksort(long long int * vet, long long int init, long long int end); // lli poiter to vecto && lli ini  sub lli end
void mergesort(long long int *vet, long long int init,long long int end); // lli *vet lli init lli end
void showtime(double *clk); // lli clocks

int main(){
	//contrucao de um menu
	long long int size=0,*vet=NULL;
	double clk = 0;
	int op;
	do{
		if(!size){
			printf("\n\ndefine a size: ");
			scanf("%lli", &size);
		}
		printf("\nvet size: %lli",size);
		printf("\n1.........booble");
		printf("\n2..........merge");
		printf("\n3..........quick");
		printf("\n4......insertion");
		printf("\n5.....reset size");
		printf("\n6...........show");
		printf("\n0...........exit");
		printf("\nchoose: ");scanf("%d",&op);
		switch(op){
			case 0:
				if(vet != NULL)
				free(vet);
				break;
			case 1:
				if(vet != NULL) {free(vet);}
				printf("\nallocating...\n");
				vet = alloca_vet(size);
				printf("organizing...\n");
				showtime(&clk);
				booblesort(vet,size);
				showtime(&clk);
				break;
			case 2:
				//mergesort(vet,0,end);
				break;
			case 3:
				if(vet != NULL) {free(vet);}
				printf("\nallocating");
				vet = alloca_vet(size);
				printf("\n\norganizing");
				showtime(&clk);
				quicksort(vet,0,size);
				showtime(&clk);
				break;
			case 4:
				if(vet != NULL) {free(vet);}                                                                                printf("\nallocating...\n");
				vet = alloca_vet(size);
				printf("\norganizing....");
				showtime(&clk);
				insertionsort(vet,size);
				showtime(&clk);
				break;
			case 5:
				size = 0;
				free(vet);
				vet=NULL;
				break;
			case 6:
				if(vet != NULL){
					printf("\n");
					showtime(&clk);
					forprint(vet,size);
					showtime(&clk);
				}else printf("\nSegmentation fault");
				break;
			default:
				printf("\nvalor invalido");
				break;
		}
	}while(op != 0);
	return 0;
}
/*

void mergesort(long long int *vet,long long int init, long long int end){
	long long int half = (init+end) /2,a;
	if(init<end){
		mergesort(vet,init,half);
		mergesort(vet,half+1,end);
	}
	merge(
}
*/
void quicksort(long long int *vet,long long int init,long long int end){
	long long int p = vet[(init + end) / 2],in = init, en = end,swap;
	while(in <= en){
		while(vet[in] < p && in < end) in++;
		while(vet[en] > p && en > init) en--;
		if(in <= en){
			swap = vet[in];
			vet[in] = vet[en];
			vet[en] = swap;
			in++;
			en--;
		}
	}
	if(in < end){ quicksort(vet,in,end);}
	if(en > init){ quicksort(vet,init,en);}
}

void booblesort(long long int * vet,long long int size){ //booble sort function
	long long int i=0,j,aux;
	int flag= 1;
	while(flag){
		flag = 0;
		for(j=0;j<size-i-1;j++){
			if(vet[j]>vet[j+1]){
				flag = 1;
				aux = vet[j];
				vet[j]=vet[j+1];
				vet[j+1]=aux;
			}
		}i++;
	}
}
long long int * alloca_vet(long long int size){
	long long int nrand,aux,i,* vet;
	vet = (long long int*)malloc(sizeof(long long int)*size);
	for(i=0;i<size;i++){
		vet[i]=i;
	}
	for(i=0;i<size;i++){
		nrand = rand()%size;
		aux=vet[nrand];
		vet[nrand]=vet[i];
		vet[i]=aux;
	}
	return vet;
}
void forprint(long long int *vet,long long int size){
	long long int i;
	for(i=0;i<size;i++){ printf("%lli ",vet[i]);}
}

void insertionsort(long long int *vet, long long int size){
	long long int i,j,aux;
	for(i=1;i<size;i++){
		j=i;
		while(vet[j]<vet[j-1] && j > 0){
			aux = vet[j];
			vet[j] = vet[j-1];
			vet[j-1] = aux;
			j--;
		}
	}
}
void showtime(double * clk){
	if(!(*clk)) *clk = clock();
	else{
		printf("\nT time: %lf",(*clk - (double)clock())/((double)CLOCKS_PER_SEC));
		*clk = 0;
	}
}
