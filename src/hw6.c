#include "hw6.h"

int main(int argc, char *argv[]) {

    char c;
    char *outfile=NULL;
    char *infile=NULL;

    FILE * toread=NULL;
    FILE * towrite=NULL;
    
    int searchText=0;
    int replaceText=0;
    int l_arguement=0;
    char* initial_argument;
    char* final_argument;
    extern char *optarg;

    char* string_to_be_searched;
    char* string_to_be_replaced;

    bool is_begin_end_given=false;

    long begin;
    long end;

    char* ptr;

    char* temp;

    if(argc<7)
    return MISSING_ARGUMENT;

    bool pre=false;
    bool post=false;

    bool s=false;

    bool w_mentioned=false;
    
        
      while ((c = getopt(argc, argv, "s:r:l:w")) != -1){
		  switch (c) {
		  case 's': 
         
                 if(optarg[0]=='-'||optarg[0]=='\0')
                   return S_ARGUMENT_MISSING;
                  
                  else{
                   if(searchText==0){
                   searchText=1;
                   string_to_be_searched=optarg;
    

                   temp=&string_to_be_searched[strlen(string_to_be_searched)-1];

                   if(*string_to_be_searched=='*')
                   {
                    pre=true;
                    string_to_be_searched=string_to_be_searched+1;
                   }

                   if(*temp=='*')
                   {
                     post=true;
                    *temp='\0';
                   }

                   }

                   else
                   return DUPLICATE_ARGUMENT;
                  }

                   break;
                   
     case 'r': if(optarg[0]=='-'||optarg[0]=='\0')
                   return R_ARGUMENT_MISSING;  


                  else{
                   if(replaceText==0){
                   replaceText=1;
                   string_to_be_replaced=optarg;
                   }

                   else
                   return DUPLICATE_ARGUMENT;
                  }

                   break;

    case 'l': 
                  if(l_arguement==0)
                  l_arguement=1;

                  if(optarg[0]=='-'||optarg[0]=='\0')
                  return L_ARGUMENT_INVALID;

                    else
                    {
                     initial_argument=strtok(optarg,",");
                     final_argument=strtok(NULL,",");

                    if(initial_argument==NULL||final_argument==NULL)
                    return L_ARGUMENT_INVALID;

                    begin=strtol(initial_argument,&ptr,10);
                    end=strtol(final_argument,&ptr,10);

                    if(end<begin || begin==0 || end==0)
                    return L_ARGUMENT_INVALID;
                   }

                   is_begin_end_given=true;
                   break;
            
    case 'w': w_mentioned=true;
             break;

                   
     default: break;        
         }
       }

       infile=argv[argc-2];
        toread = fopen (infile, "r");

        if(toread==NULL)
        return INPUT_FILE_MISSING;

        else
        fclose(toread);

        outfile=argv[argc-1];

        if(*outfile==47)
        return OUTPUT_FILE_UNWRITABLE;

        towrite=fopen(outfile,"w");
        if(towrite==NULL)
        return OUTPUT_FILE_UNWRITABLE;


        else{
        fclose(towrite);
        }

        if(searchText==0)
       return S_ARGUMENT_MISSING;

       if(replaceText==0)
       return R_ARGUMENT_MISSING;

       if(w_mentioned)
       {
         if(post&& pre)
          return WILDCARD_INVALID;

          if(!post && !pre)
          return WILDCARD_INVALID;

       }

       if(!w_mentioned)
       {
 
        char line[200];
        char* line_left;
        long current_line=1;

        int length_of_the_word_to_be_searched=strlen(string_to_be_searched);

         toread =fopen(infile, "r");
         towrite=fopen(outfile,"w");
       

         while (fgets(line, MAX_LINE, toread) != NULL) {
         char* buffer=line;

           

          if(is_begin_end_given && (current_line<begin || current_line>end)){
           fprintf(towrite, "%s", buffer );
          //fputs(buffer,towrite);
          current_line=current_line+1;
          }

          else{
          
         while((line_left=strstr(buffer,string_to_be_searched))!=NULL)
          {

         int num_bytes_to_write = strlen(buffer)-strlen(line_left) ;
          //fwrite(buffer, 1 , num_bytes_to_write, towrite);
          for(int i=0;i<num_bytes_to_write;i++){
          //fprintf(towrite, "%c", buffer[i]);
          fputc(buffer[i], towrite);
          }
         
          for(int i=0;i<length_of_the_word_to_be_searched;i++)
          {
           line_left++;
          }
           //fputs(string_to_be_replaced,towrite);
          fprintf(towrite, "%s", string_to_be_replaced );
         buffer=line_left;
          
        }
         if(buffer!=NULL)
         fprintf(towrite, "%s", buffer);
         //fputs(buffer,towrite);

       
          current_line=current_line+1;
           }
        }

        fclose(toread);
        fclose(towrite);

       }

       else
       {
       
       char sentence[200];
       char* remaining = NULL;
       int total_line=1;

       bool firstWord=false;

       int initial_word_length=0;

         toread =fopen(infile, "r");
         towrite=fopen(outfile,"w");
      
       if(pre)
       {
          while (fgets(sentence, MAX_LINE, toread) != NULL) {
           
          char* current=sentence;
           
          if(is_begin_end_given && (total_line<begin || total_line>end)){
           fprintf(towrite, "%s", current );
          total_line=total_line+1;
          }

         else{


           while((remaining=strstr(current,string_to_be_searched))!=NULL)
           {
            initial_word_length=0;
              if(!isalpha(*(remaining+strlen(string_to_be_searched))))
              {
               char* word=remaining-1;

               while(*word !='\0' && isalpha(*word))
                  {
                  if(word==&sentence[0]){
                    firstWord=true;
                  break;
                  }

                  else{
                  initial_word_length=initial_word_length+1;
                  word=word-1;
                  }
               }

               if(firstWord)
               {
                 fprintf(towrite, "%s", string_to_be_replaced );

                   current=remaining+strlen(string_to_be_searched);
               }

               else
               {
                int num_bytes_to_write = word-current+1;

                 for(int i=0;i<num_bytes_to_write;i++)
                   fprintf(towrite, "%c", *(current + i));

                   fprintf(towrite, "%s", string_to_be_replaced );

                   current=word+initial_word_length+strlen(string_to_be_searched)+1;
                

              
               }
              }  

              else
              {
                int num_bytes_to_write = remaining+strlen(string_to_be_searched)-current;

                  for(int i=0;i<num_bytes_to_write;i++)
                   fprintf(towrite, "%c", current[i]);

                   current=remaining+strlen(string_to_be_searched);

              }



           }
           
           if(current!=NULL)
           fprintf(towrite, "%s", current);


             total_line=total_line+1;  

          }
          }
       }



       else
       {
           
         while (fgets(sentence , MAX_LINE, toread) != NULL) {
         char* current=sentence;

         if(is_begin_end_given && (total_line<begin || total_line>end)){
           fprintf(towrite, "%s", current );
          total_line=total_line+1;
          }

          else{

         while((remaining=strstr(current,string_to_be_searched))!=NULL)
           {
             if(remaining>sentence &&!isalpha(*(remaining-1)))
              {
              char* word=remaining+strlen(string_to_be_searched);

              while(isalpha(*word))
              {
                word=word+1;
              }
             
             int num_bytes_to_write = remaining-current;

              for(int i=0;i<num_bytes_to_write;i++)
                fprintf(towrite, "%c", current[i]);

               fprintf(towrite, "%s", string_to_be_replaced);
            
                current=word;
              }

           if(remaining==sentence)
           {
            char* word=remaining+strlen(string_to_be_searched);

              while(*word != '\0' && isalpha(*word))
              {
                word=word+1;
              }
            fprintf(towrite, "%s", string_to_be_replaced);
            current=word;
           }
            if (remaining>sentence&&isalpha(*(remaining-1)))
            {
              int print_till=remaining+strlen(string_to_be_searched)-current;

              for(int i=0;i<print_till;i++)
                fprintf(towrite, "%c", current[i]);

              current=remaining+strlen(string_to_be_searched);
            }
            
           }


           if(current!=NULL)
           fprintf(towrite, "%s", current);


             total_line=total_line+1;   
          }
         }
       }
        fclose(toread);
        fclose(towrite);
       }
    return 0;
       
}
