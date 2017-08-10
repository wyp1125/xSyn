#include "struct.h"
#include "readdata.c"
#include "distance.c"
#include "cluster.c"
#include "synergic.c"
#include "call_syn.c"
int max_cid()
{
 int i=0;
 for(int j=0;j<n_samp;j++)
 {
  if(s_cid[j]>i)
  {
   i=s_cid[j];
  }
 }
 return i;
}
int main(int argc, char *argv[])
{
  read_exp(argv[1]);
  dis=new double*[n_samp];
  ini_phe=new int[n_samp];
  s_cid=new int[n_samp];
  int i,j;
  for(int i=0;i<n_samp;i++)
  {
    dis[i]=new double[n_samp];
    ini_phe[i]=phe[i];
  }
  double ind_g_syn[n_prob];
  int tag[n_prob];
  int tag_sz[n_prob];
  for(i=0;i<n_prob;i++)
  {
    //cout<<i<<endl;
    ind_g_syn[i]=call_sin_syn(i,ini_phe);
    tag[i]=i;
    tag_sz[i]=max_cid();
    //cout<<i<<" "<<ind_g_syn[i]<<endl;
  }
  ofstream result;
  result.open(argv[2],ios::out);
  for(i=n_prob-1;i>0;i--)
    for(j=0;j<i;j++)
    {
      if(ind_g_syn[j]<ind_g_syn[j+1])
      {
        double temp1=ind_g_syn[j];
        int temp2=tag[j];
        int temp3=tag_sz[j];
        ind_g_syn[j]=ind_g_syn[j+1];
        tag[j]=tag[j+1];
        tag_sz[j]=tag_sz[j+1];
        ind_g_syn[j+1]=temp1;
        tag[j+1]=temp2;
        tag_sz[j+1]=temp3;
      }
    }
  for(i=0;i<n_prob;i++)
  {
    result<<probe[tag[i]]<<"\t"<<tag[i]<<"\t"<<ind_g_syn[i]<<"\t"<<tag_sz[i]+1<<endl;
  }
  return 1;
}

