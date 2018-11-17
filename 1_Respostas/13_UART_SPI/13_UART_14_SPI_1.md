1. Cite as vantagens e desvantagens das comunicação serial:

(a) Assíncrona (UART).

R:Menos fios do que a comunicação sincrona. Menor velocidade de transmissão. Maior suscetividade a erro na transmissão de dados. Menos complexo de ser implementado. protocolo full-duplex, não precisa esperar.

(b) SPI.
R:Mais fios de implementação. Pode existir infinitos slaves de comunicação. Transmissão em uma velocidade maior. Mais complexa de ser implementada. Necessita de um fio de clock para sincronizar. Comunicação full-duplex, ou seja, em quanto envia-se mensagem simultaneamente recebe algo.

2. Considere o caso em que a Raspberry Pi deve receber leituras analógico/digitais de um MSP430, e que a comunicação entre os dois é UART. É tecnicamente possível que o MSP430 mande os resultados da conversão A/D a qualquer hora, ou ele deve aguardar a Raspberry Pi fazer um pedido ao MSP430? Por quê?

R:Considerando a comunicação UART como sendo full-duplex. A raspberry teria que mandar uma solicitação de informações em um buffer de tx e deixar o buffer de rx em espera de resultados, assim quando o buffer de rx da MSP receber o sinal ela pode enviar atraves do buffer tx as leituras analógicas/digitais para o rx da raspberry.  

3. Considere o caso em que a Raspberry Pi deve receber leituras analógico/digitais de um MSP430, que a comunicação entre os dois seja SPI, e que o MSP430 seja o escravo. É tecnicamente possível que o MSP430 mande os resultados da conversão A/D a qualquer hora, ou ele deve aguardar a Raspberry Pi fazer um pedido ao MSP430? Por quê?

R:Como a comunicação SPI é feita atraves de uma shitf-register e ao transmitir uma informação automaticamente o outro lado recebe algo, a MSP pode inicar a comunicação desde de que o CS estiver em nivel baixo, assim poderá enviar os dados e ao mesmo tempo poderá receber algum dado aleatório vindo da raspberry.

4. Se o Raspberry Pi tiver de se comunicar com dois dispositivos via UART, como executar a comunicação com o segundo dispositivo?

R:Como existe uma limitação entre a comunicação UART, a rasberry deve usar outro canal de comunicação e implentar um codigo paralelo ao outro codigo. Essa é uma das limitações da comunicação UART.

5. Se o Raspberry Pi tiver de se comunicar com dois dispositivos via SPI, como executar a comunicação com o segundo dispositivo?

R:Com SPI não existi limite de comunicação com os slaves, basta implentar uma logica onde os CS dos slaves serão acessados de forma exclusiva, ou seja, em quanto um CS0 esta em nivel baixo o CS1 esta em nivel logico alto e vice-versa. Essa é uma das vantagens do protocolo SPI.
