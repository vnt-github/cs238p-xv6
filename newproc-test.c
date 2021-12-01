// user-level application to test the "newproc" syscall
#include "types.h"
#include "user.h"
int
main(int argc, char *argv[])
{
    // const char *args[] = {"echo", "NEWPROC_CALL", 0};
    // const char *args[] = {"echo", "NEWPROC_CALL_TEST_FOR_MORE_STRING_LENGTH", "argument2", "argument3" , 0};
    // const char *args[] = {"mkdir", "new_dir", 0};
    // const char *args[] = {"rm", "NON_EXISTENT_DIR", 0};
    // const char *args[] = {"cat", "README", 0};
    // const char *args[] = {"cat", "NON_EXISTENT_FILE", 0};
    // const char *args[] = {"grep", "the", "README", 0};
    // const char *args[] = {"grep", "the", "NON_EXISTENT_FILE", 0};
    const char *args[] = {"ls", 0};
    // const char *args[] = {"ls", "1", 0};

    int ret;
    printf(1, "Test newproc syscall\n");
    ret = newproc(args[0], args);
    printf(1, "returned: %d\n", ret);
    exit();
}