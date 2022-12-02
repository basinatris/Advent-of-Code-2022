#include <iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

vector<int> totals;

int main(){
    string text;

    ifstream myfile;
    myfile.open("input.txt");

    int elves = 1;
    if (myfile.is_open()){
        int total = 0;
        while(getline(myfile, text)){

            if (text == "\0"){
                totals.push_back(total);
                cout << "Elf "<< elves << ": "<< total << endl;
                total = 0;
                elves++;
            }
            else {
                total += stoi(text);
            }
        }
        
        /* Part 1
        int max = 0;
        int elf = 0;
        for (vector<int>:: iterator it = totals.begin(); it!= totals.end(); it++){
            if (*it > max){
                max = *it;
            }
        }
        cout << "Most calories: "<< max<<endl;
        */
        

        sort(totals.begin(), totals.end(), greater<int>());
        total = 0;
        for (int i = 0; i < 3; i++){
            cout << totals[i] <<endl;
            total+=totals[i];
        }

        cout<< "Calorie total: "<<total<<endl;

    }
    else {
        printf("failed to open\n");
        return -1;
    }
    
    return 0;
}
