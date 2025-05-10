#include <bits/stdc++.h>
#include <random>
using namespace std;

int main(){
    int randSeed = 1746896822;
    int altura = 10;
    int comprimento = 10;
    int roomsqtd = 4;
    int corredorDensidade = 1; // valor tem que ser maior que 0 --> quanto menor, menos corredores.
    std::string roomchar = "[]";
    std::string corchar = "<>";
    std::string bgchar = ". ";

    std::vector<string> map = {};
    std::vector<int> rooms = {};
    std::srand(randSeed);

    if (corredorDensidade > roomsqtd-1){
        corredorDensidade = roomsqtd-1;
    }

    for (int i = 0; i<(altura*comprimento) ;i++){
        map.push_back(bgchar);
    }

    for (int i = 0; i<roomsqtd; i++){
        int sk = std::rand() % (altura*comprimento);
        map[sk] = "[]";
        rooms.push_back(sk);
    }

    for (int i = 0; i<rooms.size()-1; i++){ // geracao de corredores
        for (int j = i+1; j<rooms.size(); j++){
            if (i % (int)((roomsqtd-1)/corredorDensidade) == 0){
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
                    map[vOrigin-k] = corchar;
                }

                int newPoint = vOrigin-vDis;
                
                int alturaC = (int)newPoint/comprimento;
                int alturaD = (int)newGoal/comprimento;
                int hDis;
                int hOrigin;

                // map[newPoint] = "!!";
                // map[newGoal] = "??";

                // std::cout << newPoint << "|" << alturaC << endl << newGoal << "|" << alturaD << endl;

                if (alturaC <= alturaD){
                    hDis = alturaD-alturaC;
                    hOrigin = newPoint;
                }
                else{
                    hDis = alturaC-alturaD;
                    hOrigin = newGoal;
                }

                for(int k = 1; k<=hDis; k++){
                    map[hOrigin+(k*comprimento)] = corchar;
                }
            }
            
        }
    }


    for (int r = 0; r<rooms.size(); r++){
        int point = rooms[r];
        int dimensionX = (int)comprimento/10; // aumento maximo para dois lados X e Y
        int dimensionY = (int)altura/10;
        
        if (dimensionX > 0){
            dimensionX -= rand() % (dimensionX);
        }
        if (dimensionY > 0){
            dimensionY -= rand() % (dimensionY);
        }
        

        int leftl = point%comprimento;
        int rightl = comprimento-leftl-1;
        int upl = (int)point/comprimento;
        int downl = altura - upl -1;

        std::vector<int> expansion = {};

        if (dimensionX <= leftl){
            for (int i = point; i>=point-dimensionX; i--){
                expansion.push_back(i);
            }
        }
        if (dimensionX <= rightl){
            for (int i = point; i<=point+dimensionX; i++){
                expansion.push_back(i);
            }
        }

        if(dimensionY < upl){
            for (int i = 0; i < dimensionY; i++){
                for (int j = 0; j < expansion.size(); j++){
                    map[expansion[j] - (i*comprimento)] = roomchar;
                }
            }
        }

        if(dimensionY <= downl){
            for (int i = 0; i <= dimensionY; i++){ 
                for (int j = 0; j < expansion.size(); j++){
                   map[expansion[j] + (i*comprimento)] = roomchar;
                }
            }
        }
    }

    std::cout << "Ok!" << endl;
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