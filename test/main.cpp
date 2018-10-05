#include <iterator> // begin(), end()

#include "gtest/gtest.h"
#include "../include/int_ranges.h"
#include <iostream> // cout, endl

using namespace ir;

TEST(IntRange, NegateBasic){
    ir::value_type A[]{ 1, 2, 3, 4, 5 };
    ir::value_type A_E[]{ -1, -2, -3, -4, -5 };
    
    auto len_before{ std::distance( std::begin(A), std::end(A) ) };
    ir::negate( std::begin(A), std::end(A) );
    auto len_after{ std::distance( std::begin(A), std::end(A) ) };
    
    ASSERT_EQ( len_before, len_after );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}

TEST(IntRange, NegateZeros){
    ir::value_type A[]{ 0, 0, 0, 0, 0 };
    ir::value_type A_E[]{ 0, 0, 0, 0, 0 };
    
    auto len_before{ std::distance( std::begin(A), std::end(A) ) };
    ir::negate( std::begin(A), std::end(A) );
    auto len_after{ std::distance( std::begin(A), std::end(A) ) };

    ASSERT_EQ( len_before, len_after );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}

TEST(IntRange, NegateMixed){
    ir::value_type A[]{ 0, -2, 1, -3, 0 };
    ir::value_type A_E[]{ 0, 2, -1, 3, 0 };
    
    auto len_before{ std::distance( std::begin(A), std::end(A) ) };
    ir::negate( std::begin(A), std::end(A) );
    auto len_after{ std::distance( std::begin(A), std::end(A) ) };
    
    ASSERT_EQ( len_before, len_after );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}

TEST(IntRange, MinBasic){
    ir::value_type A[]{ 1, 2, 3, 4, 5 };
    ir::value_type A_E = 1;
    
    auto * P_E = & A[0];
    auto len_min(ir::min( std::begin(A), std::end(A) ));
    
    ASSERT_EQ( *len_min, A_E );
    ASSERT_EQ( len_min, P_E );
}

TEST(IntRange, MinOne){
    ir::value_type A[]{1};
    ir::value_type A_E = 1;
    
    auto * P_E = & A[0];
    auto len_min(ir::min( std::begin(A), std::end(A) ));
    
    ASSERT_EQ( *len_min, A_E );
    ASSERT_EQ( len_min, P_E );
}

TEST(IntRange, MinLast){
    ir::value_type A[]{9, 8, 3, 2};
    ir::value_type A_E = 2;
    
    auto * P_E = & A[3];
    auto len_min(ir::min( std::begin(A), std::end(A) ));
    
    ASSERT_EQ( *len_min, A_E );
    ASSERT_EQ( len_min, P_E );
}

TEST(IntRange, ReverseBasic){
    ir::value_type A[]{ 1, 2, 3, 4, 5 };
    ir::value_type A_E[]{ 5, 4, 3, 2, 1};
    ir::reverse(std::begin(A), std::end(A) );
    
    ASSERT_EQ(std::distance(std::begin(A), std::end(A)), std::distance(std::begin(A_E), std::end(A_E)));
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
    
    ir::reverse(std::begin(A), std::end(A));
    ir::reverse(std::begin(A_E), std::end(A_E));    
    
    ASSERT_EQ(std::distance(std::begin(A), std::end(A)), std::distance(std::begin(A_E), std::end(A_E)));
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}

TEST(IntRange, ReverseUm){
    ir::value_type A[]{1};
    ir::value_type A_E[]{1};
    ir::reverse(std::begin(A), std::end(A));
    
    ASSERT_EQ(std::distance(std::begin(A), std::end(A)), std::distance(std::begin(A_E), std::end(A_E)));
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}

TEST(IntRange, ReverseDois){
    ir::value_type A[]{1, -1};
    ir::value_type A_E[]{-1, 1};
    ir::reverse(std::begin(A), std::end(A));
    
    ASSERT_EQ(std::distance(std::begin(A), std::end(A)), std::distance(std::begin(A_E), std::end(A_E)));
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}

TEST(IntRange, ReverseTres){
    ir::value_type A[]{1, 5 ,6};
    ir::value_type A_E[]{6, 5, 1};
    ir::reverse(std::begin(A), std::end(A));
    
    ASSERT_EQ(std::distance(std::begin(A), std::end(A)), std::distance(std::begin(A_E), std::end(A_E)));
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}


TEST(IntRange, ScalarBasic){
    ir::value_type A[]{ -1, 2, 3, 4, 5 };
    ir::value_type A_E[]{ -3, 6, 9, 12, 15};
    ir::scalar_multiplication( std::begin(A), std::end(A), 3 );
    
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
    ASSERT_EQ( std::distance( std::begin(A), std::end(A) ), std::distance( std::begin(A_E), std::end(A_E) ) );
}


TEST(IntRange, dot_productBasic){
    ir::value_type A[]{ 1, 2 };
    ir::value_type A_E[]{ 3, 6 };
    ir::value_type ret = 15;
    ir::value_type ret_func = ir::dot_product(std::begin(A), std::end(A), std::begin(A_E));
    
    ASSERT_EQ(ret_func, ret);
}

TEST(IntRange, dot_productNull){
    ir::value_type A[]{0};
    ir::value_type A_E[]{0};
    ir::value_type ret = 0;
    ir::value_type ret_func = ir::dot_product(std::begin(A), std::end(A), std::begin(A_E));
    
    ASSERT_EQ(ret_func, ret);
}

TEST(IntRange, compactBasic){
    ir::value_type A[]{-2, -8, 2, 7, -3, 10, 1, 0, -3, 7};
    ir::value_type A_E[]{2, 7, 10, 1, 7, 10, 1, 0, -3, 7};
    ir::value_type * retorno_esperado = std::begin(A) + 5; // ponteiro que deve ser retornado na função
    ir::value_type * retorno = ir::compact( std::begin(A), std::end(A) );
   
    ASSERT_EQ( std::distance( std::begin(A), std::end(A) ), std::distance( std::begin(A_E), std::end(A_E) ) );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
    ASSERT_EQ( retorno, retorno_esperado );
}

TEST(IntRange, copyBasic){
    ir::value_type A[]{-1, 2, 3, 4, 5};
    ir::value_type A_E[]{0, 0, 0, 0, 0};
    ir::value_type * retorno_esperado = std::end(A_E); // ponteiro que deve ser retornado na função
    ir::value_type * retorno = ir::copy( std::begin(A), std::end(A), std::begin(A_E));
   
    ASSERT_EQ( std::distance( std::begin(A), std::end(A) ), std::distance( std::begin(A_E), std::end(A_E) ) );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
    ASSERT_EQ( retorno, retorno_esperado );
}

TEST(IntRange, uniqueBasic){
    ir::value_type A[]{2, 1, 2, 2, 4, 5, 6, 4, 1, 8};
    ir::value_type A_E[]{2, 1, 4, 5, 6, 8};
    ir::value_type retorno_esperado = 6; // valor do último ponteiro
    ir::value_type * retorno = ir::unique(std::begin(A), std::end(A));
    
    ASSERT_EQ(std::distance(std::begin(A_E), std::end(A_E)), std::distance(std::begin(A), retorno));
    ASSERT_TRUE(std::equal(std::begin(A), retorno, std::begin(A_E)));
    ASSERT_EQ(* retorno, retorno_esperado);
}

TEST(IntRange, uniqueUm){
    ir::value_type A[]{2};
    ir::value_type A_E[]{2};
    ir::value_type * retorno_esperado = std::end(A); // ponteiro depois do 2
    ir::value_type * retorno = ir::unique(std::begin(A), std::end(A));
    
    ASSERT_EQ(std::distance(std::begin(A_E), std::end(A_E)), std::distance(std::begin(A), retorno));
    ASSERT_TRUE(std::equal(std::begin(A), retorno, std::begin(A_E)));
    ASSERT_EQ( retorno, retorno_esperado);
}


TEST(IntRange, uniqueTres){
    ir::value_type A[]{2, 1, 2};
    ir::value_type A_E[]{2, 1};
    ir::value_type * retorno_esperado = std::begin(A) + 2; // ponteiro depois do 1
    ir::value_type * retorno = ir::unique(std::begin(A), std::end(A));
    
    ASSERT_EQ(std::distance(std::begin(A_E), std::end(A_E)), std::distance(std::begin(A), retorno));
    ASSERT_TRUE(std::equal(std::begin(A), retorno, std::begin(A_E)));
    ASSERT_EQ( retorno, retorno_esperado);
}


TEST(IntRange, sort_marblesBasic){
    ir::value_type A[]{0, 0, 1, 1, 0, 1, 0, 1, 0, 0};
    ir::value_type A_E[]{0, 0, 0, 0, 0, 0, 1, 1, 1, 1};
    ir::value_type * retorno_esperado = A + 6; // valor do último ponteiro com os valores pretos
    ir::value_type * retorno = ir::sort_marbles(std::begin(A), std::end(A));
    
    ASSERT_EQ(std::distance(std::begin(A_E), std::end(A_E)), std::distance(std::begin(A), std::end(A)));
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
    ASSERT_EQ(* retorno, * retorno_esperado);
    ASSERT_EQ(* (retorno - 1), 0);
    ASSERT_EQ(* retorno, 1);
}

TEST(IntRange, sort_marblesDois){
    ir::value_type A[]{0, 1};
    ir::value_type A_E[]{0, 1};
    ir::value_type * retorno_esperado = A + 1; // valor do último ponteiro com os valores pretos
    ir::value_type * retorno = ir::sort_marbles(std::begin(A), std::end(A));
    
    ASSERT_EQ(std::distance(std::begin(A_E), std::end(A_E)), std::distance(std::begin(A), std::end(A)));
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
    ASSERT_EQ(* retorno, * retorno_esperado);
    ASSERT_EQ(* (retorno - 1), 0);
    ASSERT_EQ(* retorno, 1);
}

TEST(IntRange, sort_marblesTres){
    ir::value_type A[]{1, 0, 0};
    ir::value_type A_E[]{0, 0, 1};
    ir::value_type * retorno_esperado = A + 2; // valor do último ponteiro com os valores pretos
    ir::value_type * retorno = ir::sort_marbles(std::begin(A), std::end(A));
    
    ASSERT_EQ(std::distance(std::begin(A_E), std::end(A_E)), std::distance(std::begin(A), std::end(A)));
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
    ASSERT_EQ(* retorno, * retorno_esperado);
    ASSERT_EQ(* (retorno - 1), 0);
    ASSERT_EQ(* retorno, 1);
}

TEST(IntRange, sort_marblesBranco){
    ir::value_type A[]{1, 1, 1, 1, 1};
    ir::value_type A_E[]{1, 1, 1, 1, 1};
    ir::value_type * retorno_esperado = A; // ponteiro que aponta para o início do vetor com 1's
    ir::value_type * retorno = ir::sort_marbles(std::begin(A), std::end(A));

    ASSERT_EQ(std::distance(std::begin(A_E), std::end(A_E)), std::distance(std::begin(A), std::end(A)));
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
    ASSERT_EQ(retorno, retorno_esperado);
}

TEST(IntRange, sort_marblesPreto){
    ir::value_type A[]{0, 0, 0, 0, 0};
    ir::value_type A_E[]{0, 0, 0, 0, 0};
    ir::value_type * retorno_esperado = std::end(A); // ponteiro para o início dos 1's
    ir::value_type * retorno = ir::sort_marbles(std::begin(A), std::end(A));
        
    ASSERT_EQ(std::distance(std::begin(A_E), std::end(A_E)), std::distance(std::begin(A), std::end(A)));
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
    ASSERT_EQ(retorno, retorno_esperado);
}

TEST(IntRange, partitionBasic){
    ir::value_type A[]{-5, 7, 10, 7, 8, 9, 1, 7, -2, 3};
    ir::value_type A_E[]{-5, 3, -2, 1, 7, 7, 7, 9, 8, 10};
    ir::value_type teste_negativo(true); // teste para os primeiros valores menores que pivot
    ir::value_type teste_positivos(true); // teste para os valores maiores que pivot
    ir::value_type teste_pivot(true); // teste para os valores iguais a pivot
    ir::value_type posicao = 0;
    ir::value_type * valorA_E;
    ir::value_type pivot = * (A + 3); // valor 7
    ir::value_type soma_A(0);
    ir::value_type soma_A_E(0);

    ir::partition(std::begin(A), std::end(A), & pivot); // posição com valor 7

    for (auto i(std::begin(A)); i != std::end(A); ++i){
        valorA_E = (A_E + posicao);
        soma_A += * i;
        soma_A_E += * valorA_E;

        //verifica se a mesma posição de A e de A_E difere em relação a ser maior que pivot
        if((* i < pivot) && (* valorA_E > pivot )){ 
            teste_positivos = false;
        }

        //verifica se a mesma posição de A e de A_E difere em relação a ser menor que pivot
        if((* i > pivot) && (* valorA_E < pivot )){
            teste_negativo = false;
        }

        //verifica se a mesma posição de A e de A_E difere em relação a ser igual que pivot
        if((* i == pivot) && (* valorA_E != pivot )){
            teste_pivot = false;
        }

        // std::cout << * i << " = " << * (A_E + posicao) << std::endl;
        posicao++;
    }

    ASSERT_EQ(soma_A, soma_A_E);
    ASSERT_EQ(std::distance(std::begin(A_E), std::end(A_E)), std::distance(std::begin(A), std::end(A)));
    ASSERT_TRUE((teste_pivot == true));
    ASSERT_TRUE((teste_negativo == true));
    ASSERT_TRUE((teste_positivos == true));
}

TEST(IntRange, partitionIgual){
    ir::value_type A[]{1, 1, 1, 1};
    ir::value_type A_E[]{1, 1, 1, 1};

    ir::partition(std::begin(A), std::end(A), std::begin(A)); // posição com valor 1

    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));

}

TEST(IntRange, partitionNegate){
    ir::value_type A[]{-1, -1, -1, -1};
    ir::value_type A_E[]{-1, -1, -1, -1};
    ir::partition(std::begin(A), std::end(A), std::begin(A)); // posição com valor 1
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}

TEST(IntRange, partitionLast){
    ir::value_type A[]{-1, -1, -1, 2};
    ir::value_type A_E[]{-1, -1, -1, 2};
    ir::partition(std::begin(A), std::end(A), std::end(A) - 1); // posição com valor 2
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}

TEST(IntRange, partitionFirst){
    ir::value_type A[]{2, 4};
    ir::value_type A_E[]{2, 4};
    ir::partition(std::begin(A), std::end(A), std::end(A) - 1); // posição com valor 2
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}

TEST(IntRange, partitionOne){
    ir::value_type A[]{2};
    ir::value_type A_E[]{2};
    ir::partition(std::begin(A), std::end(A), std::end(A) - 1); // posição com valor 2
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}

TEST(IntRange, partitionOneNegate){
    ir::value_type A[]{-2};
    ir::value_type A_E[]{-2};
    ir::partition(std::begin(A), std::end(A), std::end(A) - 1); // posição com valor 2
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}

TEST(IntRange, rotateBasic){
    ir::value_type A[]{1, 2, 3, 4, 5, 6};
    ir::value_type A_E[]{3, 4, 5, 6, 1, 2};
    ir::value_type * n_first = std::begin(A) + 2;

    ir::rotate(std::begin(A), n_first, std::end(A));
        
    ASSERT_EQ(std::distance(std::begin(A_E), std::end(A_E)), std::distance(std::begin(A), std::end(A)));
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}

TEST(IntRange, rotateLast){
    ir::value_type A[]{1, 1, 1, 2, 2, 2};
    ir::value_type A_E[]{1, 1, 1, 2, 2, 2};
    ir::value_type * n_first = std::begin(A) + 6;

    ir::rotate(std::begin(A), n_first, std::end(A));
        
    ASSERT_EQ(std::distance(std::begin(A_E), std::end(A_E)), std::distance(std::begin(A), std::end(A)));
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}

TEST(IntRange, rotateFirst){
    ir::value_type A[]{1, 1, 1, 2, 2, 2};
    ir::value_type A_E[]{1, 1, 1, 2, 2, 2};
    ir::value_type * n_first = std::begin(A);

    ir::rotate(std::begin(A), n_first, std::end(A));
        
    ASSERT_EQ(std::distance(std::begin(A_E), std::end(A_E)), std::distance(std::begin(A), std::end(A)));
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}


TEST(IntRange, rotateDois){
    ir::value_type A[]{1, 2};
    ir::value_type A_E[]{2, 1};
    ir::value_type * n_first = std::begin(A) + 1;

    ir::rotate(std::begin(A), n_first, std::end(A));
        
    ASSERT_EQ(std::distance(std::begin(A_E), std::end(A_E)), std::distance(std::begin(A), std::end(A)));
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}

TEST(IntRange, rotateUm){
    ir::value_type A[]{-2};
    ir::value_type A_E[]{-2};
    ir::value_type * n_first = std::begin(A);

    ir::rotate(std::begin(A), n_first, std::end(A));
        
    ASSERT_EQ(std::distance(std::begin(A_E), std::end(A_E)), std::distance(std::begin(A), std::end(A)));
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}


TEST(IntRange, rotateTres){
    ir::value_type A[]{-2, 1, 0};
    ir::value_type A_E[]{1, 0, -2};
    ir::value_type * n_first = std::begin(A) + 1;

    ir::rotate(std::begin(A), n_first, std::end(A));
        
    ASSERT_EQ(std::distance(std::begin(A_E), std::end(A_E)), std::distance(std::begin(A), std::end(A)));
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}


int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
