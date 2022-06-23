#include<assert.h>
#include<math.h>
#include<stdio.h>
#include"tangente.h"
double tangente(double x){
    double x2=x*x,x3=x*x2,x5=x3*x2,x7=x5*x2;
    return x+x3/3 +2*x5/15 +17*x7/315;
}
//pre-condition nbre de points <=NMAX
int getTable(interval_t i ,table_t table){
  int nbrePts=(int)(fabs(i.b-i.a)/PAS +1),j;  
  assert(nbrePts<=NMAX); // Macro qui génère une erreur si la condition est fausse
  for(j=0;j<nbrePts;j++){
    table[j].x=i.a+j*PAS;
    table[j].y=tangente(table[j].x);
  }
  return nbrePts;
}
void afficher(const table_t table,  int n){
    int j;
    printf("%20.3f  %20.3f\n",PI_DEMI,tan(PI_DEMI));
    printf("%20s%20s%20s\n","X","Y","ERR");
    for(j=0;j<n;j++)
        printf("%20.3f %20.3f %20.3f\n",table[j].x,table[j].y,fabs(table[j].y-tan(table[j].x)));
}

int main(){
    interval_t i={-PI_DEMI+EPS,PI_DEMI-EPS};
    int n;
    table_t table;
    n=getTable(i,table);
    afficher(table,n);
    return 0;
}