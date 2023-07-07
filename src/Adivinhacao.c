#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
#include <time.h>
#include "../include/AsciiArt.h"

// ========= Codificação =========
// Use a codificação ISO 8859-15
// Adicione a biblioteca locale.h
// Adicione na main :
// setlocale(LC_ALL,"portuguese");
// ===============================

int main(){  
    
    setlocale(LC_ALL,"portuguese");

    int repetir = 1;
    int seed_segundos;
    int num_random;
    int numerosecreto;
    int chute;
    int num_de_tentativas;
    int tentativa;
    int nivel;
    float pontos;
    
    do{
        seed_segundos = time(0); // time(0) retorna os segundos percorridos desde 01/01/1979;
        srand(seed_segundos);    // srand() seed da função rand, seu parâmetro deve ser alguma fonte variável;
        num_random = rand();     // rand()  função que gera um número randômico;
        numerosecreto = (num_random % 100)+1; // num_random % 100 ====> O resto da divisão de um número qualquer está sempre entre 0 e 99
        tentativa = 1;
        pontos = 1000;
        
        while (1){
            ASCII_AST_01();
            printf("Em que nível de dificulade você deseja jogar ?\n");
            printf("(1) FÁCIL   (2) MÉDIO   (3) DIFÍCIL : \n");
            scanf("%d",&nivel);

            switch (nivel){
                case 1:
                    num_de_tentativas = 15;
                    break;
                case 2:
                    num_de_tentativas = 10;
                    break;
                case 3:
                    num_de_tentativas = 5;
                    break; 
                default:
                    printf("Entre com um valor válido\n\n");
                continue;
            }
            break;
        }
        
        int acertou = 0;
        int chute_maior = 0;
        int chute_menor = 0;
        int chute_num_negativo = 0;
    
        for(int i =1 ;i <= num_de_tentativas;i++){

            printf("\nTentativa %d de %d\n",tentativa,num_de_tentativas);
            printf("Qual é o seu chute: ");
            scanf("%d", &chute); //Sempre use o & na função scanf 
            printf("Seu chute foi: %d\n",chute);

            chute_num_negativo = (chute < 0);
            chute_maior = (chute > numerosecreto);
            chute_menor = (chute < numerosecreto);
            acertou = (chute == numerosecreto);

            if (chute_num_negativo){
                printf("Você não pode chutar números negativos!\n");
                continue;
            }else if (acertou){ 
                break;
            } 
            else if (chute_maior){
                printf("Seu chute foi maior que o número secreto!\n");
            } 
            else {
                printf("Seu chute foi menor que o número secreto!\n");
            }

            tentativa++;

            // Se a divião for entre variáveis ou constantes inteiras, o compilador irá truncar o resultado como inteiro, mesmo que a variável que recebe seu valor seja do tipo float ou double.
            // Para que o resultado seja do tipo float ou double, pelo menos um dos operandos da expressão deve ser desse tipo.
            // Use os recursos de casting para mudar o tipo de variáveis;
            
            float pontos_perdidos = ((float)chute - (float)numerosecreto)/(float)2; 

            pontos = pontos - abs(pontos_perdidos); // Para usar o abs inclua a biblioteca <stdlib.h>;

        }  

        if(acertou){
            ASCII_AST_02();
            printf("\nFim de jogo!\n");
            printf("Parabéns , você venceu!\n");
            printf("Você acertou em %d tentativas!\n",tentativa);
            printf("Total de pontos :%.2f\n",pontos); 
        } else {
            ASCII_AST_03();
            printf("\nVocê perdeu! Tente de novo!\n");
        }

        printf("\n\nAutor: Matheus Sousa\n");
        printf("=======================================\n");
        printf("    (1) REPETIR     (2) FINALIZAR");
        scanf("%d",&repetir);

        switch (repetir){
        case 1:
            repetir = 1;
            system("cls");
            break;   
        case 2:
            repetir = 0;   
            break;    
        }
      
    } while (repetir == 1);
    
    return 0;
}
