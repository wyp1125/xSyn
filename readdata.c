void read_exp(char *fn)
{
  ifstream in(fn);
  string line,word;
  getline(in,line);
  getline(in,line);
  istringstream test(line);
  getline(test,word,'\t');
  while(!test.eof())
  {
    getline(test,word,'\t');
    phe.push_back(atoi(word.c_str()));
  }
  n_samp=phe.size();
  n_prob=0;
  while(!in.eof())
  {
    getline(in,line);
    if(line.length()<2)
    {
      continue;
    }
    //cout<<line<<endl;
    istringstream test(line);
    getline(test,word,'\t');
    probe.push_back(word);
    vector<double> temp;
    while(!test.eof())
    {
      getline(test,word,'\t');
      temp.push_back(atof(word.c_str()));
    }
    expr.push_back(temp);
    n_prob++;
  }
}

