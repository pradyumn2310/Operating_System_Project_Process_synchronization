# Operating_System_Project_Process_synchronization


""Project Overview""
Anytime we share data between two or more processes or threads, we run the risk of having a race condition where our 
data could become corrupted. In order to avoid these situations, we have various mechanisms to ensure that one 
program’s critical regions are guarded from another’s.
One place that we might use parallelism is to simulate real-world situations that involve multiple independently acting 
entities, such as people. In this project, we will use the semaphore implementation to model the safe apartment 
inspection problem,
whereby (potential) tenants and real-estate agents synchronize so that:

• a tenant cannot view an apartment without an agent,

• an agent cannot open the apartment without a tenant,

• an agent leaves when no more tenants are in the apartment,

• an agent cannot leave until all tenants in the apartment leave,

• once an agent opens the apartment, she can show the apartment to at most ten tenants, and

• at most one agent can open the apartment at a time.


The job of this project is to write a program that 

(a) always satisfies the above constraints and 

(b) where under no conditions will a deadlock occur. 

(A deadlock happens, for example, when the apartment is empty, an
agent and a tenant arrive, but cannot enter. 

""1)WORK DISTRIBUTION""
Pradyumn (211127) : 
 Tenant class , map, friend functions ,object factory, aging, windows API, binary semaphores.
Nandini (211131) :
 Agent class, priority inversion, friend functions ,switch case, object factory, windows API.
Karan (211445) : 
 Owner class, aptsim, friend functions, abstract class , nanosleep, windows API.


""2) SRS""
Purpose: The job of this project is to write a program that 
(a) always satisfies the above constraints and 
(b) where under no conditions will a deadlock occur. 
(A deadlock happens, for example, when the apartment is empty, an
agent and a tenant arrive, but cannot enter. 
Intended Audience: Owners, tenants and agents who want to deal with various property issues.
Intended Use: A person can inherit and use the apartment safely without any leak of data.

""User Needs:"" 

To interact with the single agent for various properties without dealing with their owners.

"Expected Outcome:"
Print out messages in the form:
The apartment is now empty.
Agent %d arrives at time %d.
Tenant %d arrives at time %d.
Agent %d opens the apartment for inspection at time %d.
Tenant %d inspects the apartment at time %d.
Tenant %d arrives at time %d.
Tenant %d inspects the apartment at time %d.
Tenant %d leaves the apartment at time %d.
Tenant %d leaves the apartment at time %d.
Agent %d leaves the apartment at time %d

""Functional Requirements:"" To make our shared data and our semaphores, what we need is for multiple processes 
to be able to
share the same memory region. We can ask for N bytes of RAM from the OS directly by using mmap():
void *ptr = mmap(NULL, N, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, 0, 0);
Nonfunctional Requirements: WINDOW 11, VS CODE , LEARN MICROSOFT.


""3) HLD/LLD""
Low-level description of Process Synchronization: 
In the case of Process Synchronization project in C++, the LLD would include defining the classes, functions, and 
algorithms that would be required to implement the system. Here is an LLD for this project file in C++:


"Classes:"
1.Property
2.Tenants
3.Agents


"Functions:"
1.Requestappointment()
2.ScheduleAppointment()
3.WaitforAppointment()
4.SeeApartment()
5.TenantArrives()
6.AgentArrives()
7.OpenApartment()
8.TenantLeavesApartment()
9.AgentLeavesApartment()
10.rand()


""Libraries:""
1. Iostream
2. Time.h
The above LLD provides a basic outline of the design for a file compression and decompression system in C++. 
However, depending on the specific requirements of the project, additional classes, functions, and data structures 
may be required.


""Conclusion""
Process synchronization is an important concept in operating system design and implementation, and it plays a crucial role 
in ensuring the correct and efficient execution of concurrent programs. 
There are various mechanisms for achieving process synchronization, including locks, semaphores, monitors, and barriers, 
each with its own strengths and weaknesses.
Choosing the right synchronization mechanism for a particular application requires careful consideration of factors such 
as performance, scalability, and ease of use. Poorly designed or implemented synchronization mechanisms can lead to a 
range of problems, including deadlocks, livelocks, and race conditions, which can result in incorrect or unpredictable 
program behavior. 
Testing and debugging concurrent programs can be challenging, and it is important to have robust testing and debugging 
tools and techniques in place to ensure the correctness of the program
