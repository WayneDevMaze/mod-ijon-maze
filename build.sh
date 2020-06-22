CC=/home/ubuntu/Study/ijon/afl-clang-fast
rm afl.maze.*
$CC tiny.c -o afl.maze.tiny.bt
$CC -DMAZE_NO_BT tiny.c -o afl.maze.tiny.nobt
$CC small.c -o afl.maze.small.bt
$CC -DMAZE_NO_BT small.c -o afl.maze.small.nobt
$CC big.c -o afl.maze.big.bt
$CC -DMAZE_NO_BT big.c -o afl.maze.big.nobt

rm maze_show
gcc maze_show.c -o maze_show
