/*
Nombre: Juan Esteban Salas
Codigo: 8975783
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

string findMiddleString(string s1, string s2) {
    int nMin = min(s1.length(), s2.length());
    int nMax = max(s1.length(), s2.length());
    string result = "";
    bool state = true;
    for(int i = 0; i < nMin && state; i++){
        if(s1[i] == s2[i]){
            result += s1[i];
        }
        else{
            if(s1[i] - s2[i] > 1){
                if(i+1 != s1.size()){
                    result += s2[i]+1;
                    
                }else{
                    result += s2[i];
                }
                i = nMin;
            }else if(s2[i] - s1[i] > 1){
                if(i+1 != s1.size()){
                    result += s1[i]+1;
                }else{
                    result += s1[i];
                }
                i = nMin;
            }
            else{
                if(s1[i] - s2[i] == 1 || s2[i] - s1[i] == 1){
                    if(i+1 == s1.size()){
                        result += s1[i];
                    }
                    else if(i+1 != s2.size()){
                        result += s2[i];
                        i = nMin;
                    }
                    else{
                        result += s1[i];
 
                        if(i+1 == nMin){
                            for(int j = i+1; j < nMax;j++){
                                if(s1[j]+1 < 'Z'){
                                    
                                    result += s1[j]+1;
                                    j = nMax;
                                }else{
                                    result += s1[j];
                                }
                            }
                        }

                        
                    }
                }
                else{
                    if(s2.size() < s1.size()){
                        if(s1[i]+1 != 'Z'){
                            result += s1[i]+1;
                            i = nMin;
                        }else{
                            
                            result += s1[i];
                        }
                        
                    }
                }
            }

        }
    }
    return result;
}


int main(){
    int n;
    while(scanf("%d\n", &n) == 1 && n != 0){
        string nombre, mitad, names[n] = {}, name1, name2;
        for(int i = 0; i < n; i++){
            cin >> nombre;
            names[i] = nombre;
        }
        sort(names,names+n);
        
        if(n > 2){
            name1 = names[((n-1)/2)];
            name2 = names[((n-1)/2)+1];
        }
        else{
            name1 = names[0];
            name2 = names[1];
        }

        mitad = findMiddleString(name1,name2);

        cout << mitad << "\n";

    }
    return 0;
}
