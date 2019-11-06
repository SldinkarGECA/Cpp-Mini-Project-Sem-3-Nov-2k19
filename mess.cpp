#include<iostream>
#include<conio.h>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<conio.h>
#include<windows.h>

#include <typeinfo>
using namespace std;



class Mess
{
public:
    Mess();
    void show();
    void allItems();
    void addNewItem();
    int searchById(int);
    void showQuantity(int);
    int checkQuantity(int,int);
    void addNewSale(int,int);
};
string name;
int choice;
int item, quantity,price=0;
int main()
{
    system("cls");
    system("title Mess Management Program");
    system("mode con: cols=140 lines=30");
    system("color 0f");
    Mess Mess;
    again:
    Mess.show();

    cin>>choice;
    if(choice == 1)
    {
        cout<<"Enter you  Good name: ";
        cin>>name;
        cout<<endl;
        system("cls");
        bb:
        Mess.allItems();
        cout<<endl;
        mm:
        cout<<"Hello "<<name;
        cout<<"\nWhat do you want to buy?. Enter Number of the item: ";

        cin>>item;
        if(item<=7)
        {
        if(Mess.searchById(item)==0)
        {
            cout<<"This item is not present\n";
            goto mm;
        }
        customer:
        Mess.showQuantity(item);
        cout<<"\nEnter quantity of the item: ";
        cin>>quantity;
        if(Mess.checkQuantity(item, quantity)==1)
        {
            Mess.addNewSale(item, quantity);
            goto again;
        }
        else
        {
            cout<<quantity<<" Quantity is not present in our Mess. Try again";
            goto customer;
        }
        }
        else
        {
            system("cls");
            cout<<"\t\t\tPlease Enter Proper Number!!!";
                Sleep(3000);
            goto bb;
        }
    }
    else if(choice == 2)
    {
        Mess.allItems();
        goto again;
    }
    else if(choice == 3)
    {
        Mess.addNewItem();
        goto again;
    }
    else if(choice == 4)
    {
        exit(0);
    }
    return 0;
}
Mess::Mess()
{
    cout<<"\n\n\n____________Welcome!!!____________\n";
}
void Mess::show()
{
    cout<<"\n\n";
    cout<<"__________________________________\n";
    cout <<"|  Mess Management System        |\n";
    cout <<"|        1.BUY AN ITEM           |\n";
    cout <<"|          2.MENU CARD           |\n";
    cout <<"|        3.ADD NEW ITEM          |\n";
    cout <<"|            4.EXIT              |\n";
    cout<<"----------------------------------\n";
    cout<<"Enter your choice: ";
}
void Mess::allItems()
{
    system("cls");
    cout<<"__________________________________\n";
    cout<<"____________MENU CARD_____________\n\n";
    cout<<"\nWhat would you like to order?\n";
    cout<<"   Item        |        Price \n";
    cout<<"1:CHAPATI      |  05 Rs. per piece\n";
    cout<<"2:RICE         |  10 Rs. per plate\n";
    cout<<"3.DAL          |  10 Rs. per plate\n";
    cout<<"4.ALOO MATAR   |  30 Rs. per plate\n";
    cout<<"5.PANEER       |  50 Rs. per plate\n";
    cout<<"6.PAPAD        |  08 Rs. per piece\n";
    cout<<"_______Today's SPECIAL Menu_______\n";
    cout<<"7.GULAB JAMUN  |  40 Rs. per plate\n\n";
    cout<<"__________________________________\n";
    Sleep(3000);
    system("cls");
}
void Mess::addNewItem()
{
    Mess Mess;
    system("cls");
    t:
    Mess.show();
    system("cls");
    mnn:
    cout<<"_____________________________________________\n";
    cout<<"___________Total BILL: "<<price<<"___________"<<endl;
    Mess.allItems();
    int id;
    int quantity;
    mm:
    cout<<"Hello "<<name;
    cout<<"\nWhat do you want to add?. Enter Number of the item: ";

        cin>>id;
        if (id<=7)
        {
        if(Mess.searchById(id)==0)
        {
            cout<<"This item is not present\n";
            goto x;
        }
        customer:
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\tTotal BILL: "<<price;
        Mess.showQuantity(id);
        cout<<"\nEnter quantity of the item: ";
        cin>>quantity;
        if(Mess.checkQuantity(id, quantity)==1)
        {
            Mess.addNewSale(id, quantity);
            goto x;
        }
        else
        {
            cout<<quantity<<" Quantity is not present in our Mess. Try again";
            goto customer;
        }
        x:
            cout<<"\nDo you want to add more?. Enter (Y/N) ";
            char ch;
            cin>>ch;
            if (ch=='y' || ch=='Y')
                goto t;
            else
            {
             cout<<"\n\n\n\n\n\n\n";
             cout<<"_________Total BILL: "<<price<<"_________"<<endl;
             cout<<"_________Thank you "<<name<<" for shopping!_________\n";
             cout<<"____________Do visit again!!_____________\n";
             Sleep(5000);
             system("cls");
             return;

            }
        }
        else{
                cout<<"\t\t\tPlease enter proper number!!!";
                Sleep(3000);
            goto mnn;
        }
}
void Mess::addNewSale(int item, int quantity)
{
    cout<<"__________________________________\n";
    int price1;
    string item_name;
     system("cls");
    if(quantity<=10)
    {
    cout<<"Preaparing Bill\n";
    Sleep(2000);
    if(item==1)
    {
    item_name="CHAPATI ";
    }
    else if(item==2)
    {   item_name="RICE";
    }
    else if(item==3)
    {   item_name="DAL ";
    }
    else if(item==4)
    {   item_name="ALOO MATAR ";
    }
    else if(item==5)
    {   item_name="PANEER";
    }
    else if(item==6)
    {   item_name="PAPAD ";
    }
    else if(item==7)
    {   item_name="GULAB JAMUN ";
    }
    if(item==1)
    {
    cout<<"You Bought item "<<item_name<<" and quantity of "<<quantity<<" items";
     price=price+5*quantity;
     price1=5*quantity;
        cout<<"Price is "<<price1;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\tTotal BILL: "<<price;
    }
    else if(item==2)
    {  cout<<"You Bought item "<<item_name<<" and quantity of "<<quantity<<" items";
     price=price+10*quantity;
     price1=10*quantity;
        cout<<"Price is "<<price1;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\tTotal BILL: "<<price;
    }
    else if(item==3)
    {   cout<<"You Bought item "<<item_name<<" and quantity of "<<quantity<<" items";
     price=price+10*quantity;
     price1=10*quantity;
        cout<<"Price is "<<price1;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\tTotal BILL: "<<price;
    }
    else if(item==4)
    {   cout<<"You Bought item "<<item_name<<" and quantity of "<<quantity<<" items";
     price=price+30*quantity;
     price1=30*quantity;
        cout<<"Price is "<<price1;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\tTotal BILL: "<<price;
    }
    else if(item==5)
    {   cout<<"You Bought item "<<item_name<<" and quantity of "<<quantity<<" items";
     price=price+50*quantity;
     price1=50*quantity;
        cout<<"Price is "<<price1;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\tTotal BILL: "<<price;
    }
    else if(item==6)
    {   cout<<"You Bought item "<<item_name<<" and quantity of "<<quantity<<" items";
     price=price+8*quantity;
     price1=8*quantity;
        cout<<"Price is "<<price1;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\tTotal BILL: "<<price;
    }
    else if(item==7)
    {   cout<<"You Bought item "<<item_name<<" and quantity of "<<quantity<<" items";
     price=price+40*quantity;
     price1=40*quantity;
        cout<<"Price is "<<price1;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\tTotal BILL: "<<price;
    }
    }
    else{
        cout<<"\t\t\tPlease enter proper quantity!!!";
                Sleep(3000);
                system("cls");

    }
}



void Mess::showQuantity(int i)
{
    system("cls");
    cout<<"\n\n\n\n\n";
    cout<<"Checking Quantity";
    cout<<" . ";
    Sleep(1000);
    cout<<". ";
    Sleep(1000);
    cout<<". ";
    Sleep(1000);
    cout<<". ";
    Sleep(1000);
    cout<<". ";
    Sleep(1000);
    cout<<"\n";
    cout<<"__________________________________\n";
    cout<<"    Item       |  Quantity \n";

    if(i==1)
    cout<<"1:CHAPATI      |  10 plates\n";
    else if(i==2)
    cout<<"2:RICE         |  10 plates\n";
    else if(i==3)
    cout<<"3.DAL          |  10 plates\n";
    else if(i==4)
    cout<<"4.ALOO MATAR   |  10 plates\n";
    else if(i==5)
    cout<<"5.PANEER       |  10 plates\n";
    else if(i==6)
    cout<<"6.PAPAD        |  10 plates\n";
    else if(i==7)
    cout<<"7.GULAB JAMUN  |  10 plates\n\n";
    cout<<"__________________________________\n";

}


int Mess::searchById(int id)
{
    if(id<1 && id>6)
    return 0;
    else
    return 1;
}
int Mess::checkQuantity(int item, int quantity)
{
    if (quantity>20)
    return 0;
    else return 1;
}
