void comp_sin_dis(int g1)
{
  int i,j;
  double min_dis=10000000;
  for(i=0;i<n_samp-1;i++)
  {
   dis[i][i]=0;
   for(j=i+1;j<n_samp;j++)
   {
    double ttt=fabs(expr[g1][i]-expr[g1][j]);
    dis[i][j]=ttt;
    dis[j][i]=ttt;
    if(ttt<min_dis)
    {
      min_dis=ttt;
      min_id[0]=i;
      min_id[1]=j;
    }
   }
  }
}
void comp_eu_dis(int g1,int g2)
{
  int i,j;
  double min_dis=10000000;
  for(i=0;i<n_samp-1;i++)
  {
   dis[i][i]=0;
   for(j=i+1;j<n_samp;j++)
   {
    double ttt=sqrt(pow((expr[g1][i]-expr[g1][j]),2)+pow((expr[g2][i]-expr[g2][j]),2));
    dis[i][j]=ttt;
    dis[j][i]=ttt;
    if(ttt<min_dis)
    {
      min_dis=ttt;
      min_id[0]=i;
      min_id[1]=j;
    }
   }
  }
}
void comp_ch_dis(int g1,int g2)
{
  int i,j;
  double min_dis=10000000;
  for(i=0;i<n_samp-1;i++)
  {
   dis[i][i]=0;
   for(j=i+1;j<n_samp;j++)
   {
    double ttt0=fabs(expr[g1][i]-expr[g1][j]);
    double ttt1=fabs(expr[g2][i]-expr[g2][j]);
    double ttt=ttt0>ttt1?ttt0:ttt1;
    dis[i][j]=ttt;
    dis[j][i]=ttt;
    if(ttt<min_dis)
    {
      min_dis=ttt;
      min_id[0]=i;
      min_id[1]=j;
    }
   }
  }
}

