#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h> 

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void) {
  int letters = 0;
  int words = 0; 
  int sentences = 0;
  float l = 0;
  float s = 0;
  string text; 

  text = get_string("Text: ");
  
  letters = count_letters(text);
  words = count_words(text);
  sentences = count_sentences(text);

  l = (float) letters / words * 100;
  s = (float) sentences / words * 100;

  int index = (0.0588 * l - 0.296 * s - 15.8) + 0.5;

  if(index >= 16)
  {
    printf("Grade 16+\n");
    return 0;
  }
  if(index <= 1)
  {
    printf("Before Grade 1\n");
    return 0;
  }
  else
  {
    printf("Grade %i", index);
    return 0;
  }
  return 0;
}

int count_sentences(string text)
{
  int length = strlen(text);
  int count = 0;

  for(int i = 0; i < length; i++)
    {
      if(text[i] == '.' || text[i] == '!' || text[i] == '?')
      {
        count++;
      }
    }
  return count;
}

int count_words(string text)
{
  int length = strlen(text);
  int count = 1;

  for(int i = 0; i < length; i++)
    {
      if(isspace(text[i]))
      {
        count++;
      }
    }
  return count;
}

int count_letters(string text)
{
  int length = strlen(text);
  int count = 0;

  for(int i = 0; i < length; i++)
    {
      if(ispunct(text[i]) || isspace(text[i]))
      {
        count = count; 
      }
      else
      {
        count++;
      }
    }
  return count;
}
