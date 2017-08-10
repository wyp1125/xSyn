#include "struct.h"
#include "readdata.c"
#include "distance.c"
#include "cluster.c"
#include "synergic.c"
#include "call_syn.c"
#include <map>
#include <gsl/gsl_cdf.h>
vector<string> x_prob;
vector<vector<int>> group;
double cut_syn=0.9;
vector<int> state;
map<string,int> probe2id;
int xgene_id;
double xgene_p;
void gen_xgene()
{
  int i,j;
  double min_p=0.005;
  int min_id=-1;
  for(i=0;i<n_prob;i++)
  {
    double x,xx,y,yy;
    x=xx=y=yy=0.0;
    double n,m;
    n=m=0;
    double t_expr[n_samp];
    for(j=0;j<n_samp;j++)
    {
     t_expr[j]=expr[i][j];
     if(state[j]==0)
     {
      x+=expr[i][j];
      xx+=expr[i][j]*expr[i][j];
      m++;
     }
     else
     {
      y+=expr[i][j];
      yy+=expr[i][j]*expr[i][j];
      n++;
     }
    }
    double mean1=x/m;
    double mean2=y/n;
    double var1=(xx-x*x/m)/m;
    double var2=(yy-y*y/n)/n;
    double tstat=0;
    double pval=1;
    if(var1!=0 && var2!=0)
    {
      tstat=(mean1-mean2)/sqrt((1/m+1/n)*((m-1)*var1+(n-1)*var2)/(m+n-2));
      double df=m+n-2;
      pval=2*(1-gsl_cdf_tdist_P(fabs(tstat), df));
      if(pval<min_p)
      {
        min_p=pval;
        min_id=i;
      }
    }
  }
 xgene_id=min_id;
 xgene_p=min_p;
}
void read_syn(char *fn, char *fn1)
{
  ifstream in(fn);
  ofstream result;
  result.open(fn1,ios::out);
  string line,word;
  int i=0;
  while(!in.eof())
  {
    getline(in,line);
    if(line.length()<2)
    {
      continue;
    }
    istringstream test(line);
    getline(test,word,'\t');
    string pb1=word;
    getline(test,word,'\t');
    string pb2=word;
    getline(test,word,'\t');
    double tag=atof(word.c_str());
    if(tag<cut_syn)
    continue;
    state.clear();
    while(!test.eof())
    {
      getline(test,word,'\t');
      state.push_back(atoi(word.c_str()));
    }
    gen_xgene();
    if(xgene_p*n_prob<0.05)
    {
    cout<<i++<<endl;
    result<<pb1<<"\t"<<pb2<<"\t"<<tag<<"\t"<<xgene_id<<"\t"<<probe[xgene_id]<<"\t"<<xgene_p<<endl;
    }
  }
}
int main(int argc, char *argv[])
{
  read_exp(argv[1]);
  int i;
  for(i=0;i<n_prob;i++)
  {
    probe2id[probe[i]]=i;
  }
  dis=new double*[n_samp];
  for(i=0;i<n_samp;i++)
  {
    dis[i]=new double[n_samp];
  }
  s_cid=new int[n_samp];
  read_syn(argv[2],argv[3]);
  return 1;
}
