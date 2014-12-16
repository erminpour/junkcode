
/*
*	copy_nocache.c
*	Victor Hugo Erminpour
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define _XOPEN_SOURCE 600
#define PERM 0655

off_t copyFile(char *inFile, char *outFile)
{
  int fd1, fd2, count=0, rc=0;
  long page_size=0;
  char *buffer = NULL;
  off_t total_count = 0;
  struct stat file_stat;

  if((fd1 = open(inFile, O_RDONLY, 0)) == -1)
  {
    fprintf(stderr, "ERROR: Unable to open() %s for reading.\n", inFile);
    return -1;
  }

  if((fd2 = creat(outFile, PERM)) == -1)
  {
    fprintf(stderr, "ERROR: Unable to creat() %s.\n", outFile);
    close(fd1);
    return -1;
  }

  if((fstat(fd1, &file_stat)) == -1)
  {
    fprintf(stderr, "ERROR: fstat() failed on %s.\n", inFile);
    close(fd1);
    close(fd2);
    return -1;
  }

  page_size = sysconf(_SC_PAGESIZE);
  buffer = (char *) malloc(page_size);

  /* 0 == EOF */
  while((count = read(fd1, buffer, page_size)) > 0)
  {
    if(write(fd2, buffer, count) != count)
    {
      fprintf(stderr, "ERROR: write() error on %s.\n", outFile);
      free(buffer);
      close(fd1);
      close(fd2);
      return -1;
    }
    total_count+=count;

    /* ask the kernel to drop the file-cache (pagesize granularity) */
    if((rc = posix_fadvise(fd2, 0, 0, POSIX_FADV_DONTNEED)) != 0)
    {
      /* posix_fadvise() doesn't set errno, but returns an error code. */
      fprintf(stderr, "Error: posix_fadvise() %d\n", rc);
      exit(rc);
    }
  }

  if(total_count != file_stat.st_size)
  {
    fprintf(stderr, "ERROR: write() error on %s.\n", outFile);
    free(buffer);
    close(fd1);
    close(fd2);
    return -1;
  }

  free(buffer);
  close(fd1);
  close(fd2);
return total_count;
}

int main(int argc, char *argv[])
{
  off_t count = 0;

  if (argc != 3)
  {
    fprintf(stderr, "Usage: %s <inputFile> <outputFile>\n", argv[0]);
    exit(1);
  }

  if ((count = copyFile(argv[1], argv[2])) == -1)
  {
    fprintf(stderr, "Unable to Copy Files!\n");
    exit(1);
  }

  fprintf(stdout, "Copied %ld bytes from %s to %s.\n", count, argv[1], argv[2]);
return 0;
}

