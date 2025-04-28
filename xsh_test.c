#include <file.h>
#include <disk.h>

command xsh_test(int nargs, char *args[])
{
    printf("=== Starting file system test ===\n");

    int fd = fileCreate("testfile");
    if (fd == SYSERR) {
        printf("[ERROR] Failed to create testfile.\n");
        return SYSERR;
    }
    printf("[OK] Created file 'testfile' with fd=%d.\n", fd);

    fileClose(fd);

    if (fileDelete(fd) == OK) {
        printf("[OK] fileDelete(fd=%d) succeeded.\n", fd);
    } else {
        printf("[ERROR] fileDelete(fd=%d) failed.\n", fd);
    }

    int test_block = 10;
    if (sbFreeBlock(&supertab[0], test_block) == OK) {
        printf("[OK] sbFreeBlock(block=%d) succeeded.\n", test_block);
    } else {
        printf("[ERROR] sbFreeBlock(block=%d) failed.\n", test_block);
    }

    printf("=== File system test complete ===\n");

    return OK;
}
