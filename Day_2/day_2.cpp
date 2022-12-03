#include <iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;



int check_score(char p){
    if (p == 'A' || p == 'X'){
        return 1;
    }
    else if (p == 'B' || p == 'Y'){
        return 2;
    }
    else if (p == 'C' || p == 'Z'){
        return 3;
    }
    return -1;
}



int main(){
    string text;

    ifstream myfile;
    myfile.open("input.txt");

    if (myfile.is_open()){
        int total = 0;

        while(getline(myfile, text)){
            char p1, p2;
            int p1_s, p2_s;
            sscanf(text.c_str(), "%c %c", &p1, &p2);
            /* Part 1
            p1_s = -1*check_score(p1);
            p2_s = check_score(p2);

            
            int score = p2_s;
            int check = p1_s + p2_s;

            if (check == 0) score += 3;
            else if (check == 1) score += 6;
            else if (check == -1) score += 0;
            else if (check == -2) score += 6;
            
            total += score;
            
            cout <<p1 <<"," <<p2 <<"|" <<p1_s <<", " <<p2_s <<" ->score: " << score << endl;
            */

            int score = 0;
            p1_s = check_score(p1);

            switch (p2){
                case 'X':
                    switch (p1){
                        case 'A':
                            score +=3;
                            break;
                        case 'B':
                            score +=1;
                            break;
                        case 'C':
                            score +=2;
                            break;
                    }
                    break;
                case 'Y':
                    score = p1_s;
                    score += 3;
                    break;
                case 'Z':
                    switch (p1){
                        case 'A':
                            score +=2;
                            break;
                        case 'B':
                            score +=3;
                            break;
                        case 'C':
                            score +=1;
                            break;
                    }
                    score += 6;
                    break;
           }

            cout <<p1 <<"," <<p2 <<" -> score: " << score << endl;
            total += score;
        }
        cout << "Total: "<< total <<endl;
        
    }
    else {
        printf("failed to open\n");
        return -1;
    }
    
    return 0;
}
