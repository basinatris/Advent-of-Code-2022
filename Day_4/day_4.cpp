#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> totals;

int main(){
    string text;

    ifstream myfile;
    myfile.open("input.txt");

    int elves = 1;
    if (myfile.is_open()){
        int total = 0;
        int full_cover = 0;
        int partial_cover = 0;
        while(getline(myfile, text)){
            int r1_1, r1_2, r2_1, r2_2;
            sscanf(text.c_str(), "%d-%d, %d-%d", &r1_1, &r1_2, &r2_1, &r2_2);

            cout << text << " -> ";
            
            if (r1_1 >= r2_1 && r1_2 <= r2_2){
                cout << "Second fully covers first"<<endl;
                total++;
                full_cover++;
            }
            else if (r1_1 <= r2_1 && r1_2 >= r2_2){
                cout << "First fully covers second"<<endl;
                total++;
                full_cover++;
            }
            else if ((r1_1 >= r2_1 && r1_1 <= r2_2) || (r1_2 >= r2_1 && r1_2 <= r2_2) || (r2_1 >= r1_2 && r2_1 <= r1_2) || 
            (r2_2 >= r1_2 && r2_2 <= r1_2)){
                cout << "Partial cover"<<endl;
                total++;
                partial_cover++;
            }
            else cout<< "No cover"<<endl;
            

           

        }
        cout << "Partial cover: " << partial_cover <<endl;
        cout << "Full cover: " << full_cover <<endl;
        cout << "Total covered: " <<total <<endl;
    }
    else {
        printf("failed to open\n");
        return -1;
    }
    
    return 0;
}
