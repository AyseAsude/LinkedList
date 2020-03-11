#include "mylinkedlist.h"


int main(int argc, char const *argv[]) {


    addFirst("ayşe", 1, 2.0, 17000);
    printForward();
    addLast("tuğrul",1,3.4,9000);
    printForward();
    if(argc == 0){
      printf("%s\n", "Please type the file name");
      return -1;
    }

    char s_flag = '0';
    char v_flag = '0';
    char r_flag = '0';
    char n_flag = '0';
    char p_flag = '0';
    char after_target = '0';
    char * flags = (char *)malloc(2 * sizeof(char));
    char * target_name = (char *)malloc(15 * sizeof(char));

    for(int i = 0; i < argc ; i++){

        //get -s or -v arguments
        if(strchr(argv[i],'-') != NULL && after_target == '0'){

            //checks if the arguments are in correct form
            if((strrchr(argv[i], 's') != strchr(argv[i],'s'))
                        || (strrchr(argv[i], 'v') != strchr(argv[i],'v') )){
                printf("%s\n", "Invalid arguments");
                return -1;
            }
            if(strchr(argv[i],'s') == NULL && strchr(argv[i],'v') == NULL){
              printf("%s\n", "Invalid arguments");
              return -1;
            }

            if(strchr(argv[i],'s') != NULL){
              s_flag = '1';
            }
            if(strchr(argv[i],'v') != NULL){
              v_flag = '1';
            }

        }

        //get target name
        if(strchr(argv[i],'-') == NULL && strstr(argv[i],".txt") == NULL && strchr(argv[i],'.') == NULL){
            if(i == 1){
              printf("%s\n", "Invalid arguments");
              return -1;
            }
            strcpy(target_name,argv[i]);
            after_target = '1';
            continue;
        }

        // gets -r -n -p arguments
        if(after_target == '1'  && strstr(argv[i],".txt") == NULL){
          //printf("%s\n", argv[i]);
          if(strchr(argv[i],'-') != NULL ){

            if(strchr(argv[i],'r') != NULL){
              r_flag = '1';
            }
            if(strchr(argv[i],'n') != NULL){
              n_flag = '1';
            }
            if(strchr(argv[i],'p') != NULL){
              p_flag = '1';
            }
          }
        }

        //get file name
        if(strstr(argv[i],".txt") != NULL && strchr(argv[i],'-') == NULL){
          if(strchr(argv[i-1],'-') == NULL){
            r_flag = '1';
            n_flag = '1';
            p_flag = '1';
          }
          //printf("%c %c %c", r_flag,n_flag, p_flag);
          if(s_flag == '1'){
            readFile(argv[i],1,target_name,r_flag,n_flag, p_flag);
          }else if(v_flag == '1'){
            readFile(argv[i],0,target_name,r_flag,n_flag, p_flag);
          }
        }


    }


    free(flags);
    free(target_name);


    return 0;
  }
