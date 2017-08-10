Instructions for running the program:

Dependency:
  c++11 compiler and "gsl" library are required

Input data (pheno_exp.txt is an example):
  Please prepare the expression data with the following format: 
  1) first column contains probe/transcript/gene IDs
  2) first row contains sample IDs
  3) second row contains phenotypes (0 or 1)
  4) third row and thereafter contain gene expression levels

Execution procedure:

  1) Detemine the height cutoff for UPGMA: modify the "cut" variable in the "struct.h" file if needed. Default: 0.6.

  2) Sort the mutual information of individual genes in ascending (inversely represented by conditional entropy)
     Commands:
           g++ -std=c++11 sel_ind.c -o sel_ind
           ./sel_ind pheno_exp.txt g_entropy_ordered             (argument explanation: ./sel_ind expression_file ordered_entropy_file)

  3) Run a single thread for the optimization procedure
     Parameter setting:
           Modify the "cutoff" variable of conditional entropy of individual genes in the "indv_thread.c" file. Default: 0.97175; 
     Commands:
           g++ -std=c++11 indv_thread.c -o ind_thread
           ./ind_thread  pheno_exp.txt g_entropy_ordered 0 30 test.syn             (argument explanation: ./ind_thread expression_file ordered_entropy_file start_position_in_ordered_entropy end_position_in_ordered_entropy optimal_synergy_file)

 4) Optional: multi-threading example (need multi-threading expertise)
    Commands:
           g++ -std=c++11 -pthread paral_series.c -o paral_compt
           ./paral_compt
           
 5) Find three-way interactions from a single output
    Parameter setting:
           Modify the "cut_syn" value in "gen_threeway_new.c" for selecting two interacting genes. Default: 0.9.
    Commands:
           LD_LIBRARY_PATH=/usr/local/lib
           export LD_LIBRARY_PATH
           g++ -std=c++11 gen_threeway_new.c -o threeway -lgsl -lgslcblas
           ./threeway pheno_exp.txt test.syn test.threeway    (argument explanation: ./threeway expression_file optimal_synergy_file threeway_interaction_file) 
 6) Evaluate the pvalue of pairwise synteny by permutation tests
    Command:
           perl pval_perm.pl test.syn 0.9 100 test.perm   (argument explanation: perl pval_perm.pl synergy_result synergy_cutoff permutation_number output)         
