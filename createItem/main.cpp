#include <iostream>
#include <fstream>
#include "..\Weapon.h"
#include "..\Armor.h"
using namespace std;

Weapon* wea[100];
Armor* arm[100];


int main()
{
    setlocale(LC_ALL,"Russian_Russia.1251");
    int n=1,m=1,k=-1;
    cout<<"Item"<<endl;
    cout<<"1 Wearpon"<<endl;
    cout<<"2 Armor"<<endl;
    cin>>n;
    cout<<endl;
    cout<<"1 Add\n 2 Delete\n 3 Write";
    cin>>m;
    cout<<endl;
    switch (n) {
    case 1:{
        ifstream in("Weapon.bon",ios::binary|ios::in);
            in>>k;
            for(int i=0;i<=k;i++){
                wea[i]= new Weapon("a",1,1,1);
                in.read((char*)*&wea[i],sizeof(Weapon));
            }
        in.close();
        switch (m) {
        case 1:{
            k++;
            ofstream out("Weapon.bon",ios::binary|ios::out);
            std::string name="lol";
            int dmg=1;
            int type=1;
            int color=1;
            cout<<"\nName: ";
            cin.ignore(1,'\n');
            getline(cin,name);
            cout<<"\nÓðîí: ";
            cin>>dmg;
            cout<<"\nType ";
            cin>>type;
            cout<<"\nColor ";
            cin>>color;
            wea[k]= new Weapon(name,type,dmg,color);
            out<<k;
            for(int i=0;i<=k;i++){
                out.write((char*)*&wea[i],sizeof(Weapon));
            }
            out.close();
            break;}
        case 2:{
            cout<<"\nID:";
            int id=0;
            cin>>id;
            wea[id]->Set_name("DELETED");
            wea[id]->Set_dmg(0);
            ofstream out("Weapon.bon",ios::binary|ios::out);
            out<<k;
            for(int i=0;i<=k;i++){
                out.write((char*)*&wea[i],sizeof(Weapon));
            }
            out.close();
            break;
        }
        case 3:{
            for(int i=0;i<=k;i++){
                cout<<"ID:";
                cout<<i<<endl;
                cout<<endl<<"Name:";
                std::setlocale(LC_ALL,"rus_rus.866");
                cout<<wea[i]->Get_name()<<endl;
                setlocale(LC_ALL,"Russian_Russia.1251");
                cout<<"Damage:"<<wea[i]->Attack()<<endl<<"Color:"<<wea[i]->Get_color()<<endl<<"Type:"<<wea[i]->Get_type()<<endl;

            }
        }
        break;
        }
    break;}
    case 2:{
        ifstream in("Armor.bon",ios::binary|ios::in);
            in>>k;
            for(int i=0;i<=k;i++){
                arm[i]= new Armor("a",1,1,1,1,1,1);
                in.read((char*)*&arm[i],sizeof(Armor));
            }
        in.close();
        switch (m) {
        case 1:{
            k++;
            ofstream out("Armor.bon",ios::binary|ios::out);
            std::string name="lol";
            int type=1;
            int color=1,p_resist=1,m_resist=1,type_stat=0,stat=0;
            cout<<"\nName: ";
            cin.ignore(1,'\n');
            getline(cin,name);
            cout<<"\nType ";
            cin>>type;
            cout<<"\nColor ";
            cin>>color;
            cout<<"\nP_resist ";
            cin>>p_resist;
            cout<<"\nM_resist ";
            cin>>m_resist;
            cout<<"\nType_stat ";
            cin>>type_stat;
            cout<<"Stat";
            cin>>stat;
            arm[k]= new Armor(name,type,p_resist,m_resist,type_stat,stat,color);
            out<<k;
            for(int i=0;i<=k;i++){
                out.write((char*)*&arm[i],sizeof(Armor));
            }
            out.close();
            break;
        }
        case 2:{
            cout<<"ID:";
            int id=0;
            cin>>id;
            arm[id]->Set_name("DELETED");
            arm[id]->Set_p_m_stat(0,0,0);
            ofstream out("Armor.bon",ios::binary|ios::out);
            out<<k;
            for(int i=0;i<=k;i++){
                out.write((char*)*&arm[i],sizeof(Armor));
            }
            out.close();
            break;
        }
        case 3:{
            for(int i=0;i<=k;i++){
                cout<<"\nID:";
                cout<<i<<endl;
                cout<<endl<<"Name:";
                std::setlocale(LC_ALL,"rus_rus.866");
                cout<<arm[i]->Get_name()<<endl;
                setlocale(LC_ALL,"Russian_Russia.1251");
                cout<<"Color:"<<arm[i]->Get_color()<<endl
                    <<"Type:"<<arm[i]->Get_type()<<endl;
                    cout<<"\nP_resist ";
                    cout<<arm[i]->Get_armor()<<endl;
                    cout<<"\nM_resist ";
                    cout<<arm[i]->Get_m_resist()<<endl;
                    cout<<"\nType_stat ";
                    cout<<arm[i]->Get_type_stat()<<endl;

            }
            break;
        }
        }
        break;
    }
    return 0;
    }
}

//ofstream out("Wearpon.bon",ios::binary|ios::out);
//wea = new Weapon("Ìå÷",2,10,0);
//cout<<wea->Get_name()<<endl;
//out.write((char*)*&wea,sizeof(*wea));
//out.close();
//ifstream in("Wearpon.bon",ios::binary|ios::in);
//arm=new Weapon("0",0,0,0);
//in.read((char*)*&arm,sizeof(*arm));
//in.close();
//cout<<arm->Get_name()<<endl;
