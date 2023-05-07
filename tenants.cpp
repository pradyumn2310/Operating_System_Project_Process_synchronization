#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <thread>

#include <windows.h>

using namespace std;

class tenants
{
private:
    int binary_semaphore;
    struct timespec process_sleep;

public:
    tenants()
    {
        binary_semaphore = 1;
    }
    /*here including the mutex lock functions*/
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
    void tenants_request_appointment(int time, string day)
    {
        cout << "\nRequest Appointment";

        cout << "\nYour appointment to view the flat has been scheduled  on " << day << " @" << time << ":00";
    }
/*This is a threadFunction which is included in Kernel32.dll*/
    static DWORD WINAPI threadFunction(LPVOID lpParam) {
        cout << "\n\nAgent is providing information to Tenant in other room." << endl;
        return 0;
    }

    void tenants_see_apartment(int num_processes)
    {
        /*here we will be using the binary semaphore where when one of the tenants would be viewing the apart other tenant cannot intrude or come to
        view the apart */

        for (int i = 1; i <= num_processes; i++)
        {
            lock();
            

            if (binary_semaphore > 2)
            {
                /*Dsiplaying thr */
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
            process_sleep.tv_sec = 5;
            process_sleep.tv_nsec = 0;
            int result = nanosleep(&process_sleep, nullptr);

            if (result == -1)
            {
                const char *message = "Error calling Nanosleep....!";
                

                const char *title = "Error 505";
                MessageBox(NULL, message, title, MB_OK);
            }
        }
    }
}
};

int main()
{
    const char *message = "Good Afternoon Sir\n Welcome to Process Synchronization wizard!!!....";
    const char *title = "My Program";
    MessageBox(NULL, message, title, MB_OK);
    tenants obj1;
    int num_processes;

    cout << "Enter the number of processes: ";
    cin >> num_processes;

    int time;
    string day;
    cout << "Enter the time and day you wish to visit:";
    cin >> time >> day;

    obj1.tenant_arrives(num_processes);
    obj1.tenants_request_appointment(time, day);

    const char *text = "Appointment Scheduled.....!!!!!";
    const char *topic = "Success";
    MessageBox(NULL, text, topic, MB_OK);
    obj1.tenants_see_apartment(num_processes);
    const char *chat = "Have a Nice Day....! :)";
    const char *file = "Notice!";
    MessageBox(NULL, chat, file, MB_OK);
 return 0;
}
