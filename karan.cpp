#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <thread>
#include <windows.h>
#include"agent.cpp"
#include"tenant.cpp"
using namespace std;
class property
{
    public:
        int properties;
        int tenant[10];
        int agent[3];
        mutex m;
        
        //lets take we will be having four properties where different dealers would be dealing to find new tenants/
        //we will be making several functions for the class property they are as follows/
        property()
        {
            properties=4;
        }
        
        void wait() {
            struct timespec ts;
            ts.tv_sec = 0;
            ts.tv_nsec = 2000000000L; // 2 seconds
            nanosleep(&ts, NULL);
        }
};

int main()
 {
    property *property1;
    tenants *tenant1;
    agents *agent1;
    int tenant=0;
    int agent=0;
    int choice;
    while (2)
    {
         const char *message = "Good Afternoon Sir\n Welcome to Process Synchronization wizard!!!....";
    const char *title = "My Program";
    MessageBox(NULL, message, title, MB_OK);
        
        cout<<"1. Tenant \n2. Agent"<<endl;
        cout<<"Enter you choice"<<endl;
        cin>>choice;
        if(choice==1)
        {
            tenant++;
            while(2)
            {
        
                property1->tenant;
                cout<<"1.Request appointment\n2.Schedule Appointment\n3.Check Appointment\n4.See Apartment\n5.Leave Apartment"<<endl;
                cout<<"Enter your choice"<<endl;
                cin>>choice;
                switch (choice)
                {
                    case 1:
                        tenant1->RequestAppointment();
                        break;
                    case 2:
                        tenant1->ScheduleAppointment();
                        break;
                    case 3:
                        tenant1->CheckAppointment(tenant);
                        const char *text = "Appointment Scheduled.....!!!!!";
                        const char *topic = "Success";
                        MessageBox(NULL, text, topic, MB_OK);
                        break;
                    case 4:
                        tenant1->SeeApartment(tenant);
                        break;
                    case 5:
                        tenant1->LeaveApartment(tenant); 
                        const char *chat = "Have a Nice Day....! :)";
                        const char *file = "Notice!";
                        MessageBox(NULL, chat, file, MB_OK);
                        break;
                    default:
                        cout<<"invalid choice"<<endl;
                        break;
                }
                cout<<"You want to continue as tenant?If yes press 0"<<endl;
                cin>>choice;
                if(choice!=0)
                    break;
            }
        }
        if(choice==2)
        {   
            agent++;
            while(2)
            {
                property1->agent;
                cout<<"1.Request appointment\n2.Schedule Appointment\n3.Check Appointment\n4.See Apartment\n5.Leave Apartment"<<endl;
                cout<<"Enter your choice"<<endl;
                cin>>choice;
                switch (choice)
                {
                    case 1:
                        agent1->RequestAppointment();
                        break;
                    case 2:
                        agent1->ScheduleAppointment();
                        break;
                    case 3:
                        agent1->CheckAppointment(agent);
                        break;
                    case 4:
                        agent1->SeeApartment();
                        break;
                    case 5:
                        agent1->LeaveApartment(); 
                        break;
                    default:
                        cout<<"invalid choice"<<endl;
                        break;
                }
                cout<<"You want to continue as agent ?If yes press 0"<<endl;
                cin>>choice;
                if(choice!=0)
                    break;
            }
        }
        else
        {
            cout<<"invalid choice"<<endl;
        }  
        cout<<"You want to continue ?If yes press 0"<<endl;
        cin>>choice;
            if(choice!=0)
                break;
    }
    
    
    return 0;
 }