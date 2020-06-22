AFL_BENCH_UNTIL_CRASH=1 afl-fuzz -m none -t 250 -i in -o workdir_afl_$1 -- ./afl.$1
