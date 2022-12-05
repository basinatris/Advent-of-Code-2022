#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

char letters[53] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int alpha(const string &input, int array[], int l){
    //fill_n(array, l, 0);
    /*
    for (int i = 0; i < l; i++){
        array[i] = 1;
    }
    cout<<endl;*/
    
    for (int i = 0; i< l; i++){
        char c = input[i];

        for (int j = 0; j < 52; j++){
            if (c == letters[j]){
                if (array[j] == 0){
                    array[j] = 1;
                }
                break;
            }
        }
            
    }

    return 0;
}

int main(){
    string text;

    ifstream myfile;
    myfile.open("input.txt");

    if (myfile.is_open()){
        int total = 0;

        while(getline(myfile, text)){
            /* Part 1
            int l = text.length();
            string first = text.substr(0, l/2);
            string second = text.substr(l/2, l/2);
            

            int check_1[52];
            int check_2[52];

            fill_n(check_1, 52, 0);
            fill_n(check_2, 52, 0);

            for (int i = 0; i < first.length(); i++){
                char lower = 'a';
                char upper = 'A';
                char c = first[i];

                for (int j = 0; j < 26; j++){
                    if (c == lower){
                        if (check_1[j] == 0){
                            check_1[j]++;
                        }
                        break;
                    }
                    else if (c == upper){
                        if (check_1[j + 26] == 0){
                            check_1[j + 26]++;
                        }
                        break;
                    }
                    else{
                        lower++;
                        upper++;
                    }
                }
            }
            
            for (int i = 0; i < second.length(); i++){
                char lower = 'a';
                char upper = 'A';
                char c = second[i];

                for (int j = 0; j < 26; j++){
                    if (c == lower){
                        if (check_2[j] == 0){
                            check_2[j]++;
                        }
                        break;
                    }
                    else if (c == upper){
                        if (check_2[j + 26] == 0){
                            check_2[j + 26]++;
                        }
                        break;
                    }
                    else{
                        lower++;
                        upper++;
                    }
                }
            }

            cout << text << " -> " << first << " + " <<second << " | common: ";
            for (int i = 0; i < 52; i++){
                if (check_1[i] == 1 && check_2[i] ==1){
                    cout << letters[i] <<", " << "priority: "<< i;
                    total+=(i+1);
                }
            }
            cout <<endl;
            */

            string text2, text3;
            getline(myfile, text2);
            getline(myfile, text3);

            int text1_letters[52];
            fill_n(text1_letters, 52, 0);

            int text2_letters[52];
            fill_n(text2_letters, 52, 0);

            int text3_letters[52];
            fill_n(text3_letters, 52, 0);

            alpha(text, text1_letters, text.length());
            alpha(text2, text2_letters, text2.length());
            alpha(text3, text3_letters, text3.length());
            
            cout<<text << "," << text2 << ", " << text3 << "," << " ->"<< endl;

            for (int i = 0; i < 52; i++){
                if (text1_letters[i] == 1 && text2_letters[i] == 1 && text3_letters[i] == 1){
                    cout << letters[i] <<", " << "priority: "<< i;
                    total+=(i+1);
                }
            }
            cout <<endl;
            
        }
        cout << "Sum of priorities: "<< total<<endl;
        
    }
    else{
        printf("failed to open\n");
        return -1;
    }
    
    return 0;
}
