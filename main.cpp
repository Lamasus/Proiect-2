#include<iostream>
using namespace std;
class Farmacie
{
protected:
    string nume;
    int ang;
    int profit;
    int s_ang;
public:
    static int index;
    Farmacie()
    {
        ang=0;
        profit=0;
        s_ang=0;
    }
     ~Farmacie(){}
     int GetAng() const {return ang;}
     int GetProf() const {return profit;}
     string GetS(){return nume;}
     void SetAng(int angj,int prof,string f)
     {
     ang = angj;
     profit=prof;
     nume=f;
     index++;
     }
     virtual int sum(){}
     static int getIndex()
     {
         return index;
     }
};
class Farmacie_online : public Farmacie
{
protected:
    string web;
    unsigned viz;
    int disc;
public:
    Farmacie_online()
    {
        viz=0;
        disc=0;
    }
     ~Farmacie_online(){}
     unsigned GetViz() const {return viz;}
     int GetDisc() const {return disc;}
     string GetM(){return web;}
     void SetF(int viz1,int disc1,string m)
     {
     viz = viz1;
     disc=disc1;
     web=m;
     }
    void sum(unsigned &s)
    {
        s=s+GetViz();

    }
};
/*Farmacie_online::virtual void afiseaza()
     {
         cout<<"numele farmaciei este: ";


         cout<<endl;
         cout<<"farmacia are "<<ang<<" angajati"<<endl;
         cout<<"farmcia are un profit de "<<profit<<" pe luna"<<endl;
     }*/
int scadere(int a,int b)
{
    if(a-b<0)
       throw "Nu mai este loc de farmacii din tipul respectiv,va rugam adaugati un alt tip de farmacie :) sau iesiti";
    return (a-b);
}
int Farmacie::index=0;
int main()
{
    cout<<"Numarul initial de farmacii este: "<<Farmacie::getIndex()<<endl;
    Farmacie *v[50];
    Farmacie_online *a[50];
    Farmacie_online *ang[2];
    int j=1,nr,nr1,ok=0,k=1,z=0,x=0;
    unsigned s_viz=0;
    cout<<"introduceti numarul de farmacii normale,iar apoi numarul de farmacii online: ";
    cin>>nr>>nr1;
    cout<<endl;
    Farmacie *ptr;
    Farmacie * obj= static_cast<Farmacie *>(ptr);
    Farmacie_online * obj1;
    while(ok!=3 || j>nr || k==nr1)
    {
        cout<<"Apasati 1 pentru a insera farmaciile normale ,2 pentru Farmaciile online sau 3 pentru iesire ";
        cin>>ok;
        if(ok==1)
    {
        try{
            z=scadere(nr,j);
            cout<<"mai este loc de "<<z+1<<" farmacii normale "<<endl;
        }catch(const char *c)
        {
            cout<<c<<endl;
            j=nr+1;
        }

        for(j;j<=nr;j++)
        {
            int a,b;
            string k;
            if(j==1)
                cout<<"introduceti numarul de angajati, profitul  si numele primei farmacii "<<endl;
            else
                cout<<"introduceti numarul de angajati, profitul si numele celei dea "<<j<<"-a farmacii "<<endl;
            cin>>a>>b>>k;
            obj=new Farmacie;
            obj->SetAng(a,b,k);
            v[j]=obj;
        }
    }
    else
        if(ok==2)
        {
            try{
            x=scadere(nr1,k);
            cout<<"mai este loc de "<<x+1<<" farmacii online "<<endl;
        }catch(const char *c)
        {
            cout<<c<<endl;
            k=nr1+1;
        }
            for(k;k<=nr1;k++)
            {
                int c,d;
                string p;
                cout<<"introduceti vizitatorii discountul si pagina web a farmaciei online ";
                cin>>c>>d>>p;
                obj1=new Farmacie_online;
                obj1->SetF(c,d,p);
                a[k]=obj1;
                ang[1]=obj1;
                ang[1]->Farmacie_online::sum(s_viz);
                cout<<"a:= "<<s_viz<<endl;
            }
        }
    else
        if(ok==3)
            break;
    }
    if(j==1)
        cout<<"Nu exista farmacii normale "<<endl;
    else
        {
            cout<<"Afisarea farmaciilor normale:     "<<endl<<endl<<endl;
            for(j=1;j<=nr;j++)
                {
                cout<<"Farmacia_"<<j<<endl;
                cout<<"        Angajati: "<<v[j]->GetAng()<<' '<<endl;
                cout<<"        Profitul lunar: "<<v[j]->GetProf()<<"lei "<<endl;
                cout<<"        Numele: "<<v[j]->GetS()<<endl<<endl;
                }
            cout<<endl<<endl;
        }
    if(k==1)
        cout<<"Nu exista farmacii online "<<endl;
    else
    {
        cout<<"Afisarea farmaciilor online:     "<<endl<<endl<<endl;
        for(k=1;k<=nr1;k++)
            {
                cout<<"Farmacia_Online"<<k<<endl;
                cout<<"       Vizitatori online : "<<a[k]->GetViz()<<endl;
                cout<<"       Discountul online : "<<a[k]->GetDisc()<<"%"<<endl;
                cout<<"       Adresa Web:  www."<<a[k]->GetM()<<".com"<<endl<<endl;
            }
    }
    cout<<"Numarul de vizitatori online este "<<s_viz<<endl;
    cout<<"Numarul final de farmacii normale este: "<<Farmacie::getIndex();
    return 0;
}
