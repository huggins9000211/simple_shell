# hsh shell


## Discription

hsh is a simple shell used to run executable files from your path.
While in interactive mode if a command is not found an error message will be printed.
you can exit the shell with the command exit.

## Usage
hsh can be used in interactive mode:
```bash
./hsh
```
```bash
$ ls -a
.  ..  hsh  test  test_ls_ls-la
$ cat test
This is a example
$ exit
gins@gins-trusty:~/shell2$
```
Or in non interactive mode:
```bash
gins@gins-trusty:~/shell_test$ cat test_ls_ls-la
/bin/ls
/bin/ls -la
gins@gins-trusty:~/shell_test$ cat test_ls_ls-la | ./hsh
hsh  test  test_ls_ls-la
total 32
drwxrwxr-x  2 gins gins  4096 Aug 28 19:15 .
drwxr-xr-x 36 gins gins  4096 Aug 28 19:13 ..
-rwxrwxr-x  1 gins gins 13891 Aug 28 19:14 hsh
-rw-rw-r--  1 gins gins    19 Aug 28 19:14 test
-rw-rw-r--  1 gins gins    21 Aug 28 19:15 test_ls_ls-la
gins@gins-trusty:~/shell_test$
```


## Authors
Anthony Huggins
