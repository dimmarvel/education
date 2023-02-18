#ifndef DIRENT_H_
#define DIRENT_H_
#define NAME_MAX

typedef struct
{
    long ino;                // undex number
    char name[NAME_MAX + 1]; // name + '\0'
} Dirent;

typedef struct
{
    int fd;   // file descriptor of catalog
    Dirent d; // list file
} DIR;

DIR* opendir(char* dirname);
Dirent* readdir(DIR* dfd);
void closedir(DIR* dfd);

#endif /* DIRENT_H_ */
