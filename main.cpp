#include<iostream>
#include<string>

using namespace std;
int dia, mes, anno;
bool bis;


class Date {
private:
    string day;
    string month;
    string year;
public:
    Date(string, string, string);
    void intro();
    void validation();
    void increment();

    int validation_month(int mes, int anno);
    static bool bisiesto_validation(int anno);
};

Date::Date(string _day, string _month, string _year) {
    day = _day;
    month = _month;
    year = _year;
}

void Date::intro() {
    cout << "Introdusca la fecha deseada" << endl;
    cout << "Dia" << endl;
    cin >> day;
    dia = stoi(day);
    cout << "Mes" << endl;
    cin >> month;
    mes = stoi(month);
    cout << "Anio" << endl;
    cin >> year;
    anno = stoi(year);
    system("cls");
}

void Date::validation() {
    if((anno%4==0) && (anno%100!=100) || (anno%400==0))
        bis = true;

    if(dia>0 && dia<32 && mes>0 && mes<13 && anno>0){
        if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12)
        {
            cout << "\nFecha valida";
        }
        else
        {
            if(mes==2 && dia<30 && bis) {
                cout << "\nFecha valida";
            }
            else if(mes==2 && dia<29 && !bis)
                cout << "\nFecha valida";
            else if(mes!=2 && dia<31)
                cout << "\nFecha valida";
            else
                cout << "\nFecha no valida";
        }
    }
    else {
        cout << "\nFecha no valida";
    }
}

int Date::validation_month(int mes, int anno) {
    int dias ;
    if((anno%4==0) && (anno%100!=100) || (anno%400==0))
        bis = true;

    if(dia>0 && dia<32 && mes>0 && mes<13 && anno>0){
        if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12)
        {
            dias = 31;
        }
        }
    if(mes==2 && dia<30 && bis) {
                dias = 29;
            }
            else if(mes==2 && dia<29 && !bis){
                dias = 28;
            }
            else if(mes!=2 && dia<31){
                dias = 30;
            }
    else{
        cout<<"\nFecha no valida";
    }
    return dias;
}

void Date::increment() {
    dia++;
    if ((dia > validation_month(mes, anno))){
        dia = 1;
        mes++;
        if (mes > 12){
            mes = 1;
            anno++;
        }
        cout << endl << dia << "/" << mes << "/" << anno;
    }
    }

int main() {
    Date vd("","","");
    vd.intro();
    vd.validation();
    vd.increment();
    return 0;
}