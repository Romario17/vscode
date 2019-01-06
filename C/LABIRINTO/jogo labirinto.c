#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define cima     72
#define baixo    80
#define esquerda 75
#define direita  77

int main()
{
	int i=1, j=1, cont;
	char a;
    char mapa[10][81] = {"################################################################################",
	                     "#@#   #                                ############           ##################",
	                     "# # ### ############### ############## ############ #########          #########", 
			             "# #                   # ############## ############ ################## #########",
                         "# ################### # #                                            # #########",
	                     "#                     ############################################## #         #",
	                     "# ####################################################               ##### ### #",
	                     "#   ################################################################# ### #### #",
	                     "###                                                                  #         #",
	                     "###################################################################### #########"};
	
	for(cont = 0; cont<10; cont++)
		printf("%s\n", mapa[cont]);
	
	while(mapa[10][70]!='@'){			
    	a = getch();
		
		if(a == cima && mapa[i-1][j] != '#'){
			mapa[i][j]= ' ';
			i--;
			mapa[i][j]= '@';
			system("cls");
			for(cont = 0; cont<10; cont++)
				printf("%s\n", mapa[cont]);
	    }
	    else if(a == baixo && mapa[i+1][j] != '#'){
			mapa[i][j]= ' ';
			i++;
			mapa[i][j]= '@';
			system("cls");
			for(cont = 0; cont<10; cont++)
				printf("%s\n", mapa[cont]);
	    }
	    else if(a == esquerda && mapa[i][j-1] != '#'){
			mapa[i][j]= ' ';
			j--;
			mapa[i][j]= '@';
			system("cls");
			for(cont = 0; cont<10; cont++)
				printf("%s\n", mapa[cont]);
	    }
	    else if(a == direita && mapa[i][j+1] != '#'){
			mapa[i][j]= ' ';
			j++;
			mapa[i][j]= '@';
			system("cls");
			for(cont = 0; cont<10; cont++)
				printf("%s\n", mapa[cont]);
	    }
	}
	system("cls");
        printf("\aCongratulations!!!");                 
	return 0;
} 
