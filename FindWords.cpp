#include <iostream>
#include <cstring>
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

void Kapital(char* str){
    for(int i = 0; str[i] != '\0'; i++){
        str[i] = toupper(str[i]);
    }
}

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

bool DiagUpLeft(char* word){
    int wordLen = strlen(word);
    for(int i=0 ; i<24 ; i++){
        for(int j=0 ; j<24 ; j++){
            bool found = true;
            for(int k=0 ; k<wordLen ; k++){
                if (matrix[i - k][j - k] != word[k]){
                    found = false;
                }
            }
            if(found){return true;}
        }
    }
    return false;
}

bool DiagUpRight(char* word){
    int wordLen = strlen(word);
    for(int i=0 ; i<24 ; i++){
        for(int j=0 ; j<24 ; j++){
            bool found = true;
            for(int k=0 ; k<wordLen ; k++){
                if (matrix[i - k][j + k] != word[k]){
                    found = false;
                }
            }
            if(found){return true;}
        }
    }
    return false;
}

bool DiagDownRight(char* word){
    int wordLen = strlen(word);
    for(int i=0 ; i<24 ; i++){
        for(int j=0 ; j<24 ; j++){
            bool found = true;
            for(int k=0 ; k<wordLen ; k++){
                if (matrix[i + k][j + k] != word[k]){
                    found = false;
                }
            }
            if(found){return true;}
        }
    }
    return false;
}


bool DiagDownLeft(char* word){
    int wordLen = strlen(word);
    for(int i=0 ; i<24 ; i++){
        for(int j=0 ; j<24 ; j++){
            bool found = true;
            for(int k=0 ; k<wordLen ; k++){
                if (matrix[i + k][j - k] != word[k]){
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
    cout << "Masukkan jumlah kata yang ingin dicari: ";
    cin >> num;
    cin.ignore(); 

    char words[num][25]; 

    for(int i=0 ; i<num ; i++){
        cin.getline(words[i], 25);
        Kapital(words[i]);
    }

    for(int i = 0; i < num; i++){
        bool found = false;
        if (Horizontal(words[i]) || Vertical(words[i]) || DiagUpLeft(words[i]) || DiagUpRight(words[i]) || DiagDownRight(words[i]) || DiagDownLeft(words[i]) ){
            cout << "Ada" << endl;
        } else {
            cout << "Tidak Ada" << endl;
        }
    }

    return 0;
}
