#include <iostream> // cout, endl
#include <iterator> // begin, end
#include <sstream>  // ostringstream
#include <algorithm> // for_each
#include "../include/functions.h"

// Componentes:
// Douglas Pinheiro Boza
// Marcos Antonio de Freitas Júnior
 
int main (int argc, char* const argv[]){
    int numero_rodadas = 2;
    int *lista_sorteio;
    int *lista_aposta;

    ir::NumerosAposta aposta;

    aposta.set_total_numeros_aposta(10);
    aposta.set_valor_aposta(1000);

    aposta.alocar_array(); 
    aposta.inserir_numero(20, 0);
    aposta.inserir_numero(30, 1);
    aposta.inserir_numero(40, 2);
    aposta.inserir_numero(50, 3);
    aposta.inserir_numero(60, 4);
    aposta.inserir_numero(70, 5);
    aposta.inserir_numero(80, 6);
    aposta.inserir_numero(11, 7);
    aposta.inserir_numero(22, 8);
    aposta.inserir_numero(33, 9);


    ir::Tabuleiro tabuleiro;
    tabuleiro.inicializa_tabuleiro();
    
    ir::Sorteio sorteio;
    lista_aposta = aposta.get_numeros_aposta(); 

    ir::MatrizPontos matriz_pontos;
    matriz_pontos.inicializa_matriz_pontos();
    int fator_mul(0);

    while(numero_rodadas >= 0){
        sorteio.gerar_sorteio();
        aposta.set_acertos(0);

        lista_sorteio = sorteio.get_lista_sorteio(); 

        std::cout << "---- Nova rodada ----\n" << std::endl;
        std::cout << "Seus números: \n";
        for (int i = 0; i < 10; ++i){
            std::cout << lista_aposta[i];
            if(i != 9){
                std::cout << ", ";
            }
        }

        std::cout << "\n\nNúmeros do sorteio: \n";
        for (int i = 0; i < 20; ++i){
            std::cout << lista_sorteio[i];
            if(i != 19){
                std::cout << ", ";
            }
        }

        numero_rodadas -= 1;
        
        tabuleiro.print_tabuleiro(sorteio, &aposta);

        
        std::cout << "\nTotal de números apostados: " << aposta.get_total_numeros_aposta() << std::endl;

        std::cout << "\nTotal de acertos: " << aposta.get_acertos() << std::endl;
        
        fator_mul = matriz_pontos.fator_mult(aposta.get_total_numeros_aposta(), aposta.get_acertos());
        if(fator_mul != -1){
            if(fator_mul == -2){
                aposta.set_valor_aposta(aposta.get_valor_aposta() / 2);
            }else{
                aposta.set_valor_aposta(aposta.get_valor_aposta() * fator_mul);
            }
        }
        std::cout << "\nValor total: " << aposta.get_valor_aposta() << std::endl;
        std::cout << "\nfator: " << fator_mul << std::endl;

        
    }


    // sorteio.print_lista_sorteio();


    aposta.liberar_array(); 

    // std::cout << aposta.into_array(20) << std::endl;
    // std::cout << aposta.into_array(1) << std::endl;
    // std::cout << aposta.into_array(44) << std::endl;

    // int opcao;
    // int linhas(0);
    // int colunas(0);
    // int tabuleiros(0);

    // std::cout << "Gerar tabuleiros: 1" << std::endl;
    // std::cout << "Jogar: 2" << std::endl;
    // std::cin >> opcao;

    // if(opcao == 1){
    //     std::cout << "Número de linhas? digite pelo menos 10" << std::endl;
    //     while(linhas < 10){
    //         std::cin >> linhas;
    //     }

    //     std::cout << "Número de colunas? digite pelo menos 10" << std::endl;
    //     while(colunas < 10){
    //         std::cin >> colunas;
    //     }


    //     std::cout << "Número de tabuleiros? digite pelo menos 1" << std::endl;
    //     while(tabuleiros == 0){
    //         std::cin >> tabuleiros;
    //     }

    //     bool teste_gerou(true);
    //     ir::inicializa_matriz(linhas, colunas); // matriz do tabuleiro
    //     ir::carrega_strings_tabuleiro(); // carrega os tabuleiros já geraos para verificação posterior

    //     while(tabuleiros > 0){
    //         ir::zera_matriz(); // cada elemento vira 0
    //         teste_gerou = ir::principal();
    //         if(teste_gerou == false){ // se não gerar uma matriz
    //             tabuleiros += 1; // gerou
    //         }else{
    //             tabuleiros -= 1; // não gerou
    //         }
    //     }
    //     ir::liberar();
    // }else{
    //     if(opcao == 2){
    //         std::cout << "Qual o tabuleiro que você deseja jogar?" << std::endl;
    //         while(tabuleiros == 0){
    //             std::cin >> tabuleiros;
    //         }      

    //         if(ir::carrega_tabuleiro(tabuleiros)){ // se conseguir carregar o tabuleiro
    //             ir::iniciar_jogo();
    //         }
    //     }
    // }






    return EXIT_SUCCESS;
}
