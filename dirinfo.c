#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>

int main(){
  struct stat sb;

  printf("\nStatistics for the current directory:\n");

  stat(".", &sb);

  printf("Total Directory size: %lld bytes\n\n", sb.st_size);

  printf("Listing Directories within current directory:\n");
  DIR * d;
  d = opendir(".");
  struct dirent * entry;
  entry = readdir(d);

  struct stat filee;

  if(d){
    while(entry){
      if(entry->d_type == DT_DIR){
        printf("%s ", entry->d_name);
        printf("File size: %hu bytes\n", entry->d_reclen);
      }
      entry = readdir(d);
    }
    closedir(d);
  }

  printf("\n");

  printf("Listing Files within current directory:\n");
  d = opendir(".");
  entry = readdir(d);

  if(d){
    while(entry){
      if(entry->d_type == DT_REG){
        printf("%s ", entry->d_name);
        printf("File size: %hu bytes\n", entry->d_reclen);
      }
      entry = readdir(d);
    }
    closedir(d);
  }

  printf("\n");

  return 0;
}
