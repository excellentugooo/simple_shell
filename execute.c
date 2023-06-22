 86             value = fork();
 87 
 88                     if (value == -1)
 89                             exit(EXIT_FAILURE);
 90                     else if (value == 0)
 91                     {
 92                             execve(path, av, env);
 93 
 94                         perror("Error");
 95                             exit(EXIT_FAILURE);
 96                     }
 97                     else
 98                     {
 99                             wait(NULL);
100                             put_char('$');
101                 put_char(' ');
                     }
