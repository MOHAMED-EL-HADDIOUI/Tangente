#ifndef _TANGENTE
    #include<math.h>
    #define _TANGENTE
    #define NMAX 2000
    #define EPS 0.0
    #define PI_DEMI   2*atan(1)
    #define PAS 0.01
    typedef struct {
        double a,b;
    }interval_t;
    typedef struct{
        double x,y;
    }point_t;
    typedef point_t table_t[NMAX];
 
    double tangente(double);
    int getTable(interval_t ,table_t);
    void afficher(const table_t,int );
#endif