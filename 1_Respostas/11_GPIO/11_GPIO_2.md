1. Defina qual modelo de Raspberry Pi você utilizará no projeto desta disciplina com o Raspberry Pi. Justifique sua escolha.

	O modelo é a 3B+. Pois como será utilizado processamento de imagens em tempo real necessita-se de um melhor poder de processamento para a aplicação ser totalmente viável. 

2. Defina qual sistema operacional você utilizará no projeto desta disciplina com o Raspberry Pi. Justifique sua escolha.
	
	Como nunca teve-se um contato com o microcontrolador, foi utilizado o SO mais simples e recomendável para os iniciantes que foi o Raspbian com desktop. Porem talvez mudando para o modo STRETCH seria uma opção para melhorar o desempenho da aplicação desenvolvida. 

3. Defina de qual forma você instalará o sistema operacional escolhido. Escreva o passo-a-passo da instalação e forneça os links necessários para isto.

	1. Foi formatado o SD utilizando um software recomendado pela raspberrypi.org - https://www.balena.io/etcher/ -
	2. Com o SD formatado na estrutura de arquivos do SO. Foi baixado a .img e feito o flash pelo programa etcher. - https://www.raspberrypi.org/downloads/raspbian/ - 
	3. Foi conectado pela primeira vez como uma estação de trabalho para configurar todas as comunicações SSH e VNC.

4. Defina de qual forma você desenvolverá software para o Raspberry Pi no projeto desta disciplina. Escreva o passo-a-passo do desenvolvimento e forneça os links necessários para isto.
	
Como fica inviavel para usar a raspberry como estação de trabalho. Todo o processo será feito via VNC     (https://www.realvnc.com/pt/connect/download/viewer/)GitHub(https://github.com/helpthx/Sistemas_Embarcados/tree/master/2_PCs). O VNC será a forma de acessar e compartilhar tela, mouse e teclado. O GitHub vai ser usado como meio de transferência de arquivos, porem todas as copilações em C ou qualquer outro sofware que necessitar de copilação será copilado na própria raspberry, assim como todas as APIS e bibliotecas serão baixadas na raspberry e no PC de desenvolvimento.  

