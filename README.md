# Trabalho prático para a disciplina Laboratório de Linguagens de Programação
Aplicação	 gráfica	 que simula	 o	 jogo 'Pursuit',	 onde	 dois	 jogadores	 disputam	 quem	 será	 o	
vencedor.	O	jogo	possui	um	 tabuleiro	7x7,	ou	seja,	49 células distribuídas	em	7	
linhas	e	7	colunas.	O	tabuleiro	é	preenchido	com	27	peças,	sendo	duas	de	cores	
diferentes	 para	 cada	 jogador	 e	 outras	 25	 peças	 imóveis	 que	 servem	 como	
bloqueios	 para	 as	 movimentações.	 Os	 jogadores	 alternam	 jogadas,	 onde	 cada	
uma	 consiste	 em	 duas	 etapas:	 uma	 de	 mover	 e	 outra	 de	 retirar	 uma	 peça	 de	
bloqueio.	Na	etapa	de	mover,	um	jogador	deve	conseguir	movimentar sua	peça	
em	 qualquer	 uma	 das	 8	 direções	 da	 rosa	 dos	 ventos	 (Norte,	 Nordeste,	 Leste,	
Sudeste,	 Sul,	 Sudoeste,	 Oeste,	 Noroeste),	 como	 se	 fosse	 uma	 rainha	 no	 jogo	 de	
xadrez,	de	forma	a	percorrer	todo	caminho	em	uma	dessas	direções	até	que	não	
seja	mais	possível	– ou	seja,	até	antes	de	encontrar	uma	peça	de	bloqueio ou	uma
das	bordas do	tabuleiro.	Após	o	movimento,	ele	deve	fazer	a	etapa	de	retirar	uma	
peça	de	bloqueio	do	tabuleiro	que	esteja	imediatamente	adjacente	à	sua	peça.	O	
jogo	termina	em	duas	situações:	quando	a	peça	do	jogador	consegue	movimentar	
até	 a	 peça	 adversária	 sem	 encontrar	 nenhum	 bloqueio	 no	 caminho	 ou	 quando	
um	jogador	não	consegue	fazer	uma	jogada	completa	(mover	e	retirar).
