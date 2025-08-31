#include <iostream>
#include <cstring>
using namespace std;
class Nedviznina{
protected:
    char *adresa;
    int kvadratura;
    int cenaKvadrat;
public:
    Nedviznina(){
        this->adresa=new char[0];
        this->kvadratura=0;
        this->cenaKvadrat=0;
    }
    Nedviznina(char *adresa,int kvadratura,int cenaKvadrat) {
        this->adresa=new char[strlen(adresa)+1];
        strcpy(this->adresa,adresa);
        this->kvadratura=kvadratura;
        this->cenaKvadrat=cenaKvadrat;
    }
    Nedviznina(const Nedviznina &n) {
        this->adresa=new char[strlen(n.adresa)+1];
        strcpy(this->adresa,n.adresa);
        this->kvadratura=n.kvadratura;
        this->cenaKvadrat=n.cenaKvadrat;
    }
    friend istream &operator>>(istream &in, Nedviznina &n)
    {
        char adresa[100];
        delete[] n.adresa;
        in>>adresa;
        n.adresa=new char[strlen(adresa)+1];
        strcpy(n.adresa,adresa);
        in >> n.kvadratura >> n.cenaKvadrat;

        return in;
    }
    int cena() {
        return cenaKvadrat*kvadratura;
    }
    void pecati()
    {
        cout << adresa << ", Kvadratura: " << kvadratura << ", Cena po Kvadrat: " << cenaKvadrat << endl;
    }
    double danokNaImot() {
        return 0.05*cena();
    }
    char *getAdresa() {
        return adresa;
    }
    ~Nedviznina() {
        delete []adresa;
    }
};
class Vila : public Nedviznina{
private:
    int danok;
public:
    Vila() {
        this->danok=0;
    }
    Vila(int danok) : Nedviznina(){
        this->danok=danok;
    }
    friend istream &operator>>(istream &in, Vila &v)
    {
        char adresa[100];
        delete[] v.adresa;
        in>>adresa;
        v.adresa=new char[strlen(adresa)+1];
        strcpy(v.adresa,adresa);
        in >> v.kvadratura >> v.cenaKvadrat >> v.danok;

        return in;
    }
    double danokNaImot() {
        return cena()*(danok+5)/100;
    }
    void pecati()
    {
        cout << adresa << ", Kvadratura: " << kvadratura << ", Cena po Kvadrat: " << cenaKvadrat << ", Danok na luksuz: " << danok
             << endl;
    }
};
int main(){
    Nedviznina n;
    Vila v;
    cin>>n;
    cin>>v;
    n.pecati();
    cout<<"Danok za: "<<n.getAdresa()<<", e: "<<n.danokNaImot()<<endl;
    v.pecati();
    cout<<"Danok za: "<<v.getAdresa()<<", e: "<<v.danokNaImot()<<endl;
    return 0;
}