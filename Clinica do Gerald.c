#include <stdio.h>
#include <string.h>
#include <process.h>

//Definicao de arrays
#define COLUNAS 30
#define LINHAS 5
#define IDADE 5
#define ALTURA 5

//VARIAVEIS Bruxo
    char nome_bruxo [LINHAS][COLUNAS];
    char espec [LINHAS][COLUNAS];
    int codB = 0;
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

//ARRAYS Pocao
    char nome_pocao [LINHAS][COLUNAS];
    char tipo [LINHAS][COLUNAS];
    int codPoc = 0;
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

//ARRAYS Paciente
    char nome_paciente [LINHAS][COLUNAS];
    int idade [IDADE];
    float altura[ALTURA];
    int codPac = 0;
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

//VARIAVEIS Tratamento

    int tratamentos [LINHAS][5];
    int dias = 0;
    int dosagem = 0;
    int codTratamentos[LINHAS];
    int codTrat = 0;

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
void arraysAbstratos(){

	int i, j;

    for(i=0; i<LINHAS; i++){
        strcpy(nome_bruxo[i],"");
        strcpy(espec[i],"");
    }
    for(i=0; i<LINHAS; i++){
        strcpy(nome_pocao[i],"");
        strcpy(tipo[i],"");
    }
    for(i=0; i<LINHAS; i++){
        strcpy(nome_paciente[i],"");
        idade[i] = 0;
        altura[i] = 0;
    }
    for(i=0; i<LINHAS; i++)
    for (j = 0; j <5; j++){
        tratamentos[i][j] = -1;
        }
	for(i=0; i<LINHAS; i++){
		codTratamentos[i] = -1;
	}
   
}
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

void listaBruxos(){

    printf("Indice.      NOME:      ESPECIALIDADE:");
	
	int j;
    for (j = 0; j <LINHAS; ++j) {
        if(nome_bruxo[j][0] != '\0'){
            printf("\n%d.         %s           %s", j, nome_bruxo[j], espec[j]);

        } else if(nome_bruxo[j][0] == '\0'){
            printf("\n%d.   NADA CADASTRADO", j);
        }
    }
    printf("\n");
}

void cadastraBruxos() {

    printf("\nDigite o codigo de cadastro: ");
    scanf("%d", &codB);


    if(codB<0 || codB>LINHAS){ //Veri posicao invalida de array
        printf("Codigo invalido!");
        printf("\nSomente codigos de 0 a 4!");}

    else{
        if(nome_bruxo[codB][0] != '\0'){ //Veri sobreescrever posicao
            printf("\nPOSICAO INVALIDA");
            printf("\nBruxo ja cadastrado!");

        } else {
            printf("\nDigite o nome do bruxo: ");
            fflush(stdin);
            scanf("%[^\n]s", nome_bruxo[codB]);

            printf("\nDigite a especialidade do Bruxo: ");
            fflush(stdin);
            scanf("%[^\n]s", espec[codB]);
            
           
        }
    }

    printf("\n");
}

void excluirBruxo(){
	
	printf("Digite o codigo do bruxo: ");
	scanf("%d", &codB);
	
	int i;
	int cont = 0;
	
	for(i=0; i<LINHAS; i++){	// veri se a tratamento vinculado
		if(tratamentos[i][0] == codB){
			printf("\nNao e possivel exclui o paciente pois ele esta vinculado a um tratamento em andamento!");
			cont++;
			break;
		}		
	}

	if(cont == 0){
		strcpy(nome_bruxo[codB],"");
    	strcpy(espec[codB],"");
		printf("\nBruxo excluido com sucesso!");	
	}
	
}

void listaPocoes(){

    printf("Indice.      NOME:              TIPO:");
	int j;
    for (j = 0; j <LINHAS; ++j) {
        if(nome_pocao[j][0] != '\0'){
            printf("\n%d.         %s           %s", j, nome_pocao[j], tipo[j]);

        } else if(nome_pocao[j][0] == '\0'){
            printf("\n%d.   NADA CADASTRADO", j);
        }
    }

    printf("\n");
}

void cadastraPocao(){

    printf("\nDigite o codigo de cadastro: ");
    scanf("%d", &codPoc);


    if(codPoc<0 || codPoc>LINHAS){ //Veri posicao invalida de array
        printf("Codigo invalido!");
        printf("\nSomente codigos de 0 a 4!");}

    else{
        if(nome_pocao[codPoc][0] != '\0'){ //Veri sobreescrever posicao
            printf("\nPOSICAO INVALIDA");
            printf("\nPocao ja cadastrado!");

        } else {
            printf("\nDigite o nome da Pocao: ");
            fflush(stdin);
            scanf("%[^\n]s", nome_pocao[codPoc]);

            printf("\nDigite o tipo da Pocao: ");
            fflush(stdin);
            scanf("%[^\n]s", tipo[codPoc]);
        }
    }
    printf("\n");
}

void excluirPocao(){
	
	printf("Digite o codigo da pocao: ");
	scanf("%d", &codPoc);
	
	int i;
	int cont = 0;
	
	for(i=0; i<LINHAS; i++){	// veri se a tratamento vinculado
		if(tratamentos[i][2] == codPoc){
			printf("\nNao e possivel exclui a pocao pois esta vinculado a um tratamento em andamento!");
			cont++; 
			break;
		}		
	}
	
	if(cont == 0){
		strcpy(nome_pocao[codPoc],"");
    	strcpy(tipo[codPoc],"");
		printf("\nPocao excluida com sucesso!");
	}
}

void listaPacinetes(){

    printf("Indice.      NOME:      IDADE:      ALTURA:");
	int j;
    for (j = 0; j <LINHAS; ++j) {
        if(nome_paciente[j][0] != '\0'){
            printf("\n%d.         %s                %d                 %.2f", j, nome_paciente[j], idade[j], altura[j]);

        } else if(nome_paciente[j][0] == '\0'){
            printf("\n%d.   NADA CADASTRADO", j);
        }
    }

    printf("\n");
}

void cadastraPacientes(){
    printf("\nDigite o codigo de cadastro: ");
    scanf("%d", &codPac);


    if(codPac<0 || codPac>LINHAS){ //Veri posição invalida de array
        printf("Codigo invalido!");
        printf("\nSomente codigos de 0 a 4!");}

    else{
        if(nome_paciente[codPac][0] != '\0'){ //Veri sobreescrever posição
            printf("\nPOSICAO INVALIDA");
            printf("\nPaciente ja cadastrado!");

        } else {
            printf("\nDigite o nome do Paciente: ");
            fflush(stdin);
            scanf("%[^\n]s", nome_paciente[codPac]);

            printf("\nDigite a idade do Paciente: ");
            scanf("%d", &idade[codPac]);

            printf("\nDigite a altura do Paciente: ");
            scanf("%f", &altura[codPac]);
        }
    }
    printf("\n");
}

void excluirPacientes(){
	
	printf("Digite o codigo do paciente: ");
	scanf("%d", &codPac);
	
	int i;
	int cont = 0;
	
	for(i=0; i<LINHAS; i++){
		if(tratamentos[i][1] == codPac){	// veri se a tratamento vinculado
			printf("\nNao e possivel exclui bruxo pois ele esta vinculado a um tratamento em andamento!");
			cont++;
			break;
		}		
	}
	
	if(cont == 0){
		strcpy(nome_paciente[codPac],"");
    	idade[codPac] = 0;
    	altura[codPac] = 0;
		printf("\nPaciente excluido com sucesso!");
	}
}

void listaTratamentoPacientes(){
     
     printf("\nDigite o codigo do paciente: ");
     scanf("%d", &codPac);
     
     if(codPac<0 || codPac>LINHAS){
     	printf("Codigo invalido!");
        printf("\nSomente codigos de 0 a 4!");}
     
     else{
	 	int i;
     	for(i=0; i<LINHAS; i++){
     	if(tratamentos[i][1] == codPac){	
     		printf("\n%s receitou %s %d vez(es) por dia por %d dia(s)!", nome_bruxo[tratamentos[i][0]], nome_pocao[tratamentos[i][2]], tratamentos[i][3], tratamentos[i][4]);	
     		break;
		 	}else{
		 		printf("Nenhum tratamento cadastrado para este paciente!");
		 		break;
			 }
	 	}	
	 }
     
     printf("\n");
}

void listaPacientesBruxo(){
	
	int cont = 0;
	int i;
	
	printf("\nDigite o codigo do bruxo: ");
	scanf("%d", &codB);
     
     if(codB<0 || codB>LINHAS){ 	//veri posicao vaida 
     	printf("Codigo invalido!");}
		      
     else{
	 	printf("Pacientes: ");
	 	
     	for(i=0; i<LINHAS; i++){
     	if(tratamentos[i][0] == codB){	
     		printf("\n%d. %s", i, nome_paciente[tratamentos[i][1]]);
		 	}
			 else{
			 	printf("\nNenhum paciente cadastrado!");
			 	break;
			 } 	 
	 	}
     printf("\n");
   }
}

void iniTratamento(){
	
	int i;
	int cont = 0;
	
	for(i=0; i<LINHAS; i++){
		
		if(codTratamentos[i] == -1){ 	//posicao disponivel no array
		
		codTratamentos[i] = i;	
			
		printf("\nDigite o codigo do bruxo: ");
    	scanf("%d", &codB);
		if(nome_bruxo[codB][0] != '\0'){ 	//veri se tem alguem na posicao do array digitado
    		tratamentos[i][0] = codB;
		}else{
			printf("\nNao a nenhum bruxo cadastrado nessa posicao!");
			printf("\nTente novamente!");
			break;
		} 
		
		printf("\nDigite o codigo da pocao: ");
    	scanf("%d", &codPoc); 		
    	if(nome_pocao[codPoc][0] != '\0'){	//veri se tem alguem na posicao do array digitado
    		tratamentos[i][2] = codPoc; 	
		}else{
			printf("\nNao a nenhum paciente cadastrado nessa posicao!");
			printf("\nTente novamente!");
			break;
		}

    	printf("\nDigite o codigo do paciente: ");
    	scanf("%d", &codPac);
		if(nome_paciente[codPac][0] != '\0'){ 	//veri se tem alguem na posicao do array digitado
    		tratamentos[i][1] = codPac; 
		}else{
			printf("\nNao a nenhum paciente cadastrado nessa posicao!");
			printf("\nTente novamente!");
			break;
		}

		
	    printf("\nDias de tratamento: ");
	    scanf("%d", &dias);
	    tratamentos[i][3] = dias;
	
	    printf("\nDosagem da pocao:");
	    scanf("%d", &dosagem);
	    tratamentos[i][4] = dosagem;
	    
	    
	    cont ++;
	    
	    printf("\nTratamento Cadastrado!");
	    
	    printf("\nSeu codigo do tratamento: %d", codTratamentos[i]);
	    
	    break; 
		}
		else{
			printf("\nNao e possivel iniciar o tratamento!");
			printf("\nNao a espaco disponivel!");
			break;
		}	
		
	}

}

void ampliaTratamento(){
	
	int i;
	
	printf("Digite o codigo do seu tratamento: ");
	scanf("%d", &codTrat);
	
	if(codTrat<0 || codTrat>LINHAS){ 	//veri posicao valida 
     	printf("Codigo invalido!");}
     	
	else{
		for(i = 0; i<LINHAS; i++){
			if(codTratamentos[i] == codTrat){
				printf("Digite o novo tempo de tratamentos: ");
				scanf("%d", &dias);
				tratamentos[i][3] = dias;
			
				printf("Digite a nova dosagem do tratamento: ");
				scanf("%d", &dosagem);
				tratamentos[i][4] = dosagem;
			
				printf("Tratamento atualizado!");
				break;
			
			}else{
				printf("Tratamento nao encontratado!");
				break;
			}
		}
  	}
}

void apagaTratamento(){
	
	int i, j, k;
	
	printf("Digite o codigo do seu tratamento: ");
	scanf("%d", &codTrat);
	
	if(codTrat<0 || codTrat>LINHAS){ 	//veri posicao valida 
     	printf("Codigo invalido!");}
	else{
		for(i = 0; i<LINHAS; i++){
		if(codTratamentos[i] == codTrat){
			for(j = 0; j<LINHAS; j++)
				for(k = 0; k<5; k++){
					tratamentos[j][k] = -1;}				
	}
	printf("Tratamento excluido!");
	break;
  		}	
	}
	
}

int main() {
    int loop = 0;
    int menu = 0;
    arraysAbstratos();

    while (loop<1){

        printf("\n0. sair");
        printf("\n1. Listar bruxo pelo codigo");
        printf("\n2. Cadastrar bruxo pelo codigo");
        printf("\n3. Excluir bruxo pelo codigo");
	    printf("\n4. Listar pocao pelo codigo");
	    printf("\n5. Cadastrar pocao pelo codigo");
	    printf("\n6. Excluir pocao pelo codigo");
	    printf("\n7. Listar paciente pelo codigo");
	    printf("\n8. Cadastrar paciente pelo codigo");
    	printf("\n9. Excluir paciente pelo codigo");
        printf("\n10. Listar tratamentos do paciente");
        printf("\n11. Listar pacientes do bruxo");
        printf("\n12. Iniciar tratamento");
        printf("\n13. Ampliar tratamento");
        printf("\n14. Apagar tratamento");
        printf("\n:");
        scanf("%d", &menu);

        if(menu==0){
            loop++;
        }
        else if(menu==1){
            listaBruxos();
            system("pause");
        }
        else if(menu==2){
            cadastraBruxos();
            system("pause");
        }
        else if(menu==3){
        	excluirBruxo();
            system("pause");
        }
        else if(menu==4){
            listaPocoes();
            system("pause");
        }
        else if(menu==5){
            cadastraPocao();
            system("pause");
        }
        else if(menu==6){
        	excluirPocao();
            system("pause");
        }
        else if(menu==7){
            listaPacinetes();
            system("pause");
        }
        else if(menu==8){
            cadastraPacientes();
            system("pause");
        }
        else if(menu==9){
        	excluirPacientes();
            system("pause");
        }
        else if(menu==10) {
        	listaTratamentoPacientes();
            system("pause");
        }
        else if(menu==11) {
        	listaPacientesBruxo();
            system("pause");
        }
        else if(menu==12){
            iniTratamento();
            system("pause");
        }
        else if(menu==13){
            ampliaTratamento();
            system("pause");
        }
        else if(menu==14){
            apagaTratamento();
            system("pause");
        }

    }

    return 0;
}
