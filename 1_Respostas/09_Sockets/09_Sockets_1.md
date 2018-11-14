1. Com relação ao modelo cliente-servidor, responda:

(a) Quais são as características básicas deste modelo?
	Um dos lados é iniciado e fica esperando indefinidamente até ser contactado pelo outro lado.

(b) Quais são as características básicas do servidor?
	Um servidor é um programa que espera por requisições de um cliente. Espera pela contactação do cliente. Ao ser contactado avalia a requisição e responde.

(c) Quais são as características básicas do cliente?
	De maneira geral, uma aplicação que inicia uma comunicação par-a-par é chamada cliente. Requisita algo do servidor.

2.  Com relação ao protocolo de comunicação da internet, responda:

(a) O que são protocolos de comunicação?
	De maneira simples, um protocolo pode ser definido como "as regras que governam" a sintaxe, semântica e sincronização da comunicação. Os protocolos podem ser implementados pelo hardware, software ou por uma combinação dos dois.

(b) Quais são as características básicas de protocolos de comunicação?
	Garantia da integridade da mensagem ou requisição.
	Segurança para não deixar qualquer um ter acesso.
	Como iniciar e finalizar uma mensagem.

3. Com relação ao protocolo TCP, responda:

(a) O que são portas no protocolo TCP?
	As portas são para o computador poder distinguir as diferentes fontes de dados. Assim, para facilitar este processo, cada uma destas aplicações recebe um endereço único na máquina, codificada em 16 bits: uma porta. A combinação endereço IP + Porta se torna, então, um endereço único, chamado socket.

(b) Para que servem estas portas?
	O número da porta indica a aplicação à qual se destinam os dados. Desta maneira, quando o computador recebe informações destinadas a uma porta, os dados são enviados para o aplicativo correspondente. Se for um pedido destinado ao aplicativo, este chama-se aplicativo servidor. Se for uma resposta, fala-se então de aplicativo cliente.
