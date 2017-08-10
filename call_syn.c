double call_sin_syn(int g1,int* t_phe)
{
  comp_sin_dis(g1);
  //cout<<"here"<<endl;
  cluster();
  //cout<<dndr<<endl;
  if(dndr=="N")
  return -10.0;
  else
  return synergic(t_phe);
}
double call_two_syn(int g1,int g2,int* t_phe,int dis_tp)
{
  int good=1;
  double inf1,inf2,inf3,inf4;
  inf1=call_sin_syn(g1,t_phe);
  if(inf1==-10.0)  
  return -10.0;
  inf2=call_sin_syn(g2,t_phe);
  if(inf2==-10.0)
  return -10.0;
  if(dis_tp==0)
    comp_ch_dis(g1,g2);
  else
    comp_eu_dis(g1,g2);
  cluster();
  if(dndr=="N")
  return -10.0;
  else
  {
   inf3=synergic(t_phe);
   inf4=phe_synergic(t_phe);
   //cout<<inf1<<" "<<inf2<<" "<<inf3<<" "<<inf4<<endl;
   return inf1+inf2-inf3-inf4;
  }
}
