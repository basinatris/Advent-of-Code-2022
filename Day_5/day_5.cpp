#include <iostream>
#include <vector>
#include <bits/stdc++.h>


using namespace std;


int main(){
    string text;

    ifstream myfile;
    myfile.open("input.txt");

    if (myfile.is_open()){
        int total = 0;
        
        vector< deque<char> > col(9);

        while(getline(myfile, text)){
            if (text == "\0")continue;
            else if (text[0] == '['){
                for (int i = 0; i < 9; i++){
                    char c = text[1 + i*4];
                    if (c != ' ') {
                        col.at(i).push_back(c);
                        cout << c;
                    }
                }
                cout <<endl;

            }
            else if (text[1] == '1'){
                for (int i = 0; i < 9; i++){
                    char c = text[1 + i*4];
                    cout << c;
                }
                cout <<endl;
            }
            else{
                
                int num = 0, first = 0, last = 0;
                sscanf(text.c_str(), "move %d from %d to %d", &num, &first, &last);
                /* Part 1
                for (int i = 0; i < num; i++){
                    
                    char c = col[first-1].front();
                    col[first-1].pop_front();
                    col[last-1].push_front(c);
                    
                    for (int i = 0; i < 9; i++){
                        if (!col[i].empty()) cout << col[i].front();
                        else cout << ' ';
                        
                    }
                    cout<<endl;
                }*/

                stack<char> temp;
                for (int i = 0; i < num; i++){
                    char c = col[first-1].front();
                    temp.push(c);
                    col[first-1].pop_front();
                }
                int n = temp.size();
                for (int i = 0; i < n; i++){
                    char c = temp.top();
                    col[last - 1].push_front(c);
                    temp.pop();
                }
                for (int i = 0; i < 9; i++){
                    if (!col[i].empty()) cout << col[i].front();
                    else cout << ' ';
                    
                }
                cout<<endl;
            }
        }

        cout << "Top of stacks: ";
        for (int i = 0; i < 9; i++){
            cout << col[i].front();
        }
        cout<<endl;
    }
    else {
        printf("failed to open\n");
        return -1;
    }
    
    return 0;
}
