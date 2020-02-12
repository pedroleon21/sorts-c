#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//prototipaçao das funçoes
long long int * alloca_vet(long long int size);
void booblesort(long long int *vet,long long int size); // pointer to lli vetctor && lli size return lli pointer to vector
void forprint(long long int *vet,long long int size);// pointer to lli vector && lli size
void insertionsort(long long int *vet, long long int size); // lli pointer to vector && lli size of vector

int main(){
	//contrucao de um menu
	long long int size=0,*vet=NULL;
	int op;
	do{
		if(!size){
			printf("\n\ndefine a size: ");
			scanf("%lli", &size);
		}
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
				booblesort(vet,size);
				break;
			case 2:
				printf("err 2");
				break;
			case 4:
				if(vet != NULL) {free(vet);}                                                                                printf("\nallocating...\n");
				vet = alloca_vet(size);
				printf("\norganizing....");
				insertionsort(vet,size);
				break;
			case 5:
				size = 0;
				free(vet);
				vet=NULL;
				break;
			case 6:
				if(vet != NULL){
					printf("\n");
					forprint(vet,size);
				}else printf("\nSegmentation fault");
				break;
		}
	}while(op != 0);
	return 0;
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

