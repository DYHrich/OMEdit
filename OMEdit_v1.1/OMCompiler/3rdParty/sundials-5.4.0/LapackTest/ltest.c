#define SUNDIALS_F77_FUNC(name,NAME) name ## _
#define dcopy_f77 SUNDIALS_F77_FUNC(dcopy, DCOPY)
#define dgetrf_f77 SUNDIALS_F77_FUNC(dgetrf, DGETRF)
extern void dcopy_f77(int *n, const double *x, const int *inc_x, double *y, const int *inc_y);
extern void dgetrf_f77(const int *m, const int *n, double *a, int *lda, int *ipiv, int *info);
int main(){
int n=1;
double x, y;
dcopy_f77(&n, &x, &n, &y, &n);
dgetrf_f77(&n, &n, &x, &n, &n, &n);
return(0);
}
