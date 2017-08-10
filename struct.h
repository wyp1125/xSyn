#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
vector<string> probe;
vector<int> phe;
int* ini_phe;
vector< vector<double> > expr;
int n_prob,n_samp;
double** dis;
int min_id[2];
double cut=0.06; //modify here if needed
string dndr;
int* s_cid;

