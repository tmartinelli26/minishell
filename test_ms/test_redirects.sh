#! minishell

grep hi <./test_files/infile
grep hi "<infile" <         ./test_files/infile
echo hi < ./test_files/infile bye bye
grep hi <./test_files/infile_big <./test_files/infile
echo <"./test_files/infile" "bonjour       42"
cat <"./test_files/file name with spaces"
cat <./test_files/infile_big ./test_files/infile
cat <"1""2""3""4""5"
echo <"./test_files/infile" <missing <"./test_files/infile"
echo <missing <"./test_files/infile" <missing
cat <"./test_files/infile"
echo <"./test_files/infile_big" | cat <"./test_files/infile"
echo <"./test_files/infile_big" | cat "./test_files/infile"
echo <"./test_files/infile_big" | echo <"./test_files/infile"
echo hi | cat <"./test_files/infile"
echo hi | cat "./test_files/infile"
cat <"./test_files/infile" | echo hi
cat <"./test_files/infile" | grep hello
cat <"./test_files/infile_big" | echo hi
cat <missing
cat <missing | cat
cat <missing | echo oi
cat <missing | cat <"./test_files/infile"
echo <123 <456 hi | echo 42
ls >./outfiles/outfile01
ls >         ./outfiles/outfile01
echo hi >         ./outfiles/outfile01 bye
ls >./outfiles/outfile01 >./outfiles/outfile02
ls >./outfiles/outfile01 >./test_files/invalid_permission
ls >"./outfiles/outfile with spaces"
ls >"./outfiles/outfile""1""2""3""4""5"
ls >"./outfiles/outfile01" >./test_files/invalid_permission >"./outfiles/outfile02"
ls >./test_files/invalid_permission >"./outfiles/outfile01" >./test_files/invalid_permission
cat <"./test_files/infile" >"./outfiles/outfile01"
echo hi >./outfiles/outfile01 | echo bye
echo hi >./outfiles/outfile01 >./outfiles/outfile02 | echo bye
echo hi | echo >./outfiles/outfile01 bye
echo hi | echo bye >./outfiles/outfile01 >./outfiles/outfile02
echo hi >./outfiles/outfile01 | echo bye >./outfiles/outfile02
echo hi >./outfiles/outfile01 >./test_files/invalid_permission | echo bye
echo hi >./test_files/invalid_permission | echo bye
echo hi >./test_files/invalid_permission >./outfiles/outfile01 | echo bye
echo hi | echo bye >./test_files/invalid_permission
echo hi | >./outfiles/outfile01 echo bye >./test_files/invalid_permission
echo hi | echo bye >./test_files/invalid_permission >./outfiles/outfile01
cat <"./test_files/infile" >./test_files/invalid_permission
cat >./test_files/invalid_permission <"./test_files/infile"
cat <missing >./outfiles/outfile01
cat >./outfiles/outfile01 <missing
cat <missing >./test_files/invalid_permission
cat >./test_files/invalid_permission <missing
cat >./outfiles/outfile01 <missing >./test_files/invalid_permission
ls >>./outfiles/outfile01
ls >>      ./outfiles/outfile01
ls >>./outfiles/outfile01 >./outfiles/outfile01
ls >./outfiles/outfile01 >>./outfiles/outfile01
ls >./outfiles/outfile01 >>./outfiles/outfile01 >./outfiles/outfile02
ls >>./outfiles/outfile01 >>./outfiles/outfile02
ls >>./test_files/invalid_permission
ls >>./test_files/invalid_permission >>./outfiles/outfile01
ls >>./outfiles/outfile01 >>./test_files/invalid_permission
ls >./outfiles/outfile01 >>./test_files/invalid_permission >>./outfiles/outfile02
ls <missing >>./test_files/invalid_permission >>./outfiles/outfile02
ls >>./test_files/invalid_permission >>./outfiles/outfile02 <missing
echo hi >>./outfiles/outfile01 | echo bye
echo hi >>./outfiles/outfile01 >>./outfiles/outfile02 | echo bye
echo hi | echo >>./outfiles/outfile01 bye
echo hi | echo bye >>./outfiles/outfile01 >>./outfiles/outfile02
echo hi >>./outfiles/outfile01 | echo bye >>./outfiles/outfile02
echo hi >>./test_files/invalid_permission | echo bye
echo hi >>./test_files/invalid_permission >./outfiles/outfile01 | echo bye
echo hi | echo bye >>./test_files/invalid_permission
echo hi | echo >>./outfiles/outfile01 bye >./test_files/invalid_permission
cat <minishell.h>./outfiles/outfile
cat <minishell.h|ls