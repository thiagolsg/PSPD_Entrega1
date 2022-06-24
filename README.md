# PSPD_Entrega1
## Sobre o Projeto
O projeto consiste em fazer uma função para rodar em uma conexão tcp e a mesma função em uma conexão rcp

PDF da questão [aqui](PSPD2022_1_Lab1.pdf)

## Conexão TCP 
### Como rodar
1) Abra um terminal na pasta local e execute o comando abaixo
```
cd TCP
gcc tcp_server_projeto_1.c -o server
./server 
```
2) Abra outro terminal na pasta local e execute o comando abaixo
```
cd TCP
gcc tcp_client_projeto_1.c -o -lm server
./client
```
## Conexão RPC 
### Como rodar
1) Abra um terminal na pasta local e execute o comando abaixo
```
cd RPC
make
./projeto_1_server
```
2) Abra outro terminal na pasta local e execute o comando abaixo
```
cd RPC
./projeto_1_client localhost
```
