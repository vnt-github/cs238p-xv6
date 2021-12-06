// user-level application to test the "newproc" syscall
#include "types.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
    // const char *args[] = {"echo", "NEWPROC_CALL", 0};
    // const char *args[] = {"echo", "NEWPROC_CALL_TEST_FOR_MORE_STRING_LENGTH", "argument2", "argument3" , 0};
    // const char *args[] = {"mkdir", "new_dir", 0};
    // const char *args[] = {"cat", "README", 0};
    // const char *args[] = {"grep", "the", "README", 0};
    // const char *args[] = {"ls", 0};
    
    // NOTE: this should give error -2. because the exec fails and it's not because of arguments. it's because ll command does not exists.
    // const char *args[] = {"ll", 0};

    // NOTE: in below commands the arguments are checked by the command that is executed later by the new process so incorrent arguments in this should not give error.
    // const char *args[] = {"grep", "the", "NON_EXISTENT_FILE", 0};
    // const char *args[] = {"ls", "1", 0};
    // const char *args[] = {"cat", "NON_EXISTENT_FILE", 0};
    // const char *args[] = {"rm", "NON_EXISTENT_DIR", 0};
    
    int in = -1;
    int out = -1;

    // NOTE: below are for file redirections
    // const char *args[] = {"cat", 0};
    const char *args[] = {"wc", 0};
    in = open("README", O_CREATE|O_RDONLY);
    if(in < 0){
        printf(1, "error: open redirection input file creation failed!\n");
        exit();
    }
    out = open("out.txt", O_CREATE|O_RDWR);
    if(out < 0){
        printf(1, "error: open redirection output file creation failed!\n");
        exit();
    }

    // NOTE: below setting in = 16 should return -1 as it's the incorrect argument to newproc as it's greater than or equal NOFILE
    // in = 18;
    int ret;

    printf(1, "Test newproc syscall\n");
    ret = newproc(args[0], args, in, out);
    int wpid;
    while((wpid=wait()) >= 0 && wpid != ret);
    printf(1, "returned: %d\n", ret);
    exit();
}