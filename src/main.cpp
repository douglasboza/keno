#include <iostream> // cout, endl
#include <iterator> // begin, end
#include <sstream>  // ostringstream
#include <algorithm> // for_each
#include <vector>
#include <fstream>
#include "../include/functions.h"

// Componentes:
// Douglas Pinheiro Boza
// Marcos Antonio de Freitas Júnior
 
int main (int argc, char* const argv[]){
   // int numero_rodadas = 2;
    int *lista_sorteio;
    int *lista_aposta;

	std::fstream file; 
	double valor_aposta; //guarda o valor da aposta.. primeira linha do arquivo.
	int numero_hits;	//guarda o numero de hits.. segunda linha do arquivo.
	std::vector<int> apostas_v; //vector para guardar as apostas.. terceira linha do arquivo.
	std::vector<int>::iterator cont; //contador para impressão do vector.. 
    double valor_por_rodada = 0;

	file.open(argv[1] , std::ios::in); //comando para abrir o arquivo por pront de comando.

    if (!file) {
    	/* Falhou em abrir o arquivo */
    	std::cout << "Erro ao abrir o arquivo!" << std::endl;

    }else{

    	std::cout << ">>> Arquivo de aposta carregado com sucesso!" << std::endl;

	    file >> valor_aposta; // pega o valor da aposta. esse valor eh tratado como moeda em reais.

	    std::cout << ">>> Você vai pagar um total de R$" << valor_aposta << std::endl;

    	std::cout << valor_aposta << std::endl; //impressão do valor da aposta.

    	file >> numero_hits; //pega o valor de hits. segunda linha.

        valor_por_rodada = valor_aposta/numero_hits;

    	std::cout << ">>> Você terá " << numero_hits << " rodadas, e irá pagar R$"
        << valor_por_rodada << " por rodada." << std::endl;
    	std::cout << std::endl;

		}
   // std::cout << numero_hits << std::endl; //impressão do numero de hits.

    int it; 

    while(file>>it) //atribui a it o valor de cada aposta. 
    {
    	if (it > 0 and it < 81) //testa se a aposta esta no intervalo [1 ; 80]
    	{
    		apostas_v.push_back(it); //coloca no ultima posição do vector o valor que esta em it. ou seja, cada aposta.
    	}
    }

    file.close(); //fecha o arquivo.
    int tam = apostas_v.size(); // quantidade de números apostados

    ir::NumerosAposta aposta;

    aposta.set_total_numeros_aposta(tam);
    aposta.set_valor_aposta(valor_aposta);


    // std::cout << tam << std::endl;

    aposta.alocar_array(); 
    for (int i = 0; i < tam; ++i)
    {
    	aposta.inserir_numero(apostas_v[i], i);
    }
  
    ir::Tabuleiro tabuleiro;
    tabuleiro.inicializa_tabuleiro();
    
    ir::Sorteio sorteio;
    lista_aposta = aposta.get_numeros_aposta(); 

    ir::MatrizPontos matriz_pontos;
    matriz_pontos.inicializa_matriz_pontos();
    float fator_mul(0.0);


    

    std::cout << ">>> voce apostou " << tam << " numeros!" << std::endl;
    std::cout << "--------+-----------" << std::endl;
    std::cout << "  Hits  | Pagamento " << std::endl;
    std::cout << "--------+-----------" << std::endl;

    for (int i = 0; i <= tam; ++i)
    {
    	std::cout << i << "       |" << matriz_pontos.fator_mult(tam, i) <<std::endl;
    }

    std::cout << std::endl;

    int cont_rodadas = 1;
    int total_rodadas = numero_hits;

    double ganho_rodada = 0;

    while(numero_hits > 0){
        valor_aposta = valor_aposta - valor_por_rodada;

        std::cout << "===========================================================================" << std::endl;
        std::cout << "=======================INICIO DA RODADA====================================" << std::endl;

        sorteio.gerar_sorteio();
        aposta.set_acertos(0);

        lista_sorteio = sorteio.get_lista_sorteio(); 

        std::cout << ">>>Rodada " << cont_rodadas << "/" << total_rodadas << std::endl;
        std::cout << "Seus números: \n";
        for (int i = 0; i < tam; ++i){
            std::cout << lista_aposta[i];
            if(i != tam - 1){
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

        numero_hits -= 1;
        
        tabuleiro.print_tabuleiro(&sorteio, &aposta);

        std::cout << "\nTotal de números apostados: " << tam << std::endl;

        std::cout << "\nTotal de acertos: " << aposta.get_acertos() << std::endl;
        

        /*
        fator_mul = matriz_pontos.fator_mult(aposta.get_total_numeros_aposta(), aposta.get_acertos());
        if(fator_mul != -1){
            if(fator_mul == -2){
                aposta.set_valor_aposta(aposta.get_valor_aposta() / 2);
            }else{
                aposta.set_valor_aposta(aposta.get_valor_aposta() * fator_mul);
            }
        }
        */

        fator_mul = matriz_pontos.fator_mult(aposta.get_total_numeros_aposta(), aposta.get_acertos());

        // std::cout << fator_mul << std::endl;
        if(fator_mul == 0.5){
            ganho_rodada = (valor_por_rodada/2);
        }else{
            ganho_rodada = ((int) fator_mul * valor_por_rodada);
        }

        valor_aposta = valor_aposta + ganho_rodada;

        std::cout << "\n>>>Taxa de Pagamento eh de: " << fator_mul << ", Assim voce ganhou: " << ganho_rodada << std::endl;
        std::cout << "\n>>>Seu saldo liquido: " << valor_aposta   << std::endl;

        //std::cout << "\nfator: " << fator_mul << std::endl;
        cont_rodadas++;

        std::cout << "========================FIM DA RODADA======================================" << std::endl;
    }
	// sorteio.print_lista_sorteio();

        std::cout << "=========================FIM DO JOGO=======================================" << std::endl;
    aposta.liberar_array(); 

    return EXIT_SUCCESS;
}
