i=1
echo Enter the limit[N]
read N
while [ $i -le $N ]
do
i=$(expr $i + 1)
sum=$(($sum+ $i))
done
echo Sum=$sum       
