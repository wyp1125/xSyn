#include "struct.h"
#include "readdata.c"
#include "distance.c"
#include "cluster.c"
#include "synergic.c"
#include "call_syn.c"
#include "optimize.c"
int main(int argc, char *argv[])
{
  double cutoff=0.97175; //modify here if needed
  read_exp(argv[1]);
  dis=new double*[n_samp];
  s_cid=new int[n_samp];
  ini_phe=new int[n_samp];
  int i,j;
  for(i=0;i<n_samp;i++)
  {
    dis[i]=new double[n_samp];
    ini_phe[i]=phe[i];
  }
  ifstream in(argv[2]);
  string line,word,tmp_prob;
  int tmp_id;
  double tmp_syn;
  vector<int> in_id;
  while(!in.eof())
  {
    getline(in,line);
    istringstream test(line);
    getline(test,word,'\t');
    getline(test,word,'\t');
    tmp_id=atoi(word.c_str());
    getline(test,word,'\t');
    tmp_syn=atof(word.c_str());
    if(tmp_syn<=cutoff)
    {
      break;
    }
    else
    {
      in_id.push_back(tmp_id);
    }
  }
  int st_id=atoi(argv[3]);
  int ed_id=atoi(argv[4]);
  for(i=st_id;i<ed_id;i++)
    for(j=0;j<in_id.size();j++)
    { 
      int gg1=in_id[i];
      int gg2=in_id[j];
      optimize(gg1,gg2,0,argv[5]);
      cout<<i<<"\t"<<j<<endl;
    }
  return 1;
}
