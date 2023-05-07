#include<iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <thread>
#include <windows.h>
#include"property"
using namespace std;

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