#include <iostream>
#include <dirent.h>
#include <string.h>
bool check=true;
struct dirent *de;
char path[1000];
char d[1000];
void crawl(char path[])
{
    DIR *dr = opendir(path);
    if (dr == NULL)
    {
        printf("Could not open current directory" );
        return;
    }
    printf("%s\n",path);
     strcpy(d,path);
    while ((de = readdir(dr)) != NULL)
    {
        int length=strlen(de->d_name);
            if(de->d_name[length-1]=='3' && de->d_name[length-2]=='p' && de->d_name[length-3]=='m')
                printf("%s\n", de->d_name);
                if(de->d_type==DT_DIR)
                {
                    //D:\Songs\Ed Sheeran\Divide
                    int p=strlen(d);
                    //d[p]=0;
                     //printf("%s %s\n", de->d_name,path);

                    strcat(d,"\\");
                   strcat(d,de->d_name);
                    //printf("%s\n",path);
                    check=false;
                }
}
printf("%s\n",d);
if(check==false)crawl(d);
closedir(dr);
}
int main(void)
{
printf("Enter path of the file \n");
gets(path);
crawl(path);
//crawlFolder(path);
return 0;
}
