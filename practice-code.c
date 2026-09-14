#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void CountCharacter(char *sentence)
{
    char str[100];
    strcpy(str, sentence);
    int freq[128] = {0};
    int seen[128] = {0};
    //printf("run CountCharacter\n");
        for(int i = 0; str[i] != '\0'; i++)
    {
        char ch = tolower(str[i]);
        freq[ch]++;
    }
    for(int i = 0; str[i] != '\0'; i++)
    {
        char ch = tolower(str[i]);
        if (!seen[(char)ch])
        {seen[(char)ch] = 1;
        
        printf("%c is %d\n", ch, freq[ch]);}
    }
}

void findWord(char *sentence)
{
    char str[100];
    strcpy(str, sentence);
    char word[100];
    int countword = 0 ;
    printf("Enter the word to search for: ");
    scanf("%s", &word);
    //printf("%s\n", word);
    
    char *token = strtok(str, " .,?!");
    //printf("token: %s \n", token);
    while(token != NULL)
    {
        //printf("while\n");
        if(strcasecmp(token, word) == 0)
        {
            //printf("if\n");
            countword++;
            
        }
        token = strtok(NULL, " .,?!");
    }
    
    printf("The word '%s' appears %d times.\n", word, countword);
}

void TitleCase(char *sentence)
{
    char str[100];
    strcpy(str, sentence);
    for(int i = 0; sentence[i] != '\0'; i++)
    {
        if(i == 0 || isspace(str[i-1]))
        {
            str[i] = toupper(str[i]);
        }
        else
        {
            str[i] = tolower(str[i]);
        }
    }
    printf("Title Case: %s", str);
}

void ExtractSubstring(char *sentence)
{
    char str[100];
    strcpy(str, sentence);
    int start_pos;
    int length;
   
    
    printf("Enter the starting position (index): ");
    scanf("%d", &start_pos);
    printf("Enter the length of the substring: ");
    scanf("%d", &length);
    
    char *result [length + 1];
    memcpy(result, str+start_pos, length);
    result[length] = '\0';
    printf("Extracted substring: %s",result);
}

void SingleSpace(char *sentence)
{
    char str[100];
    strcpy(str, sentence);
    char final[strlen(sentence) + 1];
    int j = 0;
    int space = 0;
    for(int i = 0;str[i] != '\0'; i++)
    {
        if (isspace(str[i]))
        {
            if (!space)       
            {
                final[j++] = str[i];
            }
            space = 1;
        }
        else
        {
            final[j++] = str[i];
            space = 0;
        }
    }
    final[j] = '\0';
    printf("Original string: %s \n", str);
    printf("String after replacing multiple spaces: %s", final);
}

int main()
{
    char sentence[500];
    int choice;
    
    printf("Enter a text: ");
    scanf("%[^\n]", sentence);

    printf("Choose an operation to perform on the text: \n 1. Count character occurrences \n 2. Find word frequency \n 3. Convert to title case \n 4. Extract a substring \n 5. Replace multiple spaces with a single space \n 6. Exit \n");
    
    do{
        
    //printf(" \n");
    printf("\n \nEnter your choice: ");
    scanf(" %d", &choice);

    //printf("You entered choice: %d\n", choice);
    
    switch(choice)
        {
            case 1:
                //printf("original sentence %s \n", sentence);
                CountCharacter(sentence);
                break;
            case 2:
                //printf("original sentence %s \n", sentence);
                findWord(sentence);
                break;
            case 3:
                //printf("original sentence %s \n", sentence);
                TitleCase(sentence);
                break;
            case 4:
                //printf("original sentence %s \n", sentence);
                ExtractSubstring(sentence);
                break;
            case 5:
                //printf("original sentence %s \n", sentence);
                SingleSpace(sentence);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Choice not implemented yet.\n");
        }
} while (choice < 6);
    return 0;
}
