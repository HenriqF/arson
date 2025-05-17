# arson
Esse é um programa de geração de "dungeons". Em especifico, cria um mapa de n por m com x quartos conectados por corredores.
<br><br>
Essa foi a minha primeira vez tentando fazer algo do tipo, como sempre 'à improvisada', e, pra piorar, fiz às pressas. Então, pelo menos por enquanto, restam inúmeras otimizações e melhorias no algoritmo.<br>
*O sistema de coordenadas usado tem a intenção de ser estupido*.
<br><br>
Para editar os parametros de geração, é necessário alterar as variaveis dentro do código:

```cpp
  int randSeed = 1746896822; // Essa é a seed do RNG do c++; para obter um numero aleatório toda vez, substitua o numero por "std::time(nullptr)"
  int altura = 10; // Altura do mapa 
  int comprimento = 10; // Comprimento do mapa p.s.: se o produto de altura e comprimento for maior que 2^15, a geração de mapa falhará parcialmente.
  int roomsqtd = 4; // Quantia de quartos
  int corredorDensidade = 1; // Quanto menor, menos corredores. Valor tem que ser maior que 0.
  std::string roomchar = "[]"; // "Textura" de quartos
  std::string corchar = "<>"; // "Textura" de corredores
  std::string bgchar = ". "; // "Textura" do fundo.
```

Ao executar o código, um arquivo de texto "mapa.txt" será criado com o conteúdo.<br><br><br>
![image](https://github.com/user-attachments/assets/b223611d-a984-4d26-98f6-b2c159ed518f)
