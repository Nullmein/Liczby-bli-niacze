#include <cstdio>
#include <vector>
#include <fstream>

using namespace std;

const int n = 1000000;
bool numbersTable[n + 1];


int main(){
    vector <int> tab;
    ofstream out;
    out.open("twins.cpp");
    int counter = 0;
    for (int i = 2; i*i <= n; ++i){
        if(numbersTable[i] == true){
            continue;
        }
        for(int j = i<<1; j <= n; j += i){
            numbersTable[j] = true;
        }
    }
    for (int i = 2; i <= n; i++)
        if (numbersTable[i] == false)
            tab.push_back(i);
    for (int q = 0; q < (tab.size()-1); q = q + 1){
        if(tab[q]+2 == tab[q+1]){
            //printf("%d %d\n", tab[q], tab[q+1]);
            out << tab[q] << "," << tab[q+1] << ",";
            counter += 1;
        }
    }
    printf("%d", counter);
    return 0;
}


