void cluster()
{
  double size[n_samp];
  string clst[n_samp];
  double height[n_samp];
  int i,j,c1,c2;
  c1=min_id[0];
  c2=min_id[1];
//  cout<<c1<<" "<<c2<<endl;
  for(i=0;i<n_samp;i++)
  {
    size[i]=1;
    clst[i]=to_string(i);
  }
  int n=n_samp;
  int good=0;
  while(n>1)
  {
    height[c1]=dis[c1][c2]/2;
    if(height[c1]>cut)
    {
     good=1;
     dndr=clst[0];
     for(i=1;i<n;i++)
     {
       dndr=dndr+"\t"+clst[i];
     }
     break;
    }
    for(i=0;i<n;i++)
    {
      if(i!=c1)
      {
      dis[i][c1]=(dis[i][c1]*size[c1]+dis[i][c2]*size[c2])/(size[c1]+size[c2]);
      dis[c1][i]=dis[i][c1];
      }
    }
    clst[c1]=clst[c1]+","+clst[c2];
    //cout<<clst[c1]<<"\t"<<height[c1]<<endl;
    size[c1]=size[c1]+size[c2];
    for(j=c2;j<n-1;j++)
    {
       size[j]=size[j+1];
       clst[j]=clst[j+1];
       for(i=0;i<c2;i++)
       {
           dis[i][j]=dis[i][j+1];
           dis[j][i]=dis[i][j];
       }
       for(i=c2;i<n-1;i++)
       {
         if(j>i)
         {
           dis[i][j]=dis[i+1][j+1];
           dis[j][i]=dis[i][j];
         }
       }
    }
  double  min_d=10000000;
  n--;
  for(i=0;i<n;i++)
  for(j=i+1;j<n;j++)
  if(dis[i][j]<min_d)
  {
     min_d=dis[i][j];
     c1=i;
     c2=j;
  }
//    cout<<clst[c1]<<"\t"<<clst[c2]<<"\t"<<min_d<<endl;
  }
  if(good==0)
  {
   dndr="N";
  }
// cout<<dndr<<endl;
}

