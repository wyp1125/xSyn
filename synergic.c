double mi(double x)
{
double y=x>0.5?x:(1-x);
if(y==1)
y=0.9999;
return -y*log(y)/log(2)-(1-y)*log(1-y)/log(2);
}
double synergic(int* sts)
{
int len=dndr.length();
if(len==1)
{
return -10.0;
}
char curr;
string tid="";
int i,j;
int id;
int cid=0;
double mu,c_size,c_cncr;
c_size=0;
c_cncr=0;
double cum_syn=0;
for(i=0;i<len;i++)
{
curr=dndr.at(i);
int temp=int(curr);
if(temp>=48 && temp<=57)
{
tid=tid+curr;
}
else if(temp==44)
{
id=stoi(tid);
c_size++;
c_cncr+=sts[id];
s_cid[id]=cid;
//cout<<j<<" "<<id<<" "<<cid<<" "<<c_size<<" "<<c_cncr<<endl;
tid="";
j++;
}
else
{
id=stoi(tid);
c_size++;
c_cncr+=sts[id];
s_cid[id]=cid;
cum_syn+=(double)c_size*mi((double)c_cncr/(double)c_size);
//cout<<j<<" "<<id<<" "<<cid<<" "<<c_size<<" "<<c_cncr<<" "<<mi((double)c_cncr/(double)c_size)<<endl;
c_size=0;
c_cncr=0;
tid="";
j++;
cid++;
}
}
id=stoi(tid);
c_size++;
c_cncr+=sts[id];
s_cid[id]=cid;
cum_syn+=(double)c_size*mi((double)c_cncr/(double)c_size);
//cout<<j<<" "<<id<<" "<<cid<<" "<<c_size<<" "<<c_cncr<<" "<<mi((double)c_cncr/(double)c_size)<<endl;
cum_syn=cum_syn/(double)n_samp;
return cum_syn;
}
double phe_synergic(int* sts)
{
int x=0;
for(int i=0;i<n_samp;i++)
{
x+=sts[i];
}
double temp=(double)x/(double)n_samp;
return mi(temp);
}
