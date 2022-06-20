Descrição do Case e do Programa a ser Elaborado

O projeto agora é fazer “algumas melhorias” no programa entregue no sprint 1.

Na situação anterior, o concurso era individual e o projeto submetido era cadastrado com um link (URL) para descrição do projeto. 

Como sprint2 cada projeto deve ter seu próprio registro (struct) com as seguintes informações:

Nome do projeto (ou da startup)
Componentes da equipe ou sócios proprietários (máximo 4 por equipe). Cada componente ou sócio deve ter seu registro (struct) com as seguintes informações: nome e CPF. Deve ser criado um vetor de componentes com 4 elementos do tipo registro de pessoa (nome e CPF). Quando o projeto tiver menos do que 4 componentes o CPF dos elementos do vetor deve ter valor 0.
Link (URL) do projeto
Valor do investimento solicitado pelo projeto para viabilizar o projeto.



Elabore um programa C que cadastre até 10 projetos no concurso, armazenando em um vetor de registros de projetos. Cada registro de projeto deve conter as informações descritas acima e, também, mais 4 campos (1 para cada uma das 3 notas dos avaliadores e outro para a média das notas dos avaliadores. Cada componente do projeto é armazenado em um vetor (3,0 pontos)

Cada avaliador insere suas notas em um campo específico do registro do projeto. O programa deve calcular e armazenar no registro de cada projeto a média obtida. Após computar todas as médias deve ser apresentar a listagem com as médias e o nome de cada projeto cadastrado (2,0 pontos)

Ordenar o vetor dos registros dos projetos usando como critério o valor do investimento solicitado pelo projeto em ordem crescente (usando o método de ordenação bubblesort – função bubblesort).  (2,0 pontos)

Os 5 primeiros projetos do vetor terão a sua média somada com mais 0,5 ponto (limitando ao valor máximo 10) (2,0 pontos)

Se mais de um projeto for vencedor, ou seja, obtiveram mesma média vencedora, deve ser usado o mesmo critério do sprint 1. Em seguida, apresentar o grande vencedor do concurso (o registro completo do projeto) (1,0 ponto)
