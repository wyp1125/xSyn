#include <iostream>
#include <thread>
#define N 400
using namespace std;

void call_from_thread(int tid) {
         int t=1000;
         int s=t*(t-1)/2;
         int u=s/20+1;
         int x=0;
         int i,j,st,ed;
         int gd1,gd2;
         gd1=gd2=0;
         for(i=0;i<t;i++)
         {
           x+=t-i-1;
           if(x>u*tid && gd1==0) 
           {
             st=i;
             gd1=1;
           }
           if(x>u*(tid+1) && gd2==0)
           {
            ed=i;
            gd2=1;
           }
         }
         if(gd2==0)
         {
          ed=t-1;
         }
         char cmd[N];
         sprintf(cmd,"./ind_thread pheno_exp.txt g_entropy_ordered %d %d out/%d",st,ed,tid);  
         cout<<cmd<<endl;
         i=system(cmd);
     }

int main() {
         
         int num_threads=20;
         thread t[num_threads];

         //Launch a group of threads
         for (int i = 0; i < num_threads; i++) {
             t[i] = thread(call_from_thread, i);
         }

         for (int i = 0; i < num_threads; ++i) {
             t[i].join();
         }

         return 0;
     }

