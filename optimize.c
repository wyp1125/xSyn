int optimize(int g1,int g2,int dis_tp,char* dir)
{
  int* dyn_phe=new int[n_samp];
  int i,j;
  for(i=0;i<n_samp;i++)
  {
    dyn_phe[i]=ini_phe[i];
  }
  double ini_syn=call_two_syn(g1,g2,ini_phe,dis_tp);
  if(ini_syn==-10.0)
    return -1;
  double cur_syn=ini_syn;
  double dyn_syn;
  double cut_dif=0.01;
  double max_syn;
  int max_pos;
  int go_ahead;
  while(1)
  {
   go_ahead=0;
   max_syn=0;
   for(i=0;i<n_samp;i++)
   {
    dyn_phe[i]=1-dyn_phe[i];
    dyn_syn=call_two_syn(g1,g2,dyn_phe,dis_tp);
    if(dyn_syn-cur_syn>cut_dif)
    {
      go_ahead=1;
      if(dyn_syn>max_syn)
      {
       max_syn=dyn_syn;
       max_pos=i;
      }
    }
    dyn_phe[i]=1-dyn_phe[i];
   }
   if(go_ahead==0)
   {
     break;
   }
   else
   {
     dyn_phe[max_pos]=1-dyn_phe[max_pos];
     cur_syn=max_syn;
     //cout<<ini_syn<<cur_syn<<endl;
   }
  }
  ofstream result;
  result.open(dir,ios::app);
  result<<probe[g1]<<"\t"<<probe[g2]<<"\t"<<cur_syn;
  for(i=0;i<n_samp;i++)
  {
    result<<"\t"<<dyn_phe[i];
  }
  result<<endl;
  result<<probe[g1]<<"\t"<<probe[g2]<<"\t-9";
  for(i=0;i<n_samp;i++)
  {
    result<<"\t"<<s_cid[i];
  }
  result<<endl;
  return 1;
}
