#include <bits/stdc++.h>
using namespace std;

int main(){

    std::vector<string> map = {};
    std::vector<int> rooms = {};

    std::srand(std::time(nullptr));
    
    int altura = 50;
    int comprimento = 50;

    // de uma casa i aleatória, suas adjacentes são i+1 i-1(para direita esquerda)
    // e i+comprimento i-comprimento (para cima baixo)  std::rand() % 40 == 1 
    for (int i = 0; i<(altura*comprimento) ;i++){
        map.push_back("..");
    }

    for (int i = 0; i<5; i++){
        int sk = std::rand() % (altura*comprimento);
        map[sk] = "[]";
        rooms.push_back(sk);
    }


    for (int i = 0; i<rooms.size(); i++){
        for (int j = i; j<rooms.size(); j++){
            int a = rooms[i];
            int b = rooms[j];

            int dInicioA = a%comprimento;
            int dInicioB = b%comprimento;

            int vDis;
            int vOrigin;

            int newGoal;

            if (dInicioA >= dInicioB){
                vDis = dInicioA-dInicioB;
                vOrigin = a;
                newGoal = b;
            }
            else{
                vDis = dInicioB-dInicioA;
                vOrigin = b;
                newGoal = a;
            }

            for(int k = 0; k<=vDis; k++){
                map[vOrigin-k] = "[]";
            }

            int newPoint = vOrigin-vDis;

            int alturaC = (int)newPoint/altura;
            int alturaD = (int)newGoal/altura;
            int hDis;
            int hOrigin;

            std::cout << alturaC << "|" << alturaD << endl;

            if (alturaC <= alturaD){
                hDis = alturaD-alturaC;
                hOrigin = newPoint;
            }
            else{
                hDis = alturaC-alturaD;
                hOrigin = newGoal;
            }

            for(int k = 1; k<=hDis; k++){
                map[hOrigin+(k*comprimento)] = "[]";
            }
        }
    }

    std::string TotalMap = "";
    int counts = 0;
    for (int j = 0; j< (altura*comprimento); j++){
        TotalMap += map[j];

        counts++;
        if (counts == comprimento){
            TotalMap += "\n";
            counts = 0;
        }
    }
    std::ofstream fw("mapa.txt");
    fw << TotalMap;
    fw.close();
    TotalMap = "";
    return 0;
}