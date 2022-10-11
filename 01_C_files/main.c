#include <stdio.h>

/*-------------------------------------------------------
 * 1. Open text file
 * 2. While not end of file, read strings, print on screen
 * (fopen, feof, fgets, fclose)
*/
int read_strings_from_file(const char * file_path)
{
    FILE *fp;
    fp = fopen(file_path, "r");
    if(!fp)
    {
        printf("can't open file!\n");
        return -1;
    }
    while(!feof(fp))
    {
        char str[128];
        char * res = fgets(str, sizeof(str), fp);
        if(res)
        {
            printf("%s", str);
        }
    }
    fclose(fp);
    return 0;
}

/*-------------------------------------------------------
 * 1. Open text file
 * 2. While not end of file, read numbers as strings, separated by ','
 *    print on screen
 * (fopen, feof, fscanf, fclose)
 * file example: 1234,-5678,45679,890
*/
int read_numbers_from_file(const char * file_path)
{
    FILE *fp;
    fp = fopen(file_path, "r");
    if(!fp)
    {
        printf("can't open file!\n");
        return -1;
    }
    while(!feof(fp))
    {
        int val;
        fscanf(fp, "%d,", &val); //don't forget delimeter!
                                 //without it we read 1st number in infinite cycle
        printf("%d\n", val);
    }
    fclose(fp);
    return 0;
}

/*---------------------------------------------*/
int main()
{
    read_strings_from_file("C:\\strings.txt");
    read_numbers_from_file("numbers.txt");
}
