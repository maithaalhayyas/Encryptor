#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <inttypes.h>

#include "../prod.h"

 uint8_t encrypt(uint8_t plaintext,uint8_t key){
    return (plaintext ^ key);
}


static void simplest_OTP(void **state){

    uint8_t plaintext =1;
    uint8_t key =1;
    assert_int_equal(0, encrypt(plaintext, key));


}
/* A test case that does nothing and succeeds. */
static void canary_test(void **state) {
    (void) state; /* unused */
    assert_int_equal(0, 0);
}
int main(void) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(canary_test),
            cmocka_unit_test(simplest_OTP)

    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
