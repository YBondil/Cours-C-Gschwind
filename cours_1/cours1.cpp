#include <iostream>


void print( int* tab, int size){
    
    std::cout<< "[ " ;
    for(int i = 0; i<size; i++){
         std::cout << tab[i]<< ' ' ;
    }
    std::cout << ']' << std::endl;
    ;
}
void sort(int* tab, int n){
    std::cout << "Le tableau est trié !" << std::endl;
    for(int i = 0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (tab[i]>tab[j]){
                int tmp = tab[j];
                tab[j]=tab[i];
                tab[i]=tmp;
                print(tab, n);
            }
        }
    }
}


int main(){
    //int tab[5] = {5,4,3,2,1};
    int tab[] = {5,4,3,2,1};
    sort(tab, 5);
    print(tab, 5);


    return 0;
}