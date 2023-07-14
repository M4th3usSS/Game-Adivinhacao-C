# Projeto de introdução a C
A proposta deste breve projeto é dar início à minha imersão na grandiosa linguagem C, com o objetivo de aprimorar minhas habilidades básicas de programação. Reconheço humildemente que há muito a aprender e, por meio dessa prática, pretendo impulsionar minha carreira como programador. Não há nada melhor do que colocar em prática o que se aprende, não é mesmo?

Agora vamos ao que interessa, segue os tópicos de minhas anotações:

- Codificação do PowerShell
- Diretivas
- Arquivos de cabeçalho 
- Variáveis 
- Desvio condicional 
- Laços de repetição (Loops)
- Casting int - float
- ASCII art 
- Como executar o código;

## Codificação do PowerShell
O primeiro desafio é resolver o conflito de codificação de arquivos do VS Code e do PowerShell, que aliás são as ferramentas que utilizei no desenvolvimento do jogo.

Os problemas de codificação ocorrem quando a codificação do VS Code ou do arquivo de script não corresponde à codificação esperada pelo PowerShell. Como o PowerShell não determina automaticamente a codificação de arquivos, os caracteres especiais resultavam em uma impressão inesperada ao executar.

A solução que encontrei foi mudar o encoding do meu VSCode e adicionar o código:
```C
#include <locale.h> 
int main(){  
	setlocale(LC_ALL,"portuguese");
	
	/*... */

}
```
Eu encontrei essa solução [aqui](https://pt.stackoverflow.com/questions/20550/imprimir-caracteres-especiais-no-console-do-windows#:~:text=Passando%20direto%20o%20c%C3%B3digo%20no%20printf%3A%20printf%20%28%22isto,oprintf%20que%20est%C3%A1%20dispon%C3%ADvel%20com%20a%20licensa%20LGPL)

Em caso de dúvidas, você pode pesquisar por caracteres especiais em C no terminal que está usando.

## Diretivas
**include** - Como o próprio nome sugere, os arquivos de cabeçalho são usados para incluir arquivos e bibliotecas em um programa.
##  Arquivos de cabeçalho
Arquivos de cabeçalho, também conhecidos como headers, permitem que os programadores separem certos elementos de um código-fonte de um programa em arquivos reutilizáveis. Esses arquivos normalmente contêm declarações de classes, sub-rotinas, variáveis e outros identificadores.

Ao incluir um arquivo de cabeçalho em um programa, as declarações contidas nele ficam disponíveis para uso no código-fonte principal, evitando a necessidade de reescrever essas declarações várias vezes em diferentes partes do programa.

Os arquivos de cabeçalho são uma prática comum em linguagens de programação como C e C++, facilitando a organização e reutilização do código.
## Variáveis 
São elementos que armazenam valores em memória. 
## Desvio condicional 
Estrutura que altera o fluxo de código de acordo com uma ou mais condições. 
Nesse jogo usamos o **if(){}**, **else{}** e **switch(){}**.
## Laços de repetição (Loops)
São estruturas que repetem trechos de código de acordo com uma ou mais condições.
Nesse jogo usamos o **while (){}**, **do{} while ()** e **for(){}**.
## Casting int - float
Casting, em linguagens de programação, refere-se à conversão de um tipo de dado para outro. O casting é usado quando se deseja explicitamente converter um valor de um tipo para outro compatível.

Existem dois tipos principais de casting: o casting implícito e o casting explícito.

O casting implícito ocorre automaticamente pelo compilador quando não há perda de informação ou risco de erros. Por exemplo, quando se atribui um valor inteiro a uma variável de tipo float, o compilador realiza o casting implícito, convertendo o valor inteiro para um número de ponto flutuante.

Já o casting explícito, também conhecido como "type casting", é quando o programador indica explicitamente ao compilador a conversão de um tipo para outro. Isso é feito através do uso de sintaxe especial ou operadores específicos da linguagem. Por exemplo, em C++, pode-se usar o operador de casting, como (int), para converter um valor de ponto flutuante em um valor inteiro.

O casting pode ser útil em situações onde é necessário converter tipos de dados para realizar operações ou atribuições corretamente. No entanto, é importante ter cuidado ao fazer castings explícitos, pois eles podem resultar em perda de precisão ou comportamento indefinido se a conversão não for válida.

Nesse jogo eu precisei de fazer um casting explícito em um variável int para float,para com isso, não truncar o resultado de uma divisão para inteiro.
```C
float pontos_perdidos = ((float)chute - numerosecreto)/2;  
```
Eu poderia usar 2.0 em vez de 2, mas a critério de conhecimento, decidi já tratar esse recurso.
## ASCII art 
ASCII art são figuras criadas somente com caracteres e podem ser imprimidas pelo terminal, eu usei algumas no código para deixar o jogo mais convidativo.

## Como executar o código
Na pasta doc, você encontrará um passo a passo de como instalar o compilador C/C++, assim como configurar o VSCode caso deseja alterar o código.

## Referência
- [Alura](https://cursos.alura.com.br/course/introducao-a-programacao-com-c-parte-1) C: conhecendo a Linguagem das Linguagens
- [Alura](https://www.alura.com.br/artigos/compilando-executando-programas-c-c-windows) Compilando e executando programas em C/C++ no Windows


