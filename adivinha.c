#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

    int numeroSecreto;
    int quantidadeDeChute = 0;
    int nivelDificuldade;
    int chute;
    double pontos = 1000.0;
    double calculaPontosPartida = 0.0;
    int quantidadeDeChutesDificuldade = 0;
    

void apresentaçãoNivelDedificuldade(){

    printf("\n|================================|\n");
    printf("| Escolha o nivel de dificuldade |\n");
    printf("|       [1] Nivel facil          |\n");
    printf("|       [2] Nivel medio          |\n");
    printf("|       [3] Nivel dificil        |\n");
    printf("|       [4] Nivel impossivel     |\n");
    printf("|================================|\n\n");

    scanf("%d", &nivelDificuldade );

    if (nivelDificuldade != 1 && nivelDificuldade != 2 && nivelDificuldade != 3 &&nivelDificuldade !=  4){
        apresentaçãoNivelDedificuldade();
    }

}

void logicaDificuldade(){

    apresentaçãoNivelDedificuldade();

    switch (nivelDificuldade) {
        case 1 :
            quantidadeDeChutesDificuldade = 15;
        break;

        case 2 :
            quantidadeDeChutesDificuldade = 10;

        break;

        case 3 :
            quantidadeDeChutesDificuldade = 7;

        break;        
        
        case 4 :
            quantidadeDeChutesDificuldade = 5;

        break;

        default:
            break;
        }


}

void geraNumerosAleatorios(){
    int segundos = time(0);
    srand(segundos);
    numeroSecreto = rand() % 100 + 1;
}

void saudacao(){
    printf("********************************\n");
    printf("Bem vindo ao jogo de adivinhação\n");
    printf("********************************\n");
}

void fazChute(){
    printf("\nDe um chute! : ") ;
    scanf("%d", &chute);
}

void validaChute(){

        if (chute < 0){
            printf("O jogo aceita apenas numeros positivos\n");
            quantidadeDeChute--;

        } else {

            int acertou = (numeroSecreto == chute);  
                    
            if (acertou){

                printf("Belo chute! O numero secreto é %d \n", numeroSecreto);

            } else if(chute > numeroSecreto){

                printf("Voce errou!, o numero secreto é menor que o seu chute\n");

            }else {
                printf("Voce errou! O numero secreto e maior que o seu chute!\n");
            }

        }

}

void calculaPontos(){

    calculaPontosPartida = ( (double)chute - numeroSecreto )/2.0;
    pontos = pontos - fabs(calculaPontosPartida);
    printf("\nCalcula de pontos = %.2f\n", pontos);

}


int main() {

    geraNumerosAleatorios();

    saudacao();

    logicaDificuldade();

    
 
    do {

        quantidadeDeChute++;

        printf("Você tem %d chutes\n\n", quantidadeDeChutesDificuldade);

        printf("TENTATIVA [%d]\n", quantidadeDeChute);
        fazChute(); 
        calculaPontos();
        validaChute();

        quantidadeDeChutesDificuldade--;

        int ganhou = (chute != numeroSecreto);

        if (!ganhou){
            printf("Você ganhou! ;)");
            break;
        }

    }  while(quantidadeDeChutesDificuldade != 0);
    
    printf("\n\nVoce perdeu! Tente novamente\n\n");

    return 0;

}
