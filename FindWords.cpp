#include <iostream>
using namespace std;

char matrix[24][24] = {
    "AAFLKHPFSSUFICICLESGNNH",
    "SFVREOMRWLRTTSXOQQNAOAO",
    "QEIAIFXAEIRFVFYSXIMINJI",
    "WSTRLGOCAPBIAFIWIWTUACM",
    "FEYAEAISTPCRLUJKOAKCERS",
    "RVDAKPNDEEHDEMSNCKKFOAH",
    "MRNEDSLCRRIWNRSAAFITMMI",
    "YAAECIEAHYMOTAVHRSSTISB",
    "RJSEWELCCENNIETOHWSGLSE",
    "ATANYYMOIEESNESIOIRELTR",
    "UTENEWEBHMYBETNNRAIEBEN",
    "RCLKUTEAEQJLSGSHTGDSKOA",
    "BHOICATNRRSDDECEHOOLGIT",
    "ENSLUARIRSETALOCOHCTOHE",
    "FZFUDQJYMADOYIWYGLOVESU",
    "TEKALFWONSNAEBMIEJTZNTG",
    "ESWPOSJXEUTUYOZUWAKEZHM",
    "KZUHBPEZEERFLMSNOWBALLH",
    "NSNOWBOARDYTVWYCLEVOHSA",
    "ACOCRQLGZIYCHODRAZZILBI",
    "LBVKKWANZAAQINWOLPWONSL",
    "BFREEZINGRAINSLILGTMELT",
    "HQPYLWHFMNFFUFPSWXNUMMV"
};

bool Horizontal(char* word){
    int wordLen = strlen(word);
    for(int i=0 ; i<24 ; i++){
        for(int j=0 ; j<24 ; j++){
            bool found = true;
            for(int k=0 ; k<wordLen ; k++){
                if (matrix[i][j + k] != word[k]){
                    found = false;
                }
            }
            if(found){return true;}
        }
    }
    return false;
}

bool Vertical(char* word){
    int wordLen = strlen(word);
    for(int i=0 ; i<24 ; i++){
        for(int j=0 ; j<24 ; j++){
            bool found = true;
            for(int k=0 ; k<wordLen ; k++){
                if (matrix[i + k][j] != word[k]){
                    found = false;
                }
            }
            if(found){return true;}
        }
    }
    return false;
}


int main(){
    int num;
    cin >> num;
    cin.ignore(); 

    char words[num][25]; 

    for(int i=0 ; i<num ; i++){
        cin.getline(words[i], 25);
    }

    for(int i = 0; i < num; i++){
        bool found = false;
        if (Horizontal(words[i]) || Vertical(words[i]) ){
            cout << "Ada" << endl;
        } else {
            cout << "Tidak Ada" << endl;
        }
    }

    return 0;
}
