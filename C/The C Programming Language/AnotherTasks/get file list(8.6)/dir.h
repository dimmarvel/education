#ifndef DIR_H_
#define DIR_H_

#ifndef DIRSZ
#define DIRSIZ 14
#endif

struct direct
{
    ino_t d_ino;         // index number
    char d_name[DIRSIZ]; // in long name no '\0'
};

#endif /* DIR_H_ */
