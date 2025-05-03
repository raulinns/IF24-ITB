#include <stdio.h>
typedef struct {
    int HH;
    int MM;
    int SS;
} Jam;
int main(){
    Jam J1, J2,selisih;
    scanf("%d %d %d",&J1.HH,&J1.MM,&J1.SS);
    scanf("%d %d %d",&J2.HH,&J2.MM,&J2.SS);
    selisih.HH = J2.HH-J1.HH;
    selisih.MM = J2.MM-J1.MM;
    selisih.SS = J2.SS-J1.SS;
    printf("%d %d %d\n", selisih.HH,selisih.MM,selisih.SS);
    return 0;
}
    