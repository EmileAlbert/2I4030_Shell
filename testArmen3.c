#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

//int main()
//{
//   // printf() displays the string inside quotation
//   printf("Hello, World!");
//   return 0;
//}


void test1();
char * strreplace(char*,char,char);
char * convertIntToStr(int);

int main(void)
{
    char test[15];
    while(1) {
        printf("\n>");
        scanf("%s", test);
        int ret = strcmp("test", test);

        if (ret == 0) {
            test1();
        }
        else if (ret != 0) {
            break;
        }
    }
}
void test1(){

    // char *b = replace("echo 4",'',"");
    int i = 0;
    char  b = i + '0';
    char chr;
    char repl_chr;
    char s[] = "echo 0 > /sys/class/gpio/export";
    char str[100];

    for(int j=0; j < 26; j++)
    {

	int x = j;
  	char buf[(sizeof(x) * CHAR_BIT) / 3 + 2]; // slightly oversize buffer
  	char *result  = buf + sizeof(buf) - 1; // index of next output digit

  	// add digits to result, starting at 
  	//   the end (least significant digit)

  	*result = '\0'; // terminating null
  	do {
    	*--result = '0' + (x % 10);  // remainder gives the next digit
    	x /= 10;
    	} while (x); // keep going until x reaches zero


	strcpy(str, "echo ");
	printf("%s",result);
	printf("\n%d\n", j);
	strcat(str, result);
	strcat(str, " > /sys/class/gpio/export");
	printf("\n%s", str);
	system(str);
	strcpy(str, "cat ");
	strcat(str, "> /sys/class/gpio");
	strcat(str, result);
	strcat(str, "/value");
	system(str);
    }

//    printf("\nHello, World!");

}

char * convertIntToStr(int x)
{
printf("OK");
  char buf[(sizeof(x) * CHAR_BIT) / 3 + 2]; // slightly oversize buffer
  char *result  = buf + sizeof(buf) - 1; // index of next output digit

  // add digits to result, starting at 
  //   the end (least significant digit)

  *result = '\0'; // terminating null
  do {
    *--result = '0' + (x % 10);  // remainder gives the next digit
    x /= 10;
  } while (x); // keep going until x reaches zero
printf("%s",result);
return result;

}


char * strreplace(char *s,char chr,char repl_chr)
{
   int i=0;
printf("%c",s[i]);
   while(s[i] != '\0')
   {
printf("\n%c",s[i]);
      if(s[i]==chr)
      {
	 printf("%c", s[i]);
         s[i]=repl_chr;
      }
         i++;
   }
   //printf("\n%s",s);
   return s;
}

//void lsh_loop(void);
//int main(int argc, char **argv)
//{
//    // Load config files, if any.
//
//    // Run command loop.
//    lsh_loop();
//
//    // Perform any shutdown/cleanup.
//
//    return EXIT_SUCCESS;
//}
//
//void lsh_loop(void)
//{
//    char *line;
//    char **args;
//    int status;
//
//    do {
//        printf("> ");
//        line = lsh_read_line();
//        args = lsh_split_line(line);
//        status = lsh_execute(args);
//
//        free(line);
//        free(args);
//    } while (status);
//}

//#define LSH_RL_BUFSIZE 1024
//char *lsh_read_line(void)
//{
//    int bufsize = LSH_RL_BUFSIZE;
//    int position = 0;
//    char *buffer = malloc(sizeof(char) * bufsize);
//    int c;
//
//    if (!buffer) {
//        fprintf(stderr, "lsh: allocation error\n");
//        exit(EXIT_FAILURE);
//    }
//
//    while (1) {
//        // Read a character
//        c = getchar();
//
//        // If we hit EOF, replace it with a null character and return.
//        if (c == EOF || c == '\n') {
//            buffer[position] = '\0';
//            return buffer;
//        } else {
//            buffer[position] = c;
//        }
//        position++;
//
//        // If we have exceeded the buffer, reallocate.
//        if (position >= bufsize) {
//            bufsize += LSH_RL_BUFSIZE;
//            buffer = realloc(buffer, bufsize);
//            if (!buffer) {
//                fprintf(stderr, "lsh: allocation error\n");
//                exit(EXIT_FAILURE);
//            }
//        }
//    }
//}
//
//char *lsh_read_line(void)
//{
//    char *line = NULL;
//    ssize_t bufsize = 0; // have getline allocate a buffer for us
//    getline(&line, &bufsize, stdin);
//    return line;
//}
//
//#define LSH_TOK_BUFSIZE 64
//#define LSH_TOK_DELIM " \t\r\n\a"
//char **lsh_split_line(char *line)
//{
//    int bufsize = LSH_TOK_BUFSIZE, position = 0;
//    char **tokens = malloc(bufsize * sizeof(char*));
//    char *token;
//
//    if (!tokens) {
//        fprintf(stderr, "lsh: allocation error\n");
//        exit(EXIT_FAILURE);
//    }
//
//    token = strtok(line, LSH_TOK_DELIM);
//    while (token != NULL) {
//        tokens[position] = token;
//        position++;
//
//        if (position >= bufsize) {
//            bufsize += LSH_TOK_BUFSIZE;
//            tokens = realloc(tokens, bufsize * sizeof(char*));
//            if (!tokens) {
//                fprintf(stderr, "lsh: allocation error\n");
//                exit(EXIT_FAILURE);
//            }
//        }
//
//        token = strtok(NULL, LSH_TOK_DELIM);
//    }
//    tokens[position] = NULL;
//    return tokens;
//}
//
//int lsh_launch(char **args)
//{
//    pid_t pid, wpid;
//    int status;
//
//    pid = fork();
//    if (pid == 0) {
//        // Child process
//        if (execvp(args[0], args) == -1) {
//            perror("lsh");
//        }
//        exit(EXIT_FAILURE);
//    } else if (pid < 0) {
//        // Error forking
//        perror("lsh");
//    } else {
//        // Parent process
//        do {
//            wpid = waitpid(pid, &status, WUNTRACED);
//        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
//    }
//
//    return 1;
//}
//
///*
//  Function Declarations for builtin shell commands:
// */
//int lsh_cd(char **args);
//int lsh_help(char **args);
//int lsh_exit(char **args);
//
///*
//  List of builtin commands, followed by their corresponding functions.
// */
//char *builtin_str[] = {
//        "cd",
//        "help",
//        "exit"
//};
//
//int (*builtin_func[]) (char **) = {
//        &lsh_cd,
//        &lsh_help,
//        &lsh_exit
//};
//
//int lsh_num_builtins() {
//    return sizeof(builtin_str) / sizeof(char *);
//}
//
///*
//  Builtin function implementations.
//*/
//int lsh_cd(char **args)
//{
//    if (args[1] == NULL) {
//        fprintf(stderr, "lsh: expected argument to \"cd\"\n");
//    } else {
//        if (chdir(args[1]) != 0) {
//            perror("lsh");
//        }
//    }
//    return 1;
//}
//
//int lsh_help(char **args)
//{
//    int i;
//    printf("Stephen Brennan's LSH\n");
//    printf("Type program names and arguments, and hit enter.\n");
//    printf("The following are built in:\n");
//
//    for (i = 0; i < lsh_num_builtins(); i++) {
//        printf("  %s\n", builtin_str[i]);
//    }
//
//    printf("Use the man command for information on other programs.\n");
//    return 1;
//}
//
//int lsh_exit(char **args)
//{
//    return 0;
//}
//
//int lsh_execute(char **args)
//{
//    int i;
//
//    if (args[0] == NULL) {
//        // An empty command was entered.
//        return 1;
//    }
//
//    for (i = 0; i < lsh_num_builtins(); i++) {
//        if (strcmp(args[0], builtin_str[i]) == 0) {
//            return (*builtin_func[i])(args);
//        }
//    }
//
//    return lsh_launch(args);
//}
//