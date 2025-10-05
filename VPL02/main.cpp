#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    
    int tampp = 0;

    vector <string> p_p(10);

    cin >> tampp;
    

    for (int i = 0; i < tampp; i++) {
        cin >> p_p[i];
    }
    cin.ignore();

    

    string coment;
    getline(cin, coment);

    cout << "-------------------------------------------------------------------" << endl;

    int tamt = coment.length();


    int pos1 = 0;
    int pos2;
    vector <int> q_ap(tampp, 0);

    while(pos1 < tamt) {
    
        pos2 = coment.find(' ', pos1);
            
        if (coment.find(' ', pos1) == string::npos) {
            string palavra = coment.substr(pos1);
                
                for (int i = 0; i < tampp; i++) {
                    int tamp = p_p[i].length();
            
                    if (palavra.compare(p_p[i]) == 0) {
                        q_ap[i]++;
                        coment.replace(pos1, tamp, tamp, '*');
                    }
                }

            break;
        }
            
        string palavra = coment.substr(pos1, pos2 - pos1);
        
        for (int i = 0; i < tampp; i++) {
        int tamp = p_p[i].length();
            
            if (palavra.compare(p_p[i]) == 0) {
                q_ap[i]++;
                coment.replace(pos1, tamp, tamp, '*');
            }
        }
        
        pos1 += (pos2 + 1 - pos1);
    }
        cout << coment << endl;
        
        for (int i = 0; i < tampp; i++) {
            cout << "Palavra" << ' ' << p_p[i] << ' ' << "substituida" << ' ' << q_ap[i] << ' ' << "vez(es)." << endl;
        }
        
    return 0;
}
