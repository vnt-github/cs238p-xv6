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
    // const char *args[] = {"rm", "NON_EXISTENT_DIR", 0};
    // const char *args[] = {"cat", "README", 0};
    // const char *args[] = {"cat", "NON_EXISTENT_FILE", 0};
    // const char *args[] = {"grep", "the", "README", 0};
    // const char *args[] = {"grep", "the", "NON_EXISTENT_FILE", 0};
    const char *args[] = {"ls", 0};
    // const char *args[] = {"ls", "1", 0};

    
    int in = -1;
    int out = -1;

    // NOTE: below are for file redirections
    // const char *args[] = {"cat", 0};
    // const char *args[] = {"wc", 0};
    // in = open("in.txt", O_CREATE|O_RDONLY);
    // if(in < 0){
    //     printf(1, "error: open redirection input file creation failed!\n");
    //     exit();
    // }
    // out = open("out.txt", O_CREATE|O_RDWR);
    // if(out < 0){
    //     printf(1, "error: open redirection output file creation failed!\n");
    //     exit();
    // }


    int ret;
    printf(1, "Test newproc syscall\n");
    ret = newproc(args[0], args, in, out);
    printf(1, "returned: %d\n", ret);
    exit();
}