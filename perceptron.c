#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define xn 4
#define tamanhoAmostras 10



int entradas[xn];
int pesosSinapticos[xn + 1];
int amostras[xn][tamanhoAmostras];
int saidaDesejada[tamanhoAmostras];
const char separadorEntradas[2] = ";";
const char separadorSaida[2] = "-";
int funcaoSaida(int u) {
	if (u<0) return 0;
	else return 1;
}

int treinaAmostra() {}

void preencheVetorDeAmostras() {
	    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int linha = 0;

    fp = fopen("teste.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        printf("Retrieved line of length %zu :\n", read);
        printf("%s", line);
	parserAmostras(line, linha);
	linha++;
    }

    fclose(fp);
    if (line)
        free(line);
}

void parserAmostras(char *strn, int linha) {
   char copia[20];
   char *token;
   strcpy(copia, strn);
   int contx = 0;
   /* get the first token */
   token = strtok(copia, ";");
   amostras[contx][linha] = atoi(token);
	printf("VALOR DO PRIMEIRO CAST : %d \n",amostras[contx][linha]);
   contx++;
   
   /* walk through other tokens */
   while( token != NULL ) {
      token = strtok(NULL, separadorEntradas);
      amostras[contx][linha] = atoi(token);
	printf("VALOR DO segundo CAST : %d \n",amostras[contx][linha]);
      contx++;
      if(contx == xn - 1) {
        token = strtok(NULL, separadorSaida);
	amostras[contx][linha] = atoi(token);
	printf("VALOR DO ultimo CAST : %d \n",amostras[contx][linha]);
	token = strtok(NULL, separadorSaida);
  	saidaDesejada[linha] = atoi(token);
	printf("VALOR Da primeira saida: %d \n",saidaDesejada[linha]);
	token = strtok(NULL, separadorSaida);
   }
}
}

void imprimeVetores() {
	int i = 0;
	int j = 0;
	for(j = 0; j < tamanhoAmostras; j++) {
	printf("para a amostra numero %d temos: \n", j);
		for(i = 0; i < xn; i++){
		printf("entrada numero %d de valor %d \n", i, amostras[i][j]);
		}
		printf("para a saida numero %d temos: %d \n", j, saidaDesejada[j]);
	}
}

int main() {
preencheVetorDeAmostras();
imprimeVetores();
	return 0;
}

