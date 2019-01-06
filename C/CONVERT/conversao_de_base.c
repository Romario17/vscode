#include <stdio.h>

void ler_vet(int vetor[], int n){
	
	if(n < 1) return;
	
	scanf("%d", &vetor[n-1]);
	
	ler_vet(vetor, n-1);
	
	printf("N : %d", n);
}

void ler_vetor(int vetor[], int n){
	
	if(n < 1) return;
	
	printf("N : %d", n);
	ler_vetor(vetor, n-1);
	scanf("%d", &vetor[n-1]);
}

void convert(int dec, int base){
	
	int quociente, resto;
	
	quociente = dec/base;
	resto = quociente%base;
	if(quociente == 0){		
		if(resto < 10)
			printf("%d",resto);
			
		else{	
			resto = (resto-10)+65;
			printf("%c", resto);
		}
		return;	
     }
     convert(quociente, base);
}

void base(int n, int b){
	int q, r;
	
	q = n/b;
	r = n%b; 
	if(q==0){
		if(r>9){
			r = r -10 + 65;
			printf("%c", r);
		}
		else{
			printf("%d", r);
		}
		return;	
	}	
	base(q, b);
	if(r>9){
			r = r -10 + 65;
			printf("%c", r);
		}
		else{
			printf("%d", r);
		}
	}		


	
int main(){

	int a = 16, b = 17;
	
	convert(a, b);
	
return 0;	
}


