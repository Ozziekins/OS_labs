#from line 2, I varied buffer size and exectuted with and without SYNC
gcc copy.c -DBUF_SIZE=16384 -DSYNC -o copy
#the line below is used to vary the file size, by editing count
dd bs=1024 count=10240 if=/dev/urandom of=fileA.txt
time ./copy fileA.txt fileB.txt
rm copy