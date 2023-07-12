#include "ft_printf.h"
#include <stdio.h>
int main() {
    printf("========================= ORIGINAL ========================\n");
    printf("Returned: %d\n", printf("%p", ""));
    printf("======================== FOURTY TWO ========================\n");
    printf("Returned: %d\n", ft_printf("%p", ""));
}