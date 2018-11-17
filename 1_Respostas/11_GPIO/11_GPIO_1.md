1. Apresente 5 sistemas operacionais suportados pelo Raspberry Pi, e algumas de suas características.

	1. Raspbian baseada em Debian.
	2. Ubuntu MATE baseado em no Ubuntu.
	3. OSMC torna a raspberry um media center com varias funcionalidades.
	4. Recalbox Torna uma central de emulação de video games antigos.
	5. Pidora uma versão baseada no Fedora, da Red Hat.

2. Apresente as formas de instalação de sistemas operacionais para o Raspberry Pi.
	
	Geralmente deve-se fazer um cartão SD bootável que rode como uma especie de HD no SO.
	
3. Apresente 3 formas de desenvolvimento de software para o Raspberry Pi.
	
	Como a arquitetura do processador não é Intel, deve-se tomar alguns cuidados no desenvolvimento.
	1. Pode-se fazer todo o desenvolvimento e copilações na própria raspberry.
	2. Pode-se copilar em outro Computador porem com APIs de arquitetura da ARM11 e enviar para a raspberry remotamente.
	3. Quando não forem softwares copilados não existe esse problema.

4. Apresente 3 formas de acesso remoto ao Raspberry Pi.
	
	1. Pode acessar a raspberry como uma estação de trabalho, com monitorm teclado e mouse.
	2. Pode-se conectar um capo de ethernet e fazer uma comunicação com SSH. Para isso basta saber o IP local da raspberry.
	3. Pode-se conectar a raspberry via VNC ligado-a na rede wifi e sabendo seu endereço. 

5. Apresente as formas possíveis de compilação de código em C para o Raspberry Pi.
	
	Pode ser feita pela própria gcc na raspberry ou pode-se copilar em outra maquina com poder de processamento maior porem com APIS de desenvolvimento que sejam compatíveis com a arquitetura do processador ARM11.

6. Apresente as formas possíveis de compilação de código em Python para o Raspberry Pi.
	Como python, assim como outras aplicações são softwares que são interpretáveis. Não sofrem da diferença de arquitetura do processador. Portanto, basta desenvolver o código em python e possuir todas as bibliotecas necessárias que o software irá rodar. 

refs: https://www.filipeflop.com/blog/linguagem-c-com-raspberry-pi/
