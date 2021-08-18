echo "test 100"
./push_swap `echo $ARG` | wc -l 
echo " "
ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
echo $ARG
./push_swap `echo $ARG` | wc -l 
echo " "
ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
echo $ARG
./push_swap `echo $ARG` | wc -l 
echo " "
ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
echo $ARG
./push_swap `echo $ARG` | wc -l 
echo " "
ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
echo $ARG
./push_swap `echo $ARG` | wc -l 
echo " "
ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
echo $ARG
./push_swap `echo $ARG` | wc -l 
echo " "
