#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
#include<windows.h>
#include<ctime>
#include<string>
#include <chrono>
using namespace std;

//-------------------------------blink Text-------------------
void blinkText(const string& text, int duration) {
    const int blink_interval = 500; // blink every 500 ms
    const int num_blinks = duration / blink_interval / 2; // calculate number of blinks
    
    for (int i = 0; i < num_blinks; i++) {
        cout << "\r" << text;
        Sleep(blink_interval);
        cout << "\r" << string(text.length(), ' ');
        Sleep(blink_interval);
    }
    
    cout << "\r" << text << std::endl;
}
//------------------------------------Time---------------------
int timecurr(){
    time_t now=time(0);
    char*timecu = ctime(&now);
    cout<<timecu;
    return 0;
}
//-------------------------------------color--------------------------------
int col(int a)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    return SetConsoleTextAttribute(h, a);
}
//--------------------------------------------------------customer_detail----------------------------------------------
class customer_detail{
    private:
        int cust_id;
        long  cust_phone;
        string cust_name;
        string cust_address;
    public:
        void get_cust();
        void put_cust();
        int get_cust_id(){
            return cust_id;
        }
};
void customer_detail::get_cust(){
    col(5);
    cout<<"FILL THE REQUIDEMENT DETAIL"<<endl;
    col(6);
    cout<<"CREATE UNIQUE ID:"<<endl;
    col(2);
    cin>>cust_id;
    col(6);
    cout<<"NAME : "<<endl;
    col(2);
    cin>>cust_name;
    col(6);
    cout<<"PHONE NUMBER"<<endl;
    col(2);
    cin>>cust_phone;
    col(6);
    cout<<"ADDRESS"<<endl;
    col(2);
    cin>>cust_address;
}
void customer_detail::put_cust(){
    cout<<setw(6)<<cust_id<<setw(15)<<cust_name<<setw(12)<<cust_phone<<setw(15)<<cust_address<<endl;

}
//-------------------------------------------Hospital_Detail-----------------------------------------------------------
class Hospital_detail{
    private:
        int hospn_code;
        int hospid;
        long hosp_phone;
        string hosp_name;
        string hosp_address;
    public:
        void get_hosp();
        void put_hosp();
        int get_hosp_pin(){
            return hospn_code;
        }
        int get_hospid(){
            return hospid;
        }
        int hosp_modify(char na[100],int ph,int pin,char ad[100])
        {
            hosp_phone=ph;
            hosp_name=na;
            hosp_address=ad;
            hospn_code=pin;
            
        }
};
void Hospital_detail::get_hosp(){
    cout<<"This form is for hospital management only !"<<endl;
    cout<<"NAME OF THE HOSPITAL : ";
    cin>>hosp_name;
    cout<<"hospital area pin code : ";
    cin>>hospn_code;
    cout<<"hospital Address :";
    cin>>hosp_address;
    cout<<"hospital phone number :";
    cin>>hosp_phone;
    cout<<"create a id for hospital :";
    cin>>hospid;
    
}
void Hospital_detail::put_hosp(){
    cout<<setw(1)<<hospn_code<<setw(20)<<hospid<<setw(16)<<hosp_name<<setw(20)<<hosp_address<<setw(20)<<hosp_phone<<endl;

}
//--------------------------------------------Ambulance_detail--------------------------------------------------
class Ambulance_detail{
    private:
        int ambpn_code;
        int  ambid;
        string amb_name;
        long amb_phone;
        string amb_drive;
    public:
        void get_ambul();
        void put_ambul();
        int get_ambpn_code(){
            return ambpn_code;
        }
        int  get_ambid(){
            return ambid;
        }
        int amb_modify(char na[100],int ph,int pin)
        {
            amb_drive=na;
            amb_phone=ph;
            ambpn_code=pin;
        }

};
void Ambulance_detail::get_ambul(){
    col(5);
    cout<<"This form is for Ambulance Driver"<<endl;
    col(6);
    cout<<"Name : "<<endl;
    col(2);
    cin>>amb_drive;
    col(6);
    cout<<"PHONE NUMBER"<<endl;
    col(2);
    cin>>amb_phone;
    col(6);
    cout<<"your address pin"<<endl;
    col(2);
    cin>>ambpn_code;
    col(6);
    cout<<"Your Ambulance Type "<<endl;
    col(2);
    cin>>amb_name;
    col(6);
    cout<<"vehcial plate number"<<endl;
    col(2);
    cin>>ambid;
}
void Ambulance_detail::put_ambul(){
    cout<<setw(1)<<ambpn_code<<setw(17)<<ambid<<setw(18)<<amb_name<<setw(10)<<amb_drive<<setw(12)<<amb_phone<<endl;
}
//-----------------------------------------------Function Declartion--------------------------------------------------------

void create_cust();
void login_cust();
void create_ambul();
void show_amb();
void show_amb_log();
void create_hosp();
void show_hosp();
void admin_ambl_showall();
void admin_hosp_showall();
void admin_ambl_delete();
void admin_hosp_delete();
void admin_hosp_modify();
void admin_ambl_modify();
customer_detail st;
Ambulance_detail ul;
Hospital_detail pi;
fstream cust_file,amb_file,hosp_file;

//---------------------------------------Main program---------------------------------------------------
int main(){
        int cust_choice,login_choice,admin_choice;
        //------------------------------------admin password---------------------------------------
        int password;
        auto now = chrono::system_clock::now();
        time_t current_time = chrono::system_clock::to_time_t(now);
        struct tm* ptm = localtime(&current_time);
        int hours = ptm->tm_hour*100;
        int minutes = ptm->tm_min;
        int pass=hours + minutes;
        //--------------------------------------------------------------------------------------------
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;col(6);
        string text1 = "                     | POWERED BY : TECH-ERA |";
        blinkText(text1,3000);
        cout<<" "<<endl;
        cout<<" "<<endl;
        cout<<"  "<<endl;
        cout<<" "<<endl;
        cout<<"  "<<endl;
        cout<<" "<<endl;
        cout<<" "<<endl;
    do{
        col(4);
        cout<<"⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜"<<endl;
        cout<<"⬜                                                                ⬜"<<endl;
        cout<<"⬜";col(6);cout<<"          WELCOME TO AMBULANCE MANAGEMENT SYSTEM   ";col(4); cout<<"             ⬜"<<endl;col(4);
        cout<<"⬜                                                                ⬜"<<endl;
        cout<<"⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜"<<endl;
        cout<<endl;col(7);
        string text2="  DONATE BLOOD SAVE LIFE          CAMP-25/11/23(AIIMS-DELHI)";
        blinkText(text2,3000);
        cout<<endl;
        cout<<"             ";col(5);cout<<"|";col(3);cout<<"PRESS 1";col(5);cout<<"|";cout<<"                          ";col(5);cout<<"|";col(3);cout<<"PRESS 2";col(5);cout<<"|"<<endl;
        cout<<"             ";col(5);cout<<"|";col(2);cout<<" LOGIN ";col(5);cout<<"|";cout<<"                          ";col(5);cout<<"|";col(2);cout<<"CREATE ";col(5);cout<<"|"<<endl;
        col(7);
        int entry,book_amb;
        long log_entry,log_admi,log_amb,log_hosp;
        cin>>entry;
        switch (entry){
            case 1:
                do{
                    login_cust();
                    cout<<endl;
                    col(7);
                        cin>>log_entry;
                        switch (log_entry){
                            case 1:
                                show_amb();
                                cout<<endl;
                                cout<<endl;
                                cout<<"----------------------FOR BOOK YOUR ANBULANCE-------------PRESS 1------------ "<<endl;
                                cout<<"----------------------FOR COME BACK TO HOME PAGE--------- PRESS other -------- "<<endl;col(7);
                                cin>>book_amb;
                                if(book_amb==1){
                                    show_amb_log();
                                }
                                break;
                            case 2:
                                show_hosp();
                                break;
                            case 3:
                                create_ambul();
                                break;
                            case 4:
                                create_hosp();
                                break;
                            case 9:
                            //-----------------passcode----------
                                col(4);
                                cout<<"Enter the Admin password : ";
                                col(7);
                                cin>>password;
                            if(pass==password){
                            //------------------------------------------
                                    do{
                                        col(2);
                                            cout<<"---------------------------Admin Access Taken------------------------------------"<<endl;col(6);
                                            cout<<"             |PRESS 1|                          |PRESS 2 |"<<endl;
                                            cout<<"            |AMBULANCE|                        |HOSTIPAL|"<<endl;
                                            cout<<"             |ACCESS |                          | ACCESS |"<<endl;col(2);
                                            cout<<"----------------------------------------------------------------------------------"<<endl;col(7);
                                            cin>>log_admi;
                                            switch (log_admi)
                                            {
                                            case 1:col(2);
                                                cout<<"---------------------------Ambulance Access Taken------------------------------------------"<<endl;col(6);
                                                cout<<"             |PRESS 1|              |PRESS 2|             |PRESS 3|          |PRESS 4|"<<endl;
                                                cout<<"             |  FOR  |              |  FOR  |             |  FOR  |          |  FOR  |"<<endl;
                                                cout<<"          |  SHOW ALL  |            |DELETE |             |MODIFY |           | ADD |"<<endl;
                                                cout<<"            |AMBULANCE|            |AMBULANCE|           |AMBULANCE|         |AMBULANCE|"<<endl;
                                                cout<<"             |RECORD|                |RECORD|              |RECORD|          |RECORD|"<<endl;col(2);
                                                cout<<"-------------------------------------------------------------------------------------------\n";col(7);
                                                    cin>>log_amb;
                                                    switch (log_amb)
                                                    {
                                                    case 1:
                                                        admin_ambl_showall();
                                                        break;
                                                    case 2:
                                                        admin_ambl_showall();
                                                        admin_ambl_delete();
                                                        break;
                                                    case 3:
                                                        admin_ambl_showall();
                                                        admin_ambl_modify();
                                                        break;
                                                    case 4:
                                                        admin_ambl_showall();
                                                        create_ambul();
                                                        break;
                                                    default:
                                                        break;
                                                    }
                                                break;
                                            case 2:col(2);
                                                cout<<"---------------------------Hospital Access Taken------------------------------------------"<<endl;col(6);
                                                cout<<"             |PRESS 1|              |PRESS 2|             |PRESS 3|          |PRESS 4|"<<endl;
                                                cout<<"             |  FOR  |              |  FOR  |             |  FOR  |          |  FOR  |"<<endl;
                                                cout<<"          |  SHOW ALL  |            |RECORD |             |MODIFY |           | ADD |"<<endl;
                                                cout<<"             |HOSPITAL|             |HOSPITAL|            |HOSPITAL|        |HOSPITAL|"<<endl;
                                                cout<<"             |RECORD|                |RECORD|              |RECORD|          |RECORD|"<<endl;col(2);
                                                cout<<"-------------------------------------------------------------------------------------------\n";
                                                    cin>>log_hosp;
                                                    switch (log_hosp)
                                                    {
                                                    case 1:
                                                        admin_hosp_showall();
                                                        break;
                                                    case 2:
                                                        admin_hosp_showall();
                                                        admin_hosp_delete();
                                                        break;
                                                    case 3:
                                                        admin_hosp_showall();
                                                        admin_hosp_modify();
                                                        break;
                                                    case 4:
                                                        admin_hosp_showall();
                                                        create_hosp();
                                                        break;
                                                    default:
                                                        break;
                                                    }
                                                break;
                                            default:
                                            col(4);
                                                cout<<"YOU HAVE ENTER WRONG DIGIT"<<endl;
                                                break;
                                            }  //for admin use only 
                                            // admin_ambl();
                                            cout<<"for come back to ADMIN  page press 1 : ";col(7);
                                            cin>>admin_choice;
                                        }while(admin_choice==1);
                                break;
                            }
                            default:col(4);
                                cout<<"YOU HAVE ENTER WRONG DIGIT"<<endl;
                                break;
                        }
                        cout<<"for come back to LOGIN page press 1 : ";col(7);
                        cin>>login_choice;
                }while(login_choice==1);
                break;
            case 2:
                create_cust();
            break;
        default:col(4);
            cout<<"invalid opration";
            break;
        }
        col(4);
        cout<<"for come back <- <- to home page press 1 : ";
        col(7);
        cin>>cust_choice;
    }while(cust_choice==1);
        return 0;
}
// ----------------------------------------Function Defination--------------------------
// -----------------------------------------To Create new user-------------------------
void create_cust(){
    cust_file.open("custo.dat",ios::app|ios::binary);
    st.get_cust();
    cust_file.write((char*)&st,sizeof(st));
    cust_file.close();
    col(9);
    cout<<"you have successfully create you account"<<endl;
    col(2);
    cout<<"------------------------------------------------------------------------"<<endl;
}
// ----------------------------------login to the page--------------------------------
void login_cust(){
    int no,flag=0;
    cust_file.open("custo.dat",ios::in|ios::binary);
    if(!cust_file){
        col(4);
        cout<<"--------------------Server Error-----------------------------------------\n";
        exit(0);
    }
    else{
        col(6);
        cout<<"Please enter your Id ";
        col(7);
        cin>>no;
        cust_file.read((char*)&st,sizeof(st));
        while(!cust_file.eof())
        {
            if(no == st.get_cust_id())
            {
                flag=1;
                col(2);
                cout<<"--------------------------------------------------------------------------"<<endl;
                col(4);
                cout<<"⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜"<<endl;
                cout<<"⬜                                                                ⬜"<<endl;
                cout<<"⬜";col(6);cout<<"                       LOGIN SUCCESSFULLY   ";col(4); cout<<"                    ⬜"<<endl;
                cout<<"⬜";col(6);cout<<"                              NOW   ";col(4); cout<<"                            ⬜"<<endl;
                cout<<"⬜";col(6);cout<<"                        USE OUR SERVICE   ";col(4); cout<<"                      ⬜"<<endl;
                col(4); 
                cout<<"⬜                                                                ⬜"<<endl;
                cout<<"⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜"<<endl;
                cout<<endl;
                col(7);
                cout<<"                                        login at :      ";timecurr();
                cout<<endl;
                col(5);
                cout<<"Your Id \t Name \t Phone No \t Adress "<<endl;
                col(7);
                st.put_cust();
                cout<<endl;
                cout<<" ";col(5);cout<<"|";col(3);cout<<"PRESS 1";col(5);cout<<"|";cout<<"           ";col(5);cout<<"|";col(3);cout<<"PRESS 2";col(5);cout<<"|";cout<<"           ";col(5);cout<<"|";col(3);cout<<"PRESS 3";col(5);cout<<"|";cout<<"           ";col(5);cout<<"|";col(3);cout<<"PRESS 4";col(5);cout<<"|"<<endl;
                cout<<" ";col(5);cout<<"|";col(2);cout<<"  FOR  ";col(5);cout<<"|";cout<<"           ";col(5);cout<<"|";col(2);cout<<"  FOR  ";col(5);cout<<"|";cout<<"           ";col(5);cout<<"|";col(2);cout<<"  FOR  ";col(5);cout<<"|";cout<<"           ";col(5);cout<<"|";col(2);cout<<"  FOR  ";col(5);cout<<"|"<<endl;
                cout<<" ";col(5);cout<<"|";col(6);cout<<" NEAR  ";col(5);cout<<"|";cout<<"           ";col(5);cout<<"|";col(6);cout<<" NEAR  ";col(5);cout<<"|";cout<<"           ";col(5);cout<<"|";col(6);cout<<"DRIVER ";col(5);cout<<"|";cout<<"          ";col(5);cout<<"|";col(6);cout<<"HOSPITAL";col(5);cout<<"|"<<endl;
                cout<<"";col(5);cout<<"|";col(6);cout<<"AMBULANCE";col(5);cout<<"|";cout<<"         ";col(5);cout<<"|";col(6);cout<<"HOSPITAL";col(5);cout<<"|";cout<<"           ";col(5);cout<<"|";col(6);cout<<"  JOB  ";col(5);cout<<"|";cout<<"           ";col(5);cout<<"|";col(6);cout<<"  USE  ";col(5);cout<<"|"<<endl;
                col(2);
                cout<<"--------------------------------------------------------------------------"<<endl;
                
            }
            cust_file.read((char*)&st,sizeof(st));
        }
        if(flag==0)
        {
            cout<<"No Item found";
        }
    }
    cust_file.close();
    }
    //-----------------------------------------------For Ambulance Job------------------------------------------------
void create_ambul(){
    amb_file.open("ambul.dat",ios::app|ios::binary);
    ul.get_ambul();
    amb_file.write((char*)&ul,sizeof(ul));
    amb_file.close();
    col(9);
    cout<<"you have successfully become driver"<<endl;
    col(2);
    cout<<"------------------------------------------------------------------------"<<endl;
}
//-------------------------------------------------List of Ambulance in your Area-----------------------------------------------------
void show_amb(){
    int no,flag=0;
    amb_file.open("ambul.dat",ios::in|ios::binary);
    if(!amb_file){
        col(4);
        cout<<"--------------------Server Error-----------------------------------------\n";
        exit(0);
    }
    else{
        col(6);
        cout<<"enter your area pin : ";
        col(7);
        cin>>no;
        amb_file.read((char*)&ul,sizeof(ul));
        col(2);
        cout<<"----------------------------------------------------------------------------------\n";
                        col(4);
                        cout<<"⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜"<<endl;
                        cout<<"⬜                                                                ⬜"<<endl;
                        cout<<"⬜";col(6);cout<<"                YOUR NEAR AMBULANCE LIST     ";col(4); cout<<"                   ⬜"<<endl;
                        col(4);
                        cout<<"⬜                                                                ⬜"<<endl;
                        cout<<"⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜"<<endl;
                        cout<<endl;
                col(2);
                cout<<"-----------------------------------------------------------------------------------\n";
                col(5);
                cout<<"Area pin \t Vechical id \t Vechical type \t drive Name \t drive phone "<<endl;
                col(3);
                cout<<"-----------------------------------------------------------------------------------\n";
        while(!amb_file.eof())
        {
            if(no ==ul.get_ambpn_code())
            {   
                flag=1;
                col(7);
                ul.put_ambul();
                col(2);
                cout<<"-----------------------------------------------------------------------------------\n";
            }
            amb_file.read((char*)&ul,sizeof(ul));
        }
        if(flag==0)
        {
            col(4);
            cout<<"You have enter wrong pin : "<<endl;;
        }
    }
    amb_file.close();
    }
//---------------------------------------------Which  ambulance Your have selected---------------------------------------------------------
void show_amb_log(){     
    int countdown = 30; //initializer the time take to help
    int no,flag=0;
    amb_file.open("ambul.dat",ios::in|ios::binary);
    if(!amb_file){
        cout<<"--------------------Server Error-----------------------------------------\n";
        exit(0);
    }
    else{
        col(6);
        cout<<"enter yor ambulance id : ";
        col(7);
        cin>>no;
        amb_file.read((char*)&ul,sizeof(ul));
        col(2);
        cout<<"----------------------------------------------------------------------------------\n";
                        col(4);
                        cout<<"⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜"<<endl;
                        cout<<"⬜                                                                ⬜"<<endl;
                        cout<<"⬜";col(6);cout<<"                      YOU HAVE SELECTED       ";col(4); cout<<"                  ⬜"<<endl; col(4);
                        cout<<"⬜                                                                ⬜"<<endl;
                        cout<<"⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜"<<endl;
                        col(2);
                cout<<"-----------------------------------------------------------------------------------\n";
                col(5);
                cout<<"Area pin \t Vechical id \t Vechical type \t drive Name \t drive phone "<<endl;
                col(2);
                cout<<"-----------------------------------------------------------------------------------\n";
                cout<<endl;
        while(!amb_file.eof())
        {
            if(no ==ul.get_ambid())
            {   
                flag=1;
                col(7);
                ul.put_ambul();
                col(2);
                cout<<"-----------------------------------------------------------------------------------\n";
                    //===========================Time countdown=====================================
                    col(4);
                        cout<<"⬜                                                                ⬜"<<endl;
                        cout<<"⬜";col(6);cout<<"             Ambulance is coming...in 5 min       ";col(4); cout<<"              ⬜"<<endl;
                        col(4);
                        cout<<"⬜                                                                ⬜"<<endl;
                        col(2);
                        cout<<"-------------------------------------------------------------------------------\n";
                    cout << "";
                    while (countdown > 0)
                        {
                            col(6);
                        
                        cout <<"\r" << countdown / 60 << ":" << countdown % 60 <<flush;
                        Sleep(1000);
                            countdown--;
                        }
                        col(5);
                        cout<<"\rAmbulance has arrived!\n";
                    //=============================End===============================================
            }
            amb_file.read((char*)&ul,sizeof(ul));
        }
        if(flag==0)
        {col(9);
            cout<<"You have enter wrong pin : "<<endl;;
        }
    }

    amb_file.close();
    }
//------------------------------------------------Hospital List to create--------------------------------------------------
void create_hosp(){
    hosp_file.open("hosp.dat",ios::app|ios::binary);
    pi.get_hosp();
    hosp_file.write((char*)&pi,sizeof(pi));
    hosp_file.close();col(5);
    cout<<"you Hospital is completely Authr to our service"<<endl;
    cout<<"------------------------------------------------------------------------"<<endl;
}
//-----------------------------------------------------Show all Hosptial in your Area------------------------------------------------
void show_hosp(){
    int no,flag=0;
    hosp_file.open("hosp.dat",ios::in|ios::binary);
    if(!hosp_file){col(4);
        cout<<"--------------------Server Error-----------------------------------------\n";
        exit(0);
    }
    else{col(6);
        cout<<"enter yor area pin : ";col(2);
        cin>>no;
        hosp_file.read((char*)&pi,sizeof(pi));col(7);
        cout<<"----------------------------------------------------------------------------------\n";col(4);
                        cout<<"⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜"<<endl;
                        cout<<"⬜                                                                ⬜"<<endl;
                        cout<<"⬜";col(6);cout<<"             YOUR NEAREST HOSPITAL LIST       ";col(4); cout<<"                   ⬜"<<endl; col(4);
                        cout<<"⬜                                                                ⬜"<<endl;
                        cout<<"⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜"<<endl;
                        col(2);
                cout<<"-----------------------------------------------------------------------------------\n";col(5);
                cout<<"Pin code \t Hospital id \t Hospital Name \t\tAddress \t Phone No "<<endl;col(2);
                cout<<"-----------------------------------------------------------------------------------\n";
        while(!hosp_file.eof())
        {
            if(no ==pi.get_hosp_pin())
            {   
                flag=1;col(7);
                pi.put_hosp();col(9);
                cout<<"-----------------------------------------------------------------------------------\n";
            }
            hosp_file.read((char*)&pi,sizeof(pi));
        }
        if(flag==0)
        {
            col(4);
            cout<<"You have enter wrong pin : "<<endl;;
        }
    }
    hosp_file.close();
    }
    //-----------------------Admin Access for Ambulance------------------------------------
    //-----------------------show all file of Ambulance------------------------------------
    void admin_ambl_showall()
    {
    amb_file.open("ambul.dat",ios::in|ios::binary);
    if(!amb_file)
    {col(4);
        cout<<"file not open";
        exit(0);
    }
    else
    {
        amb_file.read((char*)&ul,sizeof(ul));col(5);
        cout<<"Area pin \t Vechical id \t Vechical type \t drive Name \t drive phone "<<endl;
        cout<<"-----------------------------------------------------------------------------------\n";
        while(!amb_file.eof())
        {col(4);
            ul.put_ambul();
            amb_file.read((char*)&ul,sizeof(ul));
        }
    }
    amb_file.close();
    }
    //-----------------------delete file of Ambulance------------------------------------
    void admin_ambl_delete(){
        int no;col(6);
        cout<<"enter the code of ambulance to delete :";col(7);
        cin>>no;
        ofstream amb_file2;
        amb_file2.open("new_ambl.dat",ios::out|ios::binary);
        amb_file.open("ambul.dat",ios::in|ios::binary);
        if(!amb_file)
        {col(4);
            cout<<"file no exists";
        }
        else{
            amb_file.read((char*)&ul,sizeof(ul));
                while(!amb_file.eof())
                { 
                    if(no!=ul.get_ambpn_code())
                    {
                        amb_file2.write((char*)&ul,sizeof(ul));
                    }
                    amb_file.read((char*)&ul,sizeof(ul));
                }
            amb_file2.close();
            amb_file.close();
            remove("ambul.dat");
            rename("new_ambl.dat","ambul.dat");
        }
    }
//-----------------modify the data of ambulance------------------------
void admin_ambl_modify()
{
    int no,ph,pin;
    char na[100];col(6);
    cout<<"enter the id of ambulance to Modify  ";col(7);
    cin>>no;col(6);
    cout<<"Enter the update name : ";col(7);
    cin>>na;col(6);
    cout<<"Enter the update phone number :";col(7);
    cin>>ph;col(6);
    cout<<"Enter the update address pin :";col(7);
    cin>>pin;col(6);
    amb_file.open("ambul.dat",ios::in|ios::out|ios::binary);
        if(!amb_file)
        {col(4);
            cout<<"file not found"<<endl;
        }
        while(amb_file.read((char*)&ul,sizeof(ul)))
        {
            if(ul.get_ambid()==no)
            {

                ul.amb_modify(na,ph,pin);
                int pos=sizeof(ul);
                amb_file.seekp(-pos,ios::cur);
                amb_file.write((char*)&ul,sizeof(ul));
            }
        }
amb_file.close();
}
//-----------------------Admin Access for Hospital------------------------------------
//-----------------------show all file of Hospital------------------------------------
void admin_hosp_showall()
    {
    hosp_file.open("hosp.dat",ios::in|ios::binary);
    if(!hosp_file)
    {col(4);
        cout<<"file not open";
        exit(0);
    }
    else
    {
        hosp_file.read((char*)&pi,sizeof(pi));col(6);
        cout<<"Pin code \t Hospital id \t Hospital Name \t Address \t Phone No "<<endl;
        cout<<"-----------------------------------------------------------------------------------\n";
        while(!hosp_file.eof())
        {col(7);
            pi.put_hosp();
            hosp_file.read((char*)&pi,sizeof(pi));
        }
    }
    hosp_file.close();
    }
    //-----------------------delete file of Hospital------------------------------------
    void admin_hosp_delete(){
        int no;col(6);
        cout<<"enter the code of ambulance to delete :";col(7);
        cin>>no;
        ofstream hosp_file2;
        hosp_file2.open("new_hosp.dat",ios::out|ios::binary);
        hosp_file.open("hosp.dat",ios::in|ios::binary);
        if(!hosp_file)
        {col(4);
            cout<<"file no exists";
        }
        else{
            hosp_file.read((char*)&pi,sizeof(pi));
                while(!hosp_file.eof())
                { 
                    if(no!=pi.get_hosp_pin())
                    {
                        hosp_file2.write((char*)&pi,sizeof(pi));
                    }
    
                    hosp_file.read((char*)&pi,sizeof(pi));
                }
            hosp_file2.close();
            hosp_file.close();
            remove("hosp.dat");
            rename("new_hosp.dat","hosp.dat");
        }
    }
//-----------------modify the data of Hospital------------------------
void admin_hosp_modify()
{
    int no,ph,pin;
    char na[100],ad[100];col(6);
    cout<<"Enter the id of Hospital to Modify  ";col(7);
    cin>>no;col(6);
    cout<<"Enter the update Hospital Name : ";col(7);
    cin>>na;col(6);
    cout<<"Enter the update Hospital Phone number :";col(7);
    cin>>ph;col(6);
    cout<<"Enter the update Hospital Address Pin code :";col(7);
    cin>>pin;col(6);
    cout<<"Enter the update Hospital Address :";col(7);
    cin>>ad;col(6);
    hosp_file.open("hosp.dat",ios::in|ios::out|ios::binary);
        if(!hosp_file)
        {col(4);
            cout<<"file not found"<<endl;
        }
        while(hosp_file.read((char*)&pi,sizeof(pi)))
        {
            if(pi.get_hospid()==no)
            {
                pi.hosp_modify(na,ph,pin,ad);
                int pos=sizeof(pi);
                hosp_file.seekp(-pos,ios::cur);
                hosp_file.write((char*)&pi,sizeof(pi));
            }
        }
hosp_file.close();
}