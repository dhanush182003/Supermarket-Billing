#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>

using namespace std;

class Bill
{
    private:
    string Item;
    int Rate,Quantity;
    public:
    Bill():Item(""),Rate(0),Quantity(0){}
    
    void setItem(string item){
        Item=item;
    }
    void setRate(int rate)
    {
        Rate=rate;
    }
    void setQuantity(int quant)
    {
        Quantity=quant;
    }

    string getItem()
    {
        return Item;
    }

    int getRate()
    {
        return Rate;
    }
     int getQuant()
     {
        return Quantity;
     }
};

void addItem(Bill b)
{
    bool close=false;
    while(!close)
    {
        system("cls");
        int choice;
        cout<<"\t****************************"<<endl;
        cout<<"\t1.Add."<<endl;
        cout<<"\t2.Close."<<endl;
        cout<<"\t****************************"<<endl;
        cout<<"\tenter your choice :";
        cin>>choice;


        if(choice==1)
        {
            system("cls");
            string item;
            int rate,quant;
            cout<<"\tenter item name   :";
            cin>>item;
            b.setItem(item);

            cout<<"\tenter rate of item:";
            cin>>rate;
            b.setRate(rate);

            cout<<"\tenter quantity    :";
            cin>>quant;
            b.setQuantity(quant);

            ofstream out("E:\\Bill.txt",ios::app);
            if(!out)
            {
                cout<<"\tError:File cannot open!"<<endl;
            }
            else
            {
                out<<"\t"<<b.getItem()<<" : "<<b.getRate()<<" : "<<b.getQuant()<<endl<<endl;
            }
            out.close();
            cout<<endl<<endl;
            cout<<"\t***************************"<<endl;
            cout<<"\t* Item added successfully *"<<endl;
            cout<<"\t***************************"<<endl;
            Sleep(3000);

        }
        else if(choice==2)
        {
            system("cls");
            close=true;
            cout<<"\tBack to main menu!"<<endl;
            Sleep(3000);
        }
    }
}

void printbill()
{
    int count=0;
    bool close=false;
    while(!close)
    {
        system("cls");
        int choice;
        cout<<"\t1.Add bill."<<endl;
        cout<<"\t2.close session."<<endl;
        cout<<"\t\tenter choice :";
        cin>>choice;

        if(choice==1)
        {
            string item;
            int quant;
            cout<<"\tenter item: ";
            cin>>item;
            cout<<"enter quantity :";
            cin>>quant;

            ifstream in("E:\\Bill.txt");
            ofstream out("E:\\Bill Temp.txt");

            string line;
            bool found=false;
            while(getline(in,line))
            {
                stringstream ss(line);
                string itemName;
                int itemRate,itemQuant;
                char delimeter;
                ss>>itemName>>delimeter>>itemRate>>delimeter>>itemQuant;

                if(item == itemName)
                {
                    found=true;
                    if(quant<=itemQuant)
                    {
                        int amount=itemRate*quant;
                        cout<<"\t Item | Rate | quantity | Amount"<<endl;
                        cout<<"\t"<<itemName<<"\t "<<itemRate<<"\t "<<itemQuant<<"\t "<<amount<<endl;
                        int newQuant=itemQuant-quant;
                        itemQuant=newQuant;
                        count+=amount;

                        out<<"\t"<<itemName<<" : "<<itemRate<<" : "<<itemQuant<<endl<<endl;
                    }
                    else{
                        cout<<"\tSorry,"<<item<<" Ended!"<<endl;
                    }
                }
                else
                {
                    out<<line<<endl;
                }
            }
            if(!found)
            {
                cout<<"\tItem not available!"<<endl;
            }
            out.close();
            in.close();
            remove("E:\\Bill.txt");
            rename("E:\\Bill Temp.txt","E:\\Bill.txt");
        }
        else if(choice==2)
        {
            close=true;
            cout<<"\tcounting total bill...............!"<<endl;
        }
        Sleep(3000);
    }
    system("cls");
    cout<<endl<<endl;
    cout<<"\t****************************************"<<endl;
    cout<<"\t Total Bill ----------------------: "<<count<<endl;
    cout<<"\t****************************************"<<endl;
    cout<<"\tThanks for shopping!!"<<endl;
    Sleep(5000);
}


int main()
{
    Bill b;
    bool exit1=false;

    while(!exit1)
    {
        system("cls");
        int val;
        cout<<"\t****************************************"<<endl;
        cout<<"\t WElcome to super market billing system"<<endl;
        cout<<"\t****************************************"<<endl;
        cout<<"\t\t1.Add Item."<<endl;
        cout<<"\t\t2.Print Bill"<<endl;
        cout<<"\t\t3.Exit"<<endl;
        cout<<"\t****************************************"<<endl;
        cout<<"\t\tEnter Choice:";
        cin>>val;

        if(val==1)
        {
            system("cls");
            addItem(b);
            Sleep(3000);
        }
        else if(val==2)
        {
            printbill();
        }
        else if(val==3)
        {
            system("cls");
            exit1=true;
            cout<<endl;
            cout<<"\t************"<<endl;
            cout<<"\t*good luck!*"<<endl;
            cout<<"\t************"<<endl;
            Sleep(3000);
        }
        
    }
}
