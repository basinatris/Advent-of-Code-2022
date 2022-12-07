#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

int main(){
    string text;

    ifstream myfile;
    myfile.open("input.txt");

    if (myfile.is_open()){
        int total = 0;
        short index = 14;

        while(getline(myfile, text)){
            for (int i = 0; i < text.length() - index; i++){
                bool dupe = false;
                for (int j = 1; j < index; j++){
                    for (int k = 0; k < j; k++){
                        if (text[i+j] == text[i+k]) {
                            dupe = true;
                        }
                    }
                }
                if (!dupe){
                    total = i + index;
                    break;
                }
            }
        }
        
        cout <<"First marker: " <<total <<", " <<endl;
    }
    else {
        printf("failed to open\n");
        return -1;
    }
    
    return 0;
}
