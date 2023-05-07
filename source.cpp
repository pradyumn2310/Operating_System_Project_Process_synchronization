#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <thread>


using namespace std;

class property
{
    public:
        int properties;
        int tenant[10];
        int agent[3];
        //lets take we will be having four properties where different dealers would be dealing to find new tenants/
        //we will be making several functions for the class property they are as follows/
        property()
        {
            properties=4;

        }

};
class tenants:public property
{
private:
    int binary_semaphore;
    struct timespec ts;

public:
    tenants()
    {
        binary_semaphore = 1;
    }
    /here including the mutex lock functions/
    void lock()
    {
        binary_semaphore++;
    }

    void unlock()
    {
        binary_semaphore--;
    }

    void tenant_arrives(int num_processes)
    {
        cout << "Process order: ";
        for (int i = 0; i < num_processes; i++)
        {
            cout << i + 1 << " ";
        }
        cout << endl;
    }
    void RequestAppointment(int time, string day)
    {
        cout << "\nRequest Appointment";

        cout << "\nYour appointment to view the flat has been scheduled  on " << day << " @" << time << ":00";
    }

    static DWORD WINAPI threadFunction(LPVOID lpParam) {
        cout << "\n\nAgent is providing information to Tenant in other room." << endl;
        return 0;
    }
    
    void ScheduleAppointment()
        {
            int time;
            cout<<"choose the time slot you wish to come and visit the apart!"
            <<"\n1.(11:00am-13:00pm)"
            <<"\n2.(13:00pm-14:00pm)"
            <<"\n3.(15:00pm-16:00pm)";
            cin>>time;
        }
    void CheckAppointment(int n)
        {
            if(n<=9)
            {
                cout<<"Your appointment is confirmed "<<endl;
            }
            else
            {
                cout<<"Your appointment is on waiting"<<endl;
            }

        }
    void SeeApartment(int num_processes)
    {
        /*here we will be using the binary semaphore where when one of the tenants would be viewing the apart other tenant cannot intrude or come to
        view the apart */

        for (int i = 1; i <= num_processes; i++)
        {
            lock();
            

            if (binary_semaphore > 2)
            {
                const char *mess = "Mutual exclusion wont be followed!\nYou wont be able to access the flat";
                const char *title = "error 502";
                MessageBox(NULL, mess, title, MB_OK);
                const char *mes = "Sorry for the Inconvenience  :(";
                const char *ttl = "error 504";
                MessageBox(NULL, mes, ttl, MB_OK);

                break;
            }
            else if (binary_semaphore == 2)
            {
                HANDLE hThread = CreateThread(NULL, 0, threadFunction, NULL, 0, NULL);
                if (hThread == NULL)
                {
                    cout << "Thread creation failed" << endl;
                }

               

                CONTEXT context;
                context.ContextFlags = CONTEXT_FULL;
                if (GetThreadContext(hThread, &context))
                {
                    
                cout << "\n\nTenant  " << i << " is viewing the flat";
                cout << "\n No other tenant or agent is allowed to enter the flat!";

                CloseHandle(hThread);

                unlock();
                cout << "\n The flat has been viewed and now,Tenant " << i << " is leaving the flat !";
            }
            else if (binary_semaphore == 1)
            {
                cout << "\nNo process is in the critical section!";
            }
            ts.tv_sec = 5;
            ts.tv_nsec = 0;
            int result = nanosleep(&ts, nullptr);

            if (result == -1)
            {
                const char *message = "Error calling Nanosleep....!";
                

                const char *title = "Error 505";
                MessageBox(NULL, message, title, MB_OK);
            }
        }
    }
    }
    void LeaveApartment(int n)
        {
            for (int id = 1; id <= n; id++)
            {
                cout << "\n";
                cout << endl;
                cout << "Tenant " << id << " leaves the apart\n ";
            }


        }
};
class agents:public property
{
    private:
        int binary_semaphore;
        struct timespec ts;

    public:
        tenants()
        {
            binary_semaphore = 1;
        }
        /here including the mutex lock functions/
        void lock()
        {
            binary_semaphore++;
        }

        void unlock()
        {
            binary_semaphore--;
        }
    void RequestAppointment(int time, string day)
        {
            int choice;
            cout<<" Which property you to visit ?\nAvailable properties: 1,2,3,4\n";
            cout<<"Enter choice:";
            cin>>choice;
            if(choice==1 || choice==2 || choice==3 || choice==4)
            {
                cout<<"Kindly schedule appointment"<<endl;
            }
            cout << "\nYour appointment to view the flat has been scheduled  on " << day << " @" << time << ":00";
        
        }
    void ScheduleAppointment()
        {
             int time;
            cout<<"choose the time slot you wish to come and visit the apart!"
            <<"\n1.(11:00am-13:00pm)"
            <<"\n2.(13:00pm-14:00pm)"
            <<"\n3.(15:00pm-16:00pm)";
            cin>>time;

        }
    void CheckAppointment(int n)
        {
            if(n>0 || n<0)
            {
                cout<<"Your appointment is on waiting"<<endl;
            }
            else
            {
                cout<<"You can visit the appartment"<<endl;
            }
            

        }

    static DWORD WINAPI threadFunction(LPVOID lpParam) {
        cout << "\n\nAgent is providing information to Tenant in other room." << endl;
        return 0;
    }
    void SeeApartment(int num_processes)
        {
            if(*tenant>0 && *tenant<=9)
            {
                cout<<"Agent arrived at appartment "<<endl;
            }
        /*here we will be using the binary semaphore where when one of the tenants would be viewing the apart other tenant cannot intrude or come to
        view the apart */

        for (int i = 1; i <= num_processes; i++)
        {
            lock();
            

            if (binary_semaphore > 2)
            {
                const char *mess = "Mutual exclusion wont be followed!\nYou wont be able to access the flat";
                const char *title = "error 502";
                MessageBox(NULL, mess, title, MB_OK);
                const char *mes = "Sorry for the Inconvenience  :(";
                const char *ttl = "error 504";
                MessageBox(NULL, mes, ttl, MB_OK);

                break;
            }
            else if (binary_semaphore == 2)
            {
                HANDLE hThread = CreateThread(NULL, 0, threadFunction, NULL, 0, NULL);
                if (hThread == NULL)
                {
                    cout << "Thread creation failed" << endl;
                }

               

                CONTEXT context;
                context.ContextFlags = CONTEXT_FULL;
                if (GetThreadContext(hThread, &context))
                {
                    
                cout << "\n\nTenant  " << i << " is viewing the flat";
                cout << "\n No other tenant or agent is allowed to enter the flat!";

                CloseHandle(hThread);

                unlock();
                cout << "\n The flat has been viewed and now,Tenant " << i << " is leaving the flat !";
            }
            else if (binary_semaphore == 1)
            {
                cout << "\nNo process is in the critical section!";
            }
            ts.tv_sec = 5;
            ts.tv_nsec = 0;
            int result = nanosleep(&ts, nullptr);

            if (result == -1)
            {
                const char *message = "Error calling Nanosleep....!";
                

                const char *title = "Error 505";
                MessageBox(NULL, message, title, MB_OK);
            }
        }
    }
        }
    void LeaveApartment()
        {
            if(tenant==0)
            {
                cout<<"You can leave appartment"<<endl;
            }
            else
            {
                cout<<"Wait for tenant to leave "<<endl;
            }
        } 
};



int main()
{
    const char *message = "Good Afternoon Sir\n Welcome to Process Synchronization wizard!!!....";
    const char *title = "My Program";
    MessageBox(NULL, message, title, MB_OK);

    cout << "Enter the number of processes: ";
    cin >> num_processes;
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
                        tenant1->RequestAppointment(num_processes);
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
                        agent1->ScheduleAppointment(num_processes);
                        break;
                    case 3:
                        agent1->CheckAppointment(agent);
                        break;
                    case 4:
                        agent1->SeeApartment(agent);
                        break;
                    case 5:
                        agent1->LeaveApartment(); 
                        const char *chat = "Have a Nice Day....! :)";
                        const char *file = "Notice!";
                        MessageBox(NULL, chat, file, MB_OK);
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
 return 0;
}