char * longestCommonPrefix(char ** strs, int strsSize){
    int i,j;
    char *NOT="";
    if(strsSize==0)
    {
        return NOT;
    }
    else
    {
    for(i=1;i<strsSize;i++)
    {
        for(j=0;j<strlen(strs[0]);j++)
        {
            if(strs[0][j]!=strs[i][j])
            {
                strs[0][j]='\0';
                break;
            }
        }
    }
    }
    return strs[0];
}
