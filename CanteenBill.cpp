/* MINI PROJECT MADE BY ABHIJEET ARJUN KUMBHAR*/ 

#include<iostream>
#include<iomanip>
#include<conio.h>
#include<stdio.h>
#include<fstream>
using namespace std;
fstream file,file1;
class product
{
    int pno;
    string name;
    float price,qty,tax,dis;
    public:
        void create();
        void show();
        void write();
        void display();
        void admin();
        void search(int n);
        void modify(int n);
        void del(int n);
        void order();
        void menu();              
};
void product ::create()
{
    cout<<"\n\n Please Enter The Product No. of The Product : ";
    cin>>pno;
    cout<<"\n\n Please Enter The Name No. of The Product : ";
    cin>>name;
    cout<<"\n\n Please Enter The Price of The Product : ";
    cin>>price;
    cout<<"\n\n Plese Enter The Discount(%) : ";
    cin>>dis;
}
void product ::show()
{
    cout<<"\nThe Product No. of The Product:"<<pno;
    cout<<"\nThe Name of The Product :"<<name;
    cout<<"\nThe Price of The Product :"<<price;
    cout<<"\nDiscount:"<<dis<<"%";
}
void product ::write()
{
    file.open("shop.txt",ios::out|ios::app);
    create();
    file<<" "<<pno<<" "<<name<<" "<<price<<" "<<dis<<" ";
    file.close();
    cout<<"\n\nThe Product Has Been Created ";
    getch();
}
void product ::display()
{
    system("cls");
    cout<<"\n\n\t\tProduct Menu!!!\n\n";
    file.open("shop.txt",ios::in);
    if(!file)
    admin();
    file>>pno>>name>>price>>dis;
    while(!file.eof())
    {
        show();
        cout<<"\n\n=========================================";
        file>>pno>>name>>price>>dis;
    }
    file.close();
    getch();
}
void product ::admin()
{
    system("cls");
    int choice,num;
    cout<<"\tadmin menu"<<endl;
    cout<<"\t1.create product"<<endl;
    cout<<"\t2.display all product"<<endl;
    cout<<"\t3.search product"<<endl;
    cout<<"\t4.modify product"<<endl;
    cout<<"\t5.delete product"<<endl;
    cout<<"\t6.back to menu"<<endl;
    cout<<"\tEnter your choice :";
    cin>>choice;
    switch(choice)
    {
        case 1:
            system("cls");
            write();
            break;
        case 2:
            display();
            break;
        case 3:
            system("cls");
            cout<<"Please enter the product no to search : ";
            cin>>num;
            search(num);
            break;
        case 4:
            system("cls");
            cout<<"Please enter the product no to modify : ";
            cin>>num;
            modify(num);
            break;
        case 5:
            system("cls");
            cout<<"Please enter the product no to delete : ";
            cin>>num;
            del(num);
            break;
        case 6:
            break;
            
        default:
            cout<<"Invalid record";       
    }

}
void product ::search(int n)
{
    int found=0;
    file.open("shop.txt",ios::in);
    if(!file)
    admin();
    file>>pno>>name>>price>>dis;
    while(!file.eof())
    {
        if(pno == n)
        {
            system("cls");
            show();
            found=1;
        }
        file>>pno>>name>>price>>dis;
    }
    file.close();
    if(found == 0)
    cout<<"\n\nrecord not exit";
    getch();
}
void product ::modify(int n)
{
    int found=0;
    system("cls");
    cout<<"\n\n\tTo Modify";
    file.open("shop.txt",ios::in);
    if(!file)
    admin();
    file1.open("shop1.txt",ios::out|ios::app);
    file>>pno>>name>>price>>dis;
    while(!file.eof())
    {
        if(pno == n)
        {
            show();
            cout<<"\n\n Please Enter The New Detail";
            create();
            file1<<" "<<pno<<" "<<name<<" "<<price<<dis<<" ";
            cout<<"\n\n\tRecord Updated";
            found=1;
        }
        else
        file1<<" "<<pno<<" "<<name<<" "<<price<<" "<<dis<<" ";
        file>>pno>>name>>price>>dis;
    }
    file.close();
    file1.close();
    remove("shop1..txt");
    rename("shop1.txt","shop.txt");
    if(found==0)
    cout<<"\n\n Record Not Found ";
    getch();
}
void product ::del(int n)
{
    int found=0;
    file.open("shop.txt",ios::in);
    if(!file)
    admin();
    file1.open("shop1.txt",ios::out);
    file>>pno>>name>>price>>dis;
    while(!file.eof())
    {
        if(pno == n)
        {
            cout<<"\n\n\t Record Deleted";
            found=1;
        }
        else
        file1<<" "<<pno<<" "<<name<<" "<<price<<" "<<dis<<" ";
        file>>pno>>name>>price>>dis;
    }
    file.close();
    file1.close();
    remove("shop.txt");
    rename("shop1.txt","shop.txt");
    if(found==0)
    cout<<"\n\n Record Not Found ";
    getch();
}
void product::menu()
{
    system("cls");
    file.open("shop.txt",ios::in);
    cout<<"PRODUCT MENU"<<endl;
    cout<<"=============================="<<endl;
    cout<<"P.NO\t\tNAME\t\tPRICE\n";
    cout<<"=============================="<<endl;
    file>>pno>>name>>price;
    while(!file.eof());
    {
        cout<<pno<<"\t\t"<<name<<"\t\t"<<price<<endl;
        file>>pno>>name>>price;
    }
    file.close();
    getch();
}
void product::order()
{
    int order_arr[50],quan[50],c=0;
    float amt=0,damt=0,total=0;
    char ch;
    file.open("shop.txt",ios::in);
    if(file)
    {
        file.close();
        menu();
        // display();
        cout<<endl<<"************************"<<endl;
        cout<<"PLACE YOUR ORDER"<<endl;
        cout<<"************************"<<endl;
        do
        {
            cout<<"Enter the product no. Of the product "<<endl;
            cin>>order_arr[c];
            cout<<"Quantity in number :"<<endl;
            cin>>quan[c];
            c++;
            cout<<"Do you want to order another product ";
            cin>>ch;
        }while(ch=='y' || ch=='Y');
        cout<<"Thank you for placing order !!!";
        cout<<"*************************************";
        cout<<"\n no \t name \t Quantity \tPrice \tAmount \t amount with discount"<<endl;
        for(int x=0;x<=c;x++)
        {
            file.open("shop.txt",ios::in);
            file>>pno>>name>>price>>dis;
            while(!file.eof())
            {
                if(pno == order_arr[x])
                {
                    amt=price*quan[x];
                    damt=amt-(amt/100*dis);
                    cout<<"\n"<<order_arr[x]<<"\t"<<name<<"\t"<<quan[x]<<"\t"<<price<<"\t"<<amt<<"\t"<<damt;
                    total +=damt;
                }
                file>>pno>>name>>price>>dis;
            }
            file.close();
        }
        cout<<"\t\t\t\t\t\t\t\t\tTOTAL : "<<total;
        getch();
    }
}
int main()
{
    product p;
    start:
        int choice;
        system("cls");
        cout<<"MAIN MENU\n";
        cout<<"1.CUSTOMER"<<endl;
        cout<<"2.ADMIN"<<endl;
        cout<<"3.EXIT"<<endl;
        cout<<"Enter choice\n"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                system("cls");
                p.order();
                getch();
                break;
            case 2:
                p.admin();
                break;
            case 3: 
                exit(0);
            default:
                cout<<"Invalid Input";
        }
        goto start;
        return 0;
}